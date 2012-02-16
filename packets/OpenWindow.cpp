#include "StdInc.h"
#include "OpenWindow.h"

bool OpenWindow::readPacket(PacketParser *pParser)
{
	unsigned char ucWindow = pParser->getByte();
	unsigned char ucType = pParser->getByte();
	std::string strTitle = pParser->getString();
	unsigned char ucNumSlots = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onOpenWindow(ucWindow, ucType, strTitle, ucNumSlots);
	return true;
}

bool OpenWindow::writePacket(PacketWriter *pWriter, unsigned char ucWindow, unsigned char ucType, std::string strTitle, unsigned char ucNumSlots)
{
	pWriter->addByte(0x64);
	pWriter->addByte(ucWindow);
	pWriter->addByte(ucType);
	pWriter->addString(strTitle);
	pWriter->addByte(ucNumSlots);
	return true;
}
