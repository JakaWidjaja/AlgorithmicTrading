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

GenerateSignals::GenerateSignals(const shared_ptr<Config>& config, 
								 const shared_ptr<HurstExponent>& hurst, 
								 const shared_ptr<VarianceRatio>& vr, 
								 const shared_ptr<HalfLife>& hl, 
								 const shared_ptr<SingleSMA>& singleSMA, 
								 const shared_ptr<SavitzkyGolay>& smoother, 
								 const vector<portfolioRow> portfolios, 
								 double investAmt) :
hurstExp(hurst), vRatio(vr), hlife(hl), sma(singleSMA), smoother(smoother), portfolios(portfolios), investAmt(investAmt)
{
	ou         = make_shared<MethodOfMoment>();
	meanRevert = make_shared<MeanRevertingSignal>(config); 
	trend      = make_shared<TrendSignal>(config);
}

pair<Eigen::MatrixXd, Eigen::MatrixXd> GenerateSignals::signals(const Eigen::MatrixXd& data)
{
	for(const auto& p : portfolios)
	{
		const vector<string>& stockNames = p.stockNames;
		const vector<double>& weights    = p.weights;

		int rows = data.rows();
		Eigen::MatrixXd portfolioData(rows, stockNames.size());
		for(size_t j = 0; j < stockNames.size(); ++j)
		{	
			bool found = false;
            for (int k = 0; k < portfolios[0].stockNames.size(); ++k)
            {
                if (stockNames[j] == portfolios[0].stockNames[k]) // assumes portfolios[0].stockNames is full stock list in order
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

		Eigen::VectorXd prices = portfolioData.row(portfolioData.row() - 1);
		Eigen::VectorXd allocation = Eigen::Map<const Eigen::VectorXd>(weights.data(), weights.size()) * investAmt;
		Eigen::VectorXd numShares(stockNames.size());
		for(int i = 0; i < prices.size(); ++i)
		{
			numShared(i) = (prices(i) != 0.0) ? trunc(allocation(i) / prices(i)) : 0.0;
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
            meanRevertStrategy.conservativeResize(meanRevertStrategy.rows() + meanResult.rows(), Eigen::NoChange);
            meanRevertStrategy.bottomRows(meanResult.rows()) = meanResult;
        }

        // Trend
        Eigen::MatrixXd trendResult = trending -> signal(hurstExp -> getValue(), 
        												 vRatio   -> getValue(),
        												 hlife    -> getValue(), 
        												 *sma, 
        												 lastPrice, 
        												 stockNames, 
        												 portfolioData);

        if(trendResult.size() > 0)
        {
        	trendStrategy.conservativeResize(trendStrategy.rows() + trendResult.rows(), Eigen::NoChange);
        	trendStrategy.bottomRows(trendResult.rows()) = trendResult;
        }

        return {meanRevertStrategy, trendStrategy}
	}
}