class PacketParser;

#ifndef _PACKETPARSER_H
#define _PACKETPARSER_H

#include <string>
#include <exception>
#include <list>
#include "PacketHandlerHelper.h"
#include "PacketSource.h"
#include <iconv.h>

class PacketParser
{
	friend class PacketHandlerHelper;

public:
	class Exception : public std::exception
	{
	public:
		int m_iPacketId;
		int m_iLastCompletePacket;
	};
	class PacketIncompleteNotification
	{
	public:
		int m_iMinMissingBytes;
	};

	PacketParser(ePacketSource packetSource);
	~PacketParser();

	ePacketSource getPacketSource();

	void registerPacketHandler(IPacketHandler *pHandler);
	bool unregisterPacketHandler(IPacketHandler *pHandler);
	IPacketHandler *getPacketHandlerHelper();

	void parseInput(const char *pData, size_t iSize);

	void getBytes(uint8_t *dest, size_t num);

	uint8_t getByte();
	int16_t getShort();
	int32_t getInt();
	int64_t getLong();
	std::string getString();
	float getFloat();
	double getDouble();
	bool getBool();
	void getMetadata();

private:
	ePacketSource m_packetSource;
	std::string m_strBuffer;
	std::string::iterator m_itCurrentIterator;
	int m_iLastCompletePacket;

	std::list<IPacketHandler *> m_lstPacketHandlers;
	IPacketHandler *m_pPacketHandlerHelper;

	iconv_t m_iconv;
};

#endif
