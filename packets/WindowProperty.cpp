#include "StdInc.h"
#include "WindowProperty.h"

bool WindowProperty::readPacket(PacketParser *pParser)
{
	unsigned char ucWindow = pParser->getByte();
	short iProperty = pParser->getShort();
	short iValue = pParser->getShort();
	
	pParser->getPacketHandlerHelper()->onWindowProperty(ucWindow, iProperty, iValue);
	return true;
}

bool WindowProperty::writePacket(PacketWriter *pWriter)
{
	return false;
}
