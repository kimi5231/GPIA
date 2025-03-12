#include "pch.h"
#include "ThreadManager.h"
#include "Listener.h"
#include "Service.h"
#include "Session.h"
#include "GameSession.h"
#include "ServerPacketHandler.h"
#include "GameSessionManager.h"
#include "GameRoom.h"

int main()
{
	SocketUtils::Init();

	GRoom->Init();

	ServerServiceRef service = make_shared<ServerService>(
		NetAddress(L"127.0.0.1", 7777),
		make_shared<IocpCore>(),
		[]() {return make_shared<GameSession>();},
		100);

	assert(service->Start());

	while (true)
	{
		service->GetIocpCore()->Dispatch(0);
		GRoom->Update();
	}

	GThreadManager->Join();

	SocketUtils::Clear();
}