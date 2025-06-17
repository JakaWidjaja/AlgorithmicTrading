#include "OrderManager.h"
#include <stdexcept>
#include <string>
#include <vector>
#include <tuple>

using std::scoped_lock;
using std::string;
using std::move;
using std::runtime_error;
using std::vector;
using std::tuple;

OrderManager::OrderManager() = default;

void OrderManager::setClient(EClientSocket* client)
{
	this -> clientSocket = client; 
}

void OrderManager::setNextOrderId(int orderId)
{
	scoped_lock lock(orderMutex);
	orderIdCounter = orderId;
}

int OrderManager::getNextOrderId() const
{
	scoped_lock lock(orderMutex);
	return orderIdCounter;
}

int OrderManager::getAndIncrementOrderId()
{
	scoped_lock lock(orderMutex);
	std::cout << "[DEBUG] Next order ID used: " << orderIdCounter << std::endl;
	return orderIdCounter++;
}

void OrderManager::placeMarketOrder(const Contract& contract, double quantity, const string& direction)
{
	if(!clientSocket)
	{
		throw runtime_error("Client socket not set");
	}

	Order order;
	order.action        = direction;
	order.orderType     = "MKT";
	order.totalQuantity = quantity;
	order.transmit      = true;

	clientSocket -> placeOrder(getAndIncrementOrderId(), contract, order);
}

void OrderManager::placeLimitOrder(const Contract& contract, double quantity, const string& direction, double limitPrice)
{
	if(!clientSocket)
	{
		throw runtime_error("Client socket not set");
	}
	if (quantity <= 0) 
	{
	    std::cerr << "[FATAL] Invalid quantity: " << quantity << std::endl;
	    return;
	}

	int orderId = getAndIncrementOrderId();

    std::cout << "[INFO] Placing limit order - ID: " << orderId
              << ", Symbol: " << contract.symbol
              << ", Qty: " << quantity
              << ", Price: " << limitPrice << "\n";

	Order order;
	order.action        = direction;
	order.orderType     = "LMT";
	order.totalQuantity = quantity;
	order.lmtPrice      = limitPrice;
	order.transmit      = true;

	clientSocket -> placeOrder(getAndIncrementOrderId(), contract, order);
}

void OrderManager::placeStopOrder(const Contract& contract, double quantity, const string& direction, double stopPrice)
{
	if(!clientSocket)
	{
		throw runtime_error("Client socket not set");
	}
	Order order;
	order.orderType     = "STP";
	order.action        = direction;
	order.totalQuantity = quantity;
	order.auxPrice      = stopPrice;
	order.transmit      = true;

	clientSocket -> placeOrder(getAndIncrementOrderId(), contract, order);
}

void OrderManager::placeStopLimitOrder(const Contract& contract, double quantity, const string& direction, double stopPrice, double limitPrice)
{
	if(!clientSocket)
	{
		throw runtime_error("Client socket not set");
	}
	Order order;
	order.orderType     = "STP LMT";
	order.action        = direction;
	order.totalQuantity = quantity;
	order.auxPrice      = stopPrice;
	order.lmtPrice      = limitPrice;
	order.transmit      = true;

	clientSocket -> placeOrder(getAndIncrementOrderId(), contract, order);
}

void OrderManager::placeTrailingStopOrder(const Contract& contract, double quantity, const string& direction, double trailingAmount)
{
	if(!clientSocket)
	{
		throw runtime_error("Client socket not set");
	}
	Order order;
	order.orderType       = "TRAIL";
	order.action          = direction;
	order.totalQuantity   = quantity;
	order.trailingPercent = false;
	order.auxPrice        = trailingAmount;
	order.transmit        = true;

	clientSocket->placeOrder(getAndIncrementOrderId(), contract, order);
}

void OrderManager::placeTrailingStopLimitOrder(const Contract& contract, double quantity, const string& direction, double trailingAmount, double limitOffset)
{
	if (!clientSocket)
		throw std::runtime_error("Client socket not set");

	Order order;
	order.orderType      = "TRAIL LIMIT";
	order.action         = direction;
	order.totalQuantity  = quantity;
	order.auxPrice       = trailingAmount;
	order.lmtPriceOffset = limitOffset;
	order.transmit       = true;

	clientSocket->placeOrder(getAndIncrementOrderId(), contract, order);
}

void OrderManager::placeMarketOnCloseOrder(const Contract& contract, double quantity, const string& direction)
{
	if(!clientSocket)
	{
		throw runtime_error("Client socket not set");
	}

	Order order;
    order.orderType     = "MOC";
    order.action        = direction;
    order.totalQuantity = quantity;
    order.transmit      = true;
    clientSocket -> placeOrder(getAndIncrementOrderId(), contract, order);
}

void OrderManager::placeLimitOnCloseOrder(const Contract& contract, double quantity, const string& direction, double limitPrice)
{
    if(!clientSocket)
	{
		throw runtime_error("Client socket not set");
	}

    Order order;
    order.orderType     = "LOC";
    order.action        = direction;
    order.totalQuantity = quantity;
    order.lmtPrice      = limitPrice;
    order.transmit      = true;

    clientSocket -> placeOrder(getAndIncrementOrderId(), contract, order);
}

void OrderManager::placePeggedToMarketOrder(const Contract& contract, double quantity, const string& direction, double offset)
{
    if(!clientSocket)
	{
		throw runtime_error("Client socket not set");
	}

    Order order;
    order.orderType     = "PEG MKT";
    order.action        = direction;
    order.totalQuantity = quantity;
    order.auxPrice      = offset; // offset from best bid/ask
    order.transmit      = true;

    clientSocket -> placeOrder(getAndIncrementOrderId(), contract, order);
}

void OrderManager::placePeggedToMidpointOrder(const Contract& contract, double quantity, const string& direction, double offset)
{
    if(!clientSocket)
	{
		throw runtime_error("Client socket not set");
	}

    Order order;
    order.orderType     = "PEG MID";
    order.action        = direction;
    order.totalQuantity = quantity;
    order.auxPrice      = offset; // offset from midpoint
    order.transmit      = true;

    clientSocket -> placeOrder(getAndIncrementOrderId(), contract, order);
}

void OrderManager::placeRelativeOrder(const Contract& contract, double quantity, const string& direction, double offset)
{
    if(!clientSocket)
	{
		throw runtime_error("Client socket not set");
	}

    Order order;
    order.orderType     = "REL";
    order.action        = direction;
    order.totalQuantity = quantity;
    order.auxPrice      = offset; // offset from best bid/ask
    order.transmit      = true;
    clientSocket -> placeOrder(getAndIncrementOrderId(), contract, order);
}

void OrderManager::placeOcaGroupOrders(const vector<tuple<Contract, double, string, string, double>>& orders, const string& ocaGroup)
{
    if(!clientSocket)
	{
		throw runtime_error("Client socket not set");
	}

    for (const auto& [contract, qty, direction, orderType, price] : orders) {
        Order order;
        order.orderType     = orderType;
        order.action        = direction;
        order.totalQuantity = qty;
        order.ocaGroup      = ocaGroup;
        order.ocaType       = 1; // CANCEL_WITH_BLOCK
        order.transmit      = false;

        if (orderType == "LMT" || orderType == "LOC") order.lmtPrice = price;
        if (orderType == "STP") order.auxPrice = price;

        clientSocket -> placeOrder(getAndIncrementOrderId(), contract, order);
    }

    // Transmit the last one
    if (!orders.empty()) {
        auto& [contract, qty, direction, orderType, price] = orders.back();
        Order order;
        order.orderType     = orderType;
        order.action        = direction;
        order.totalQuantity = qty;
        order.ocaGroup      = ocaGroup;
        order.ocaType       = 1;
        order.transmit      = true;

        if (orderType == "LMT" || orderType == "LOC") order.lmtPrice = price;
        if (orderType == "STP") order.auxPrice = price;

        clientSocket -> placeOrder(getAndIncrementOrderId(), contract, order);
    }
}

void OrderManager::placeBracketOrder(const Contract& contract, double quantity, double entryPrice, double takeProfitPrice, double stopLossPrice, const string& direction)
{
    if(!clientSocket)
	{
		throw runtime_error("Client socket not set");
	}

    int parentId = getAndIncrementOrderId();

    Order parent;
    parent.orderId       = parentId;
    parent.orderType     = "LMT";
    parent.action        = direction;
    parent.totalQuantity = quantity;
    parent.lmtPrice      = entryPrice;
    parent.transmit      = false;

    Order takeProfit;
    takeProfit.orderId       = getAndIncrementOrderId();
    takeProfit.action        = (direction == "BUY") ? "SELL" : "BUY";
    takeProfit.orderType     = "LMT";
    takeProfit.totalQuantity = quantity;
    takeProfit.lmtPrice      = takeProfitPrice;
    takeProfit.parentId      = parentId;
    takeProfit.transmit      = false;

    Order stopLoss;
    stopLoss.orderId       = getAndIncrementOrderId();
    stopLoss.action        = (direction == "BUY") ? "SELL" : "BUY";
    stopLoss.orderType     = "STP";
    stopLoss.totalQuantity = quantity;
    stopLoss.auxPrice      = stopLossPrice;
    stopLoss.parentId      = parentId;
    stopLoss.transmit      = true;

    clientSocket -> placeOrder(parent.orderId, contract, parent);
    clientSocket -> placeOrder(takeProfit.orderId, contract, takeProfit);
    clientSocket -> placeOrder(stopLoss.orderId, contract, stopLoss);
}


void OrderManager::placeTimeBasedOrder(const Contract& contract, double quantity, const string& direction, const string& orderType, double price, const string& goodAfterTime, const string& goodTillDate)
{
    if(!clientSocket)
	{
		throw runtime_error("Client socket not set");
	}

    Order order;
    order.orderType     = orderType;
    order.action        = direction;
    order.totalQuantity = quantity;
    order.transmit      = true;

    if (orderType == "LMT" || orderType == "LOC") order.lmtPrice = price;
    if (orderType == "STP") order.auxPrice = price;

    if (!goodAfterTime.empty()) order.goodAfterTime = goodAfterTime;
    if (!goodTillDate.empty()) order.goodTillDate = goodTillDate;

    clientSocket -> placeOrder(getAndIncrementOrderId(), contract, order);
}



void OrderManager::cancelOrder(OrderId orderId)
{
	if(!clientSocket)
	{
		throw runtime_error("Client socket not set");
	}

	OrderCancel cancel;
	cancelOrder(orderId, cancel);
}

void OrderManager::cancelOrder(OrderId id, const OrderCancel& cancel)
{
	if (!clientSocket)
	{
		throw runtime_error("Client socket not set");
	}

	clientSocket -> cancelOrder(id, cancel);
}

void OrderManager::cancelAllOrders()
{
	if(!clientSocket)
	{
		throw runtime_error("Client socket not set");
	}

	OrderCancel cancel;
	clientSocket -> reqGlobalCancel(cancel); 
}

