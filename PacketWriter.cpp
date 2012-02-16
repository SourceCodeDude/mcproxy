#include "StdInc.h"
#include "PacketWriter.h"
#include "Endian.h"
#include "utils/convert.h"

PacketWriter::PacketWriter()
{
	// converter UTF-8 -> UCS-2
	m_iconv = iconv_open("UCS-2", "UTF-8");
}

PacketWriter::PacketWriter(size_t iAllocSize)
{
	// converter UTF-8 -> UCS-2
	m_iconv = iconv_open("UCS-2", "UTF-8");

	m_strBuffer.reserve(iAllocSize);
}

PacketWriter::~PacketWriter()
{
	iconv_close(m_iconv);
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

void PacketWriter::addString(std::string strString)
{
	addShort(strString.length());

	char *pInput = (char *)strString.c_str();
	size_t iInputSize = strString.length();

	char *pOutput;
	size_t iOutputSize;
	convert(m_iconv, pInput, iInputSize, &pOutput, &iOutputSize);

	addBytes((const char *)pOutput, iOutputSize);

	free(pOutput);
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
