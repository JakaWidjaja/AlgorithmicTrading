#ifndef IB_CLIENT_CORE_H
#define IB_CLIENT_CORE_H

#include "EWrapper.h"
#include "EClientSocket.h"
#include "EReaderOSSignal.h"
#include "EReader.h"

#include <memory>
#include <thread>
#include <string>

class IBClientCore :public EWrapper
{
public:
	IBClientCore();
	virtual ~IBClientCore();

	void connect(const std::string& host, int port, int clientId);
	void disconnect();
	bool isConnected() const;

	EClientSocket* getClientSocket() const { return client.get(); }

protected:
	std::unique_ptr<EReaderOSSignal> osSignal;
	std::unique_ptr<EClientSocket> client;
	std::unique_ptr<EReader> reader;
	std::thread readerThread;
};

#endif