#include "pch.h"
#include "ThreadManager.h"
#include "Listener.h"
#include "Service.h"
#include "Session.h"
#include "GameSession.h"
#include "ServerPacketHandler.h"
#include "GameSessionManager.h"

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

	while (true)
	{
		vector<BuffData> buffs{ BuffData {100, 1.5f}, BuffData{200, 2.3f}, BuffData {300, 0.7f } };
		SendBufferRef sendBuffer = ServerPacketHandler::Make_S_TEST(1001, 100, 10, buffs);
		GSessionManager.Broadcast(sendBuffer);

		this_thread::sleep_for(250ms);
	}

	GThreadManager->Join();

	SocketUtils::Clear();
}