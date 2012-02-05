#include "StdInc.h"
#include "PacketWriter.h"
#include "Endian.h"
#include "utils/StringConvert.h"

PacketWriter::PacketWriter()
{
}

PacketWriter::PacketWriter(size_t iAllocSize)
{
	m_strBuffer.reserve(iAllocSize);
}

PacketWriter::~PacketWriter()
{
}

void PacketWriter::addBytes(const char *pData, size_t iSize)
{
	m_strBuffer.append(pData, iSize);
}

void PacketWriter::addByte(uint8_t ucByte)
{
	addBytes((const char *)&ucByte, 1);
}

void PacketWriter::addShort(int16_t iNum)
{
	iNum = htons(iNum);
	addBytes((const char *)&iNum, sizeof(iNum));
}

void PacketWriter::addInt(int32_t iNum)
{
	iNum = htonl(iNum);
	addBytes((const char *)&iNum, sizeof(iNum));
}

void PacketWriter::addLong(int64_t iNum)
{
	iNum = htonll(iNum);
	addBytes((const char *)&iNum, sizeof(iNum));
}

void PacketWriter::addString(std::wstring wstrString)
{
	addShort(wstrString.length());
	int16_t *tmp = new int16_t[wstrString.length()];
	size_t k = 0;
	for (std::wstring::iterator i = wstrString.begin(); i != wstrString.end(); ++i)
	{
		tmp[k++] = htons(*i);
	}
	addBytes((const char *)tmp, wstrString.length() * sizeof(int16_t));
	delete[] tmp;
}

void PacketWriter::addString(std::string strString)
{
	addString(StringConvert::widen(strString));
}

void PacketWriter::addFloat(float fNum)
{
	fNum = Endian::bigFloat(fNum);
	addBytes((const char *)&fNum, 4);
}

void PacketWriter::addDouble(double dNum)
{
	dNum = Endian::bigDouble(dNum);
	addBytes((const char *)&dNum, 8);
}

void PacketWriter::addBool(bool bBool)
{
	addBytes((const char *)&bBool, 1);
}

void PacketWriter::send(TcpSocket *pSocket)
{
	pSocket->SendBuf(m_strBuffer.c_str(), m_strBuffer.length());
}
