#include "StdInc.h"
#include "MapChunk.h"
#include "../zlib.h"
#include <vector>

bool MapChunk::readPacket(PacketParser *pParser)
{
	int iX = pParser->getInt();
	short y = pParser->getShort();
	int iZ = pParser->getInt();
	char cSX = pParser->getByte();
	char cSY = pParser->getByte();
	char cSZ = pParser->getByte();
	int iSize = pParser->getInt();
	
	std::vector<unsigned char> vecBytes(iSize);
	pParser->getBytes((unsigned char *)&vecBytes[0], iSize);
	//printf("[CHUNK] %d/%d/%d size %d/%d/%d (B %d)\n", iX, y, iZ, cSX, cSY, cSZ, iSize);

	/*z_stream strm;
	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;
	strm.avail_in = 0;
	strm.next_in = Z_NULL;
	int ret = inflateInit(&strm);
	assert(ret == Z_OK);

	strm.avail_in = iSize;
	strm.next_in = tmp;

	unsigned char out[100000];
	strm.avail_out = 100000;
	strm.next_out = out;
	ret = inflate(&strm, Z_NO_FLUSH);
	assert(ret != Z_STREAM_ERROR);
	inflateEnd(&strm);

	assert(100000 - strm.avail_out == (cSX + 1) * (cSY + 1) * (cSZ + 1) * 2.5);*/

	pParser->getPacketHandlerHelper()->onMapChunk(iX, y, iZ, cSX, cSY, cSZ, iSize);
	return true;
}

bool MapChunk::writePacket(PacketWriter *pWriter)
{
	return false;
}
