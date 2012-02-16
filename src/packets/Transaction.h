class Transaction;

#ifndef _TRANSACTION_H
#define _TRANSACTION_H

#include "../Packet.h"
#include "../PacketParser.h"

class Transaction : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter);
};

REGISTER_PACKET(Transaction);

#endif
