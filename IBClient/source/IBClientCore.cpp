#include "IBClientCore.h"
#include <iostream>
#include <memory>
#include <string>

using std::make_unique;
using std::string;
using std::thread;
using std::cerr;
using std::cout;

IBClientCore::IBClientCore() : osSignal(make_unique<EReaderOSSignal>(1000)), client(make_unique<EClientSocket>(this, osSignal.get()))
{}

IBClientCore::~IBClientCore()
{
	disconnect();
}

void IBClientCore::connect(const string& host, int port, int clientId)
{
	if(client -> eConnect(host.c_str(), port, clientId))
	{
		cout << "Connected to TWS\n";

		reader = make_unique<EReader>(client.get(), osSignal.get());
		reader -> start();
		readerThread = thread([this]()
		{
			while(client -> isConnected())
			{
				osSignal -> waitForSignal();
				reader -> processMsgs();
			}
		});
	}
	else
	{
		cerr << "Failed to connect to TWS\n";
	}
}

void IBClientCore::disconnect()
{
	if(client -> isConnected())
	{
		client -> eDisconnect();
	}

	if(readerThread.joinable())
	{
		readerThread.join();
	}

	reader.reset();
}

bool IBClientCore::isConnected() const
{
	return client -> isConnected();
}