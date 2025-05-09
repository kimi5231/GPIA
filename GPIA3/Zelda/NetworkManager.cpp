#include "pch.h"
#include "Service.h"
#include "ServerSession.h"
#include "NetworkManager.h"
#include "ThreadManager.h"

void NetworkManager::Init()
{
	SocketUtils::Init();

	_service = make_shared<ClientService>(
		NetAddress(L"127.0.0.1", 7777),
		make_shared<IocpCore>(),
		[=]() { return CreateSession(); },
		1);

	assert(_service->Start());
}

void NetworkManager::Update()
{
	_service->GetIocpCore()->Dispatch(0);
}

ServerSessionRef NetworkManager::CreateSession()
{
	return _session = make_shared<ServerSession>();
}

void NetworkManager::SendPacket(SendBufferRef sendBuffer)
{
	if (_session)
		_session->Send(sendBuffer);
}