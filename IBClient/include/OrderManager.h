#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include "Order.h"
#include "OrderCancel.h" 
#include "Contract.h"
#include "EClientSocket.h"
#include "CommonDefs.h"
#include <mutex>
#include <memory>
#include <map>
#include <string>

class OrderManager
{
public:
	OrderManager();

	void setClient(EClientSocket* client);
	void setNextOrderId(int id);
	int getNextOrderId() const;

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
	void cancelOrder(OrderId id); 
	void cancelOrder(OrderId id, const OrderCancel& cancel);
	void cancelAllOrders();

private:
	EClientSocket* clientSocket = nullptr;
	mutable std::mutex orderMutex;
	int orderIdCounter = 100;

	int getAndIncrementOrderId();
};

#endif