#include "pch.h"
#include "ThreadManager.h"

const int32 BUF_SIZE = 1000;

struct Session
{
	SOCKET socket = INVALID_SOCKET;
	char recvBuffer[BUF_SIZE]{};
	int32 recvBytes = 0;
};

int main()
{
	SocketUtils::Init();

	SOCKET listenSocket = ::socket(AF_INET, SOCK_STREAM, 0);
	if (listenSocket == INVALID_SOCKET)
		return 0;

	u_long on = 1;
	if (::ioctlsocket(listenSocket, FIONBIO, &on) == INVALID_SOCKET)
		return 0;

	SocketUtils::SetReuseAddress(listenSocket, true);

	if (SocketUtils::BindAnyAddress(listenSocket, 7777) == false)
		return 0;

	if (SocketUtils::Listen(listenSocket) == false)
		return 0;

	vector<WSAEVENT> wsaEvents;
	vector<Session> sessions;
	sessions.reserve(100);

	WSAEVENT listenEvent = ::WSACreateEvent();
	wsaEvents.push_back(listenEvent);
	sessions.push_back(Session{ listenSocket });

	if (::WSAEventSelect(listenSocket, listenEvent, FD_ACCEPT | FD_CLOSE) == SOCKET_ERROR)
		return 0;

	while (true)
	{
		int32 index = ::WSAWaitForMultipleEvents(wsaEvents.size(), &wsaEvents[0], FALSE, WSA_INFINITE, FALSE);
		if (index == WSA_WAIT_FAILED)
			continue;

		index -= WSA_WAIT_EVENT_0;
		
		WSANETWORKEVENTS networkEvents;
		if (::WSAEnumNetworkEvents(sessions[index].socket, wsaEvents[index], &networkEvents) == SOCKET_ERROR)
			continue;

		if (networkEvents.lNetworkEvents & FD_ACCEPT)
		{
			if (networkEvents.iErrorCode[FD_ACCEPT_BIT] != 0)
				continue;

			SOCKADDR_IN clientAddr;
			int32 addrLen = sizeof(clientAddr);

			SOCKET clientSocket = ::accept(listenSocket, (SOCKADDR*)&clientAddr, &addrLen);
			if (clientSocket != INVALID_SOCKET)
			{
				cout << "Client Connected!" << endl;

				WSAEVENT clientEvent = ::WSACreateEvent();
				wsaEvents.push_back(clientEvent);
				sessions.push_back(Session{ clientSocket });
				if (::WSAEventSelect(clientSocket, clientEvent, FD_READ | FD_WRITE | FD_CLOSE) == SOCKET_ERROR)
					return 0;
			}
		}
		
		if (networkEvents.lNetworkEvents & FD_READ)
		{
			if (networkEvents.iErrorCode[FD_ACCEPT_BIT] != 0)
				continue;

			Session& s = sessions[index];

			int32 recvLen = ::recv(s.socket, s.recvBuffer, BUF_SIZE, 0);
			if (recvLen == SOCKET_ERROR && ::WSAGetLastError() != WSAEWOULDBLOCK)
			{
				if (recvLen <= 0)
					continue;
			}

			cout << "recv Data = " << s.recvBuffer << endl;
			cout << "recvLen = " << recvLen << endl;
		}
	}

	SocketUtils::Clear();
}