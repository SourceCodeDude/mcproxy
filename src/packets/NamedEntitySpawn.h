class NamedEntitySpawn;

#ifndef _NAMEDENTITYSPAWN_H
#define _NAMEDENTITYSPAWN_H

#include "../Packet.h"
#include "../PacketParser.h"

class NamedEntitySpawn : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, int iEntity, std::string strName, int iX, int iY, int iZ, char cRot, char cPitch, short iItem);
};

REGISTER_PACKET(NamedEntitySpawn);

#endif
