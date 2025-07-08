#include "GenerateSignals.h"
#include <numeric>
#include <cmath>
#include <iostream>

using std::string;
using std::vector;
using std::map;
using std::shared_ptr;
using std::make_shared;
using std::pair;
using std::trunc;

GenerateSignals::GenerateSignals(const shared_ptr<ConfigModel>& modelConfig, 
								 const shared_ptr<HurstExponent>& hurst, 
								 const shared_ptr<VarianceRatio>& vr, 
								 const shared_ptr<HalfLife>& hl, 
								 const shared_ptr<SingleSMA>& singleSMA, 
								 const shared_ptr<SavitzkyGolay>& smoother, 
								 const vector<portfolioRow>& portfolios, 
								 double investAmt) :
hurstExp(hurst), vRatio(vr), hlife(hl), sma(singleSMA), smoother(smoother), portfolios(portfolios), investAmt(investAmt)
{
	ou         = make_shared<MethodOfMoment>();
	meanRevert = make_shared<MeanRevertSignal>(modelConfig); 
	trend      = make_shared<TrendSignal>(modelConfig);
	doubleSMAShort = modelConfig -> getDoubleSMAShortWindow();
	doubleSMALong  = modelConfig -> getDoubleSMALongWindow();
}

pair<Eigen::MatrixXd, Eigen::MatrixXd> GenerateSignals::signals(const Eigen::MatrixXd& data)
{
	for(const auto& p : portfolios)
	{
		const vector<string>& stockNames = p.combination;
		const vector<double>& weights    = p.weights;

		int rows = data.rows();
		Eigen::MatrixXd portfolioData(rows, stockNames.size());
		for(size_t j = 0; j < stockNames.size(); ++j)
		{	
			bool found = false;
            for (int k = 0; k < portfolios[0].combination.size(); ++k)
            {
                if (stockNames[j] == portfolios[0].combination[k]) // assumes portfolios[0].stockNames is full stock list in order
                {
                    portfolioData.col(j) = data.col(k);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                std::cerr << "[Warning] stock " << stockNames[j] << " not found in data column headers." << std::endl;
                portfolioData.col(j).setZero();
            }
		}

		Eigen::VectorXd prices = portfolioData.row(portfolioData.rows() - 1);
		Eigen::VectorXd allocation = Eigen::Map<const Eigen::VectorXd>(weights.data(), weights.size()) * investAmt;
		Eigen::VectorXd numShares(stockNames.size());
		for(int i = 0; i < prices.size(); ++i)
		{
			numShares(i) = (prices(i) != 0.0) ? trunc(allocation(i) / prices(i)) : 0.0;
		}

		Eigen::VectorXd total = portfolioData * numShares;
		vector<double> totalVec(total.data(), total.data() + total.size());

		smoother -> compute(totalVec);
		vector<double> smoothed = smoother -> getValue();

		hurstExp -> compute(smoothed);
		vRatio   -> compute(smoothed);
		hlife    -> compute(smoothed);
		sma -> compute(smoothed);
		auto [mu, theta, sigma] = ou -> calibrate(smoothed);

		double lastPrice = total(total.size() - 1);

		// Mean Reverting
		Eigen::MatrixXd meanResult = meanRevert -> signal(hurstExp -> getValue(),
														  hlife    -> getValue(),
														  *sma,
														  mu, sigma, lastPrice,
														  stockNames,
														  portfolioData);

		if (meanResult.size() > 0)
        {
            int oldRows = meanRevertStrategy.rows();
			int newRows = oldRows + meanResult.rows();
			int cols = meanResult.cols();

			if (meanRevertStrategy.cols() == 0)
			{
				meanRevertStrategy.resize(0, cols);  // initialize columns if empty
			}

			meanRevertStrategy.conservativeResize(newRows, Eigen::NoChange);
			meanRevertStrategy.block(oldRows, 0, meanResult.rows(), cols) = meanResult;
        }

        // Trend
        int shortWindow = doubleSMAShort;
        int longWindow = doubleSMALong;
        DoubleSMA doubleSMA(shortWindow, longWindow);
        doubleSMA.compute(smoothed);

        Eigen::MatrixXd trendResult = trend -> signal(hurstExp -> getValue(), 
        												 vRatio   -> getValue(),
        												 hlife    -> getValue(), 
        												 doubleSMA, 
        												 lastPrice, 
        												 stockNames, 
        												 portfolioData);

        if(trendResult.size() > 0)
        {
        	int oldRows = trendStrategy.rows();
			int newRows = oldRows + trendResult.rows();
			int cols = trendResult.cols();

			if (trendStrategy.cols() == 0)
			{
				trendStrategy.resize(0, cols);  // initialize columns if empty
			}

			trendStrategy.conservativeResize(newRows, Eigen::NoChange);
			trendStrategy.block(oldRows, 0, trendResult.rows(), cols) = trendResult;
        }
	}
	return {meanRevertStrategy, trendStrategy};
}