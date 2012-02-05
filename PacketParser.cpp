#include "StdInc.h"
#include "Endian.h"
#include "PacketParser.h"
#include "Packets.h"

PacketParser::PacketParser(ePacketSource packetSource)
	: m_packetSource(packetSource), m_iLastCompletePacket(-1)
{
	m_pPacketHandlerHelper = new PacketHandlerHelper(this);
}

PacketParser::~PacketParser()
{
	delete m_pPacketHandlerHelper;
}

ePacketSource PacketParser::getPacketSource()
{
	return m_packetSource;
}

void PacketParser::registerPacketHandler(IPacketHandler *pHandler)
{
	for (std::list<IPacketHandler *>::iterator i = m_lstPacketHandlers.begin(); i != m_lstPacketHandlers.end(); ++i)
	{
		if (*i == pHandler)
		{
			return;
		}
	}

	m_lstPacketHandlers.push_back(pHandler);
}

bool PacketParser::unregisterPacketHandler(IPacketHandler *pHandler)
{
	for (std::list<IPacketHandler *>::iterator i = m_lstPacketHandlers.begin(); i != m_lstPacketHandlers.end(); ++i)
	{
		if (*i == pHandler)
		{
			i = m_lstPacketHandlers.erase(i);
			return true;
		}
	}

	return false;
}

IPacketHandler *PacketParser::getPacketHandlerHelper()
{
	return m_pPacketHandlerHelper;
}

void PacketParser::parseInput(const char *pData, size_t iSize)
{
	m_strBuffer.append(pData, iSize);
	std::string::iterator strip = m_strBuffer.begin();

	for (std::string::iterator i = m_strBuffer.begin(); i != m_strBuffer.end();)
	{
		uint8_t p = (uint8_t) *i;
		++i; // skip packet id

		Packet *pack = Packets::createPacket((int) p);
		if (pack != NULL)
		{
			m_itCurrentIterator = i;
			try
			{
				for (std::list<IPacketHandler *>::iterator x = m_lstPacketHandlers.begin(); x != m_lstPacketHandlers.end(); ++x)
				{
					(*x)->m_packetSource = m_packetSource;
				}

				if (pack->readPacket(this))
				{
					strip = i = m_itCurrentIterator;
					m_iLastCompletePacket = (int) p;
				}
				else
				{
					printf("WARNING: Failed to handle packet 0x%02X as %s packet\n", p, m_packetSource == SERVER ? "server" : "client");
				}
				
				for (std::list<IPacketHandler *>::iterator x = m_lstPacketHandlers.begin(); x != m_lstPacketHandlers.end(); ++x)
				{
					(*x)->m_packetSource = UNKNOWN;
				}
			}
			catch (PacketIncompleteNotification)
			{
				// This packet is incomplete, we'll do it next time.
				delete pack;
				break;
			}

			delete pack;
		}
		else
		{
			Exception ex;
			ex.m_iPacketId = p;
			ex.m_iLastCompletePacket = m_iLastCompletePacket;
			throw ex;
		}

		if (i == m_strBuffer.end())
			break;
	}

	if (strip != m_strBuffer.begin())
	{
		m_strBuffer.erase(m_strBuffer.begin(), strip);
	}
}

void PacketParser::getBytes(uint8_t *dest, size_t num)
{
	size_t c = 0;
	for (; c < num && m_itCurrentIterator != m_strBuffer.end(); ++m_itCurrentIterator)
	{
		dest[c++] = *m_itCurrentIterator;
	}

	if (num - c != 0)
	{
		PacketIncompleteNotification e;
		e.m_iMinMissingBytes = num - c;
		throw e;
	}
}

uint8_t PacketParser::getByte()
{
	uint8_t ucByte;
	getBytes(&ucByte, 1);
	return ucByte;
}

int16_t PacketParser::getShort()
{
	int16_t iShort;
	getBytes((uint8_t *)&iShort, 2);
	return ntohs(iShort);
}

int32_t PacketParser::getInt()
{
	int32_t iInt;
	getBytes((uint8_t *)&iInt, 4);
	return ntohl(iInt);
}

int64_t PacketParser::getLong()
{
	int64_t iLong;
	getBytes((uint8_t *)&iLong, 8);
	return ntohll(iLong);
}

std::wstring PacketParser::getString()
{
	int16_t iLength;
	getBytes((uint8_t *)&iLength, 2);
	iLength = ntohs(iLength);

	std::wstring wstrString;
	wstrString.resize(iLength);
	uint16_t *tmp = new uint16_t[iLength];
	getBytes((uint8_t *)tmp, iLength * 2);

	size_t k = 0;
	for (std::wstring::iterator i = wstrString.begin(); i != wstrString.end(); ++i)
	{
		*i = ntohs(tmp[k++]);
	}
	return wstrString;
}

float PacketParser::getFloat()
{
	float fFloat;
	getBytes((uint8_t *)&fFloat, 4);
	return Endian::bigFloat(fFloat);
}

double PacketParser::getDouble()
{
	double dDouble;
	getBytes((uint8_t *)&dDouble, 8);
	return Endian::bigDouble(dDouble);
}

bool PacketParser::getBool()
{
	uint8_t ucByte;
	getBytes(&ucByte, 1);
	return ucByte != 0;
}

void PacketParser::getMetadata()
{
	uint8_t p = getByte();
	while (p != 0x7F)
	{
		switch (p >> 5)
		{
		case 0:
			getByte();
			break;
		case 1:
			getShort();
			break;
		case 2:
			getInt();
			break;
		case 3:
			getFloat();
			break;
		case 4:
			getString();
			break;
		case 5:
			getShort();
			getByte();
			getShort();
			break;
		case 6:
			getInt();
			getInt();
			getInt();
			break;
		default:
			printf("UNHANDLED metadata type %d\n", p >> 5);
			break;
		}
		p = getByte();
	}
}
