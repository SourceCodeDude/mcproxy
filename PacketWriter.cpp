#include "StdInc.h"
#include "PacketWriter.h"
#include "Endian.h"

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

void PacketWriter::addByte(unsigned char ucByte)
{
	addBytes((const char *)&ucByte, sizeof(ucByte));
}

void PacketWriter::addShort(short iNum)
{
	iNum = htons(iNum);
	addBytes((const char *)&iNum, sizeof(iNum));
}

void PacketWriter::addInt(int iNum)
{
	iNum = htonl(iNum);
	addBytes((const char *)&iNum, sizeof(iNum));
}

void PacketWriter::addLong(__int64 iNum)
{
	iNum = htonll(iNum);
	addBytes((const char *)&iNum, sizeof(iNum));
}

void PacketWriter::addString(std::wstring wstrString)
{
	addShort(wstrString.length());
	for (std::wstring::iterator i = wstrString.begin(); i != wstrString.end(); ++i)
	{
		*i = htons(*i);
	}
	addBytes((const char *)wstrString.c_str(), wstrString.length() * sizeof(wchar_t));
}

void PacketWriter::addString(std::string strString)
{
	wchar_t *pString = new wchar_t[strString.length()];
	size_t iConv;
	mbstowcs_s(&iConv, pString, strString.length(), strString.c_str(), strString.length());
	std::wstring wstr(pString, iConv);
	delete[] pString;
	addString(wstr);
}

void PacketWriter::addFloat(float fNum)
{
	fNum = Endian::bigFloat(fNum);
	addBytes((const char *)&fNum, sizeof(fNum));
}

void PacketWriter::addDouble(double dNum)
{
	dNum = Endian::bigDouble(dNum);
	addBytes((const char *)&dNum, sizeof(dNum));
}

void PacketWriter::addBool(bool bBool)
{
	addBytes((const char *)&bBool, sizeof(bBool));
}

void PacketWriter::send(TcpSocket *pSocket)
{
	pSocket->SendBuf(m_strBuffer.c_str(), m_strBuffer.length());
}
