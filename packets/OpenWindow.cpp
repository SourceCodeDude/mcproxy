#include "StdInc.h"
#include "OpenWindow.h"

bool OpenWindow::readPacket(PacketParser *pParser)
{
	unsigned char ucWindow = pParser->getByte();
	unsigned char ucType = pParser->getByte();
	std::wstring wstrTitle = pParser->getString();
	unsigned char ucNumSlots = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onOpenWindow(ucWindow, ucType, wstrTitle, ucNumSlots);
	return true;
}

bool OpenWindow::writePacket()
{
	return false;
}
