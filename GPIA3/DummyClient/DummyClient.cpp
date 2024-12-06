#include "pch.h"
#include <iostream>

int main()
{
	WSADATA wsaData;
	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 0;

	// 1) 소켓 생성
	// TCP
	//SOCKET clientSocket = ::socket(AF_INET, SOCK_STREAM, 0);
	// UDP
	SOCKET clientSocket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (clientSocket == INVALID_SOCKET)
		return 0;

	// 2) 서버 연결
	SOCKADDR_IN serverAddr;
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	::inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
	serverAddr.sin_port = ::htons(7777);

	/*if (::connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
		return 0;

	cout << "Connected To Server!" << endl;*/

	// 3) 통신
	while (true)
	{
		char sendBuffer[100] = "Hello! I am Client!";
		//int32 resultCode = ::send(clientSocket, sendBuffer, sizeof(sendBuffer), 0);
		::sendto(clientSocket, sendBuffer, sizeof(sendBuffer), 0, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
		/*if (resultCode == SOCKET_ERROR)
			return 0;*/

		/*char recvBuffer[100];
		int32 recvLen = ::recv(clientSocket, recvBuffer, sizeof(recvBuffer), 0);
		if (recvLen <= 0)
			return 0;

		cout << "Echo Data: " << recvBuffer << endl;*/

		this_thread::sleep_for(1s);
	}

	::closesocket(clientSocket);
	::WSACleanup();
}