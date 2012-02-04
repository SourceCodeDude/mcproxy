class PacketWriter;

#ifndef _PACKETWRITER_H
#define _PACKETWRITER_H

#include <string>
#include <TcpSocket.h>

class PacketWriter
{
public:
	PacketWriter();
	PacketWriter(size_t iAllocSize);
	~PacketWriter();

	void addBytes(const char *pData, size_t iSize);

	void addByte(unsigned char ucByte);
	void addShort(short iNum);
	void addInt(int iNum);
	void addLong(__int64 iNum);
	void addString(std::wstring wstrString);
	void addString(std::string strString);
	void addFloat(float fNum);
	void addDouble(double dNum);
	void addBool(bool bBool);

	void send(TcpSocket *pSocket);

private:
	std::string m_strBuffer;
};

#endif
