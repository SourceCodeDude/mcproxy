class AddObjectVehicle;

#ifndef _ADDOBJECTVEHICLE_H
#define _ADDOBJECTVEHICLE_H

#include "../Packet.h"
#include "../PacketParser.h"

class AddObjectVehicle : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, int iEntity, unsigned char ucType, int iX, int iY, int iZ, int iUnk1, short unk2, short unk3, short unk4);
};

REGISTER_PACKET(AddObjectVehicle);

#endif
