#pragma once

enum
{
	S_TEST = 1,
	S_EnterGame = 2,
};

class ClientPacketHandler
{
public:
	static void HandlePacket(BYTE* buffer, int32 len);

	static void Handle_S_TEST(BYTE* buffer, int32 len);
	static void Handle_S_EnterGame(BYTE* buffer, int32 len);

	template<typename T>
	static SendBufferRef MakeSendBuffer(T& pkt, uint16 pktId);
};


