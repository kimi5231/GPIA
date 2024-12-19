﻿#include "pch.h"
#include "ThreadManager.h"
#include "Listener.h"
#include "Service.h"
#include "Session.h"

class GameSession : public Session
{

};

int main()
{
	SocketUtils::Init();

	ServerServiceRef service = make_shared<ServerService>(
		NetAddress(L"127.0.0.1", 7777),
		make_shared<IocpCore>(),
		[]() {return make_shared<GameSession>();},
		100);

	assert(service->Start());

	for (int32 i = 0; i < 5; ++i)
	{
		GThreadManager->Launch([=]() {
			while (true)
			{
				service->GetIocpCore()->Dispatch();
			}
		});
	}

	GThreadManager->Join();

	SocketUtils::Clear();
}