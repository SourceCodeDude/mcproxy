class AddObjectVehicle;

#ifndef _ADDOBJECTVEHICLE_H
#define _ADDOBJECTVEHICLE_H

#include "../Packet.h"
#include "../PacketParser.h"

class AddObjectVehicle : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(AddObjectVehicle);

#endif
