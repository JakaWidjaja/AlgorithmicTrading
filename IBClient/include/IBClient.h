#ifndef IB_CLIENT_H
#define IB_CLIENT_H

#include "EWrapper.h"
#include "EClientSocket.h"
#include "Contract.h"
#include "HistoricalData.h"
#include "IBClientCore.h"
#include "MarketData.h"
#include "OrderManager.h"

#include <memory>
#include <thread>
#include <set>
#include <string>
#include <vector>
#include <tuple>

class IBClient : public IBClientCore
{
public:
	IBClient();
	~IBClient();

	// Market data
	void requestMarketDataType(int type);
	void requestMarketData(int tickerId,
						   const std::string& symbol,
						   const std::string& secType, 
						   const std::string& exchange, 
						   const std::string& currency);
	double getMarketValue(int tickerId, TickType field) const;

	// Historical data
	void requestHistoricalData(int reqId, const Contract& contract,
										  const std::string& endDateTime, 
										  const std::string& durationStr, 
										  const std::string& barSizeSetting, 
										  const std::string& whatToShow, int useRTH, int formatDate);
	const std::vector<Bar>& getHistoricalData(int reqId) const;
	void exportHistoricalDataToCSV(int reqId, const std::string& filename) const;

	// Order manager
	void placeMarketOrder(const Contract& contract, double quantity, const std::string& direction);
	void placeLimitOrder(const Contract& contract, double quantity, const std::string& direction, double limitPrice);
	void placeStopOrder(const Contract& contract, double quantity, const std::string& direction, double stopPrice);
	void placeStopLimitOrder(const Contract& contract, double quantity, const std::string& direction, double stopPrice, double limitPrice);
	void placeTrailingStopOrder(const Contract& contract, double quantity, const std::string& direction, double trailingAmount);
	void placeTrailingStopLimitOrder(const Contract& contract, double quantity, const std::string& direction, double trailingAmount, double limitOffset);
	void placeMarketOnCloseOrder(const Contract& contract, double quantity, const std::string& direction);
	void placeLimitOnCloseOrder(const Contract& contract, double quantity, const std::string& direction, double limitPrice);
	void placePeggedToMarketOrder(const Contract& contract, double quantity, const std::string& direction, double offset);
	void placePeggedToMidpointOrder(const Contract& contract, double quantity, const std::string& direction, double offset);
	void placeRelativeOrder(const Contract& contract, double quantity, const std::string& direction, double offset);
	void placeOcaGroupOrders(const std::vector<std::tuple<Contract, double, std::string, std::string, double>>& orders, const std::string& ocaGroup);
	void placeBracketOrder(const Contract& contract, double quantity, double entryPrice, double takeProfitPrice, double stopLossPrice, const std::string& direction);
	void placeTimeBasedOrder(const Contract& contract, double quantity, const std::string& direction, const std::string& orderType, double price, const std::string& goodAfterTime = "", const std::string& goodTillDate = "");
	void cancelOrder(int orderId);
	void cancelAllOrders();


	// Used Ewrapper
	void historicalData(TickerId reqId, const Bar& bar) override;
	void historicalDataEnd(int reqId, const std::string& start, const std::string& end) override;

	void tickPrice(TickerId tickerId, TickType field, double price, const TickAttrib& attrib) override;
	void tickSize(TickerId tickerId, TickType field, Decimal size) override;
	void error(int id, time_t time, int errorCode, const std::string& errorString, const std::string& advancedOrderRejectJson) override;
	void nextValidId(OrderId orderId) override;
	void requestNextValidId(){getClientSocket()->reqIds(1);}
	void orderStatus(OrderId, const std::string&, Decimal, Decimal, double, long long, int, double, int, const std::string&, double) override;

	// EWrapper overrides
	void tickOptionComputation(TickerId, TickType, int, double, double, double, double, double, double, double, double) override {}
	void tickGeneric(TickerId, TickType, double) override {}
	void tickString(TickerId, TickType, const std::string&) override {}
	void tickEFP(TickerId, TickType, double, const std::string&, double, int, const std::string&, double, double) override {}
	void openOrder(OrderId, const Contract&, const Order&, const OrderState&) override {}
	void openOrderEnd() override {}
	void winError(const std::string&, int) override {}
	void connectionClosed() override {}
	void updateAccountValue(const std::string&, const std::string&, const std::string&, const std::string&) override {}
	void updatePortfolio(const Contract&, Decimal, double, double, double, double, double, const std::string&) override {}
	void updateAccountTime(const std::string&) override {}
	void accountDownloadEnd(const std::string&) override {}
	void contractDetails(int, const ContractDetails&) override {}
	void bondContractDetails(int, const ContractDetails&) override {}
	void contractDetailsEnd(int) override {}
	void execDetails(int, const Contract&, const Execution&) override {}
	void execDetailsEnd(int) override {}
	void updateMktDepth(TickerId, int, int, int, double, Decimal) override {}
	void updateMktDepthL2(TickerId, int, const std::string&, int, int, double, Decimal, bool) override {}
	void updateNewsBulletin(int, int, const std::string&, const std::string&) override {}
	void managedAccounts(const std::string&) override {}
	void receiveFA(faDataType, const std::string&) override {}
	void scannerParameters(const std::string&) override {}
	void scannerData(int, int, const ContractDetails&, const std::string&, const std::string&, const std::string&, const std::string&) override {}
	void scannerDataEnd(int) override {}
	void realtimeBar(TickerId, long, double, double, double, double, Decimal, Decimal, int) override {}
	void currentTime(long) override {}
	void fundamentalData(TickerId, const std::string&) override {}
	void deltaNeutralValidation(int, const DeltaNeutralContract&) override {}
	void tickSnapshotEnd(int) override {}
	void marketDataType(TickerId, int) override {}
	void commissionAndFeesReport(const CommissionAndFeesReport&) override {}
	void position(const std::string&, const Contract&, Decimal, double) override {}
	void positionEnd() override {}
	void accountSummary(int, const std::string&, const std::string&, const std::string&, const std::string&) override {}
	void accountSummaryEnd(int) override {}
	void verifyMessageAPI(const std::string&) override {}
	void verifyCompleted(bool, const std::string&) override {}
	void displayGroupList(int, const std::string&) override {}
	void displayGroupUpdated(int, const std::string&) override {}
	void verifyAndAuthMessageAPI(const std::string&, const std::string&) override {}
	void verifyAndAuthCompleted(bool, const std::string&) override {}
	void connectAck() override {}
	void positionMulti(int, const std::string&, const std::string&, const Contract&, Decimal, double) override {}
	void positionMultiEnd(int) override {}
	void accountUpdateMulti(int, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&) override {}
	void accountUpdateMultiEnd(int) override {}
	void securityDefinitionOptionalParameter(int, const std::string&, int, const std::string&, const std::string&, const std::set<std::string>&, const std::set<double>&) override {}
	void securityDefinitionOptionalParameterEnd(int) override {}
	void softDollarTiers(int, const std::vector<SoftDollarTier>&) override {}
	void familyCodes(const std::vector<FamilyCode>&) override {}
	void symbolSamples(int, const std::vector<ContractDescription>&) override {}
	void mktDepthExchanges(const std::vector<DepthMktDataDescription>&) override {}
	void tickNews(int, time_t, const std::string&, const std::string&, const std::string&, const std::string&) override {}
	void smartComponents(int, const SmartComponentsMap&) override {}
	void tickReqParams(int, double, const std::string&, int) override {}
	void newsProviders(const std::vector<NewsProvider>&) override {}
	void newsArticle(int, int, const std::string&) override {}
	void historicalNews(int, const std::string&, const std::string&, const std::string&, const std::string&) override {}
	void historicalNewsEnd(int, bool) override {}
	void headTimestamp(int, const std::string&) override {}
	void histogramData(int, const HistogramDataVector&) override {}
	void historicalDataUpdate(TickerId, const Bar&) override {}
	void rerouteMktDataReq(int, int, const std::string&) override {}
	void rerouteMktDepthReq(int, int, const std::string&) override {}
	void marketRule(int, const std::vector<PriceIncrement>&) override {}
	void pnl(int, double, double, double) override {}
	void pnlSingle(int, Decimal, double, double, double, double) override {}
	void historicalTicks(int, const std::vector<HistoricalTick>&, bool) override {}
	void historicalTicksBidAsk(int, const std::vector<HistoricalTickBidAsk>&, bool) override {}
	void historicalTicksLast(int, const std::vector<HistoricalTickLast>&, bool) override {}
	void tickByTickAllLast(int, int, time_t, double, Decimal, const TickAttribLast&, const std::string&, const std::string&) override {}
	void tickByTickBidAsk(int, time_t, double, double, Decimal, Decimal, const TickAttribBidAsk&) override {}
	void tickByTickMidPoint(int, time_t, double) override {}
	void orderBound(long long, int, int) override {}
	void completedOrder(const Contract&, const Order&, const OrderState&) override {}
	void completedOrdersEnd() override {}
	void replaceFAEnd(int, const std::string&) override {}
	void wshMetaData(int, const std::string&) override {}
	void wshEventData(int, const std::string&) override {}
	void historicalSchedule(int, const std::string&, const std::string&, const std::string&, const std::vector<HistoricalSession>&) override {}
	void userInfo(int, const std::string&) override {}
	void currentTimeInMillis(time_t) override {}
	void execDetailsProtoBuf(const protobuf::ExecutionDetails&) override {}
	void execDetailsEndProtoBuf(const protobuf::ExecutionDetailsEnd&) override {}
	void orderStatusProtoBuf(const protobuf::OrderStatus&) override {}
	void openOrderProtoBuf(const protobuf::OpenOrder&) override {}
	void openOrdersEndProtoBuf(const protobuf::OpenOrdersEnd&) override {}
	void errorProtoBuf(const protobuf::ErrorMessage&) override {}

private:
	//std::shared_ptr<EClientSocket> sharedClientSocket;
	HistoricalData histData;
	MarketData     marketData;
	OrderManager   orderManager;
};

#endif