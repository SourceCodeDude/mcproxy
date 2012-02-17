#include "StdInc.h"
#include "VanillaClient.h"
#include "Endian.h"
#include <stdarg.h>
#include <string.h>

VanillaClient::VanillaClient()
	: TcpClient()
{
	m_pPacketParser = new PacketParser(SERVER);
	m_pPacketParser->registerPacketHandler(this);
}

VanillaClient::~VanillaClient()
{
	delete m_pPacketParser;
}

PacketParser *VanillaClient::getPacketParser()
{
	return m_pPacketParser;
}

int VanillaClient::sendf(int bytes, const char *szFormat, ...)
{
	va_list vaArgs;
	va_start(vaArgs, szFormat);
	uint8_t *buf = (uint8_t *)malloc(bytes);
	uint8_t *buf2 = buf;
	
	uint8_t c;
	for (uint8_t *i = (uint8_t *)szFormat; (c = *i) != '\0'; ++i)
	{
		switch (c)
		{
		case 'c':
			{
#ifdef WIN32
				uint8_t val = va_arg(vaArgs, uint8_t);
#else
				uint8_t val = (uint8_t) va_arg(vaArgs, int);
#endif
				*buf = val; // *buf++ ??
				++buf;
			}
			break;
		case 'i':
			{
				int32_t val = va_arg(vaArgs, int32_t);
				*(int32_t *)buf = htonl(val);
				buf += 4;
			}
			break;
		case 's':
			{
#ifdef WIN32
				int16_t val = va_arg(vaArgs, int16_t);
#else
				int16_t val = (int16_t) va_arg(vaArgs, int);
#endif
				*(int16_t *)buf = htons(val);
				buf += 2;
			}
			break;
		case 'l':
			{
				int64_t val = va_arg(vaArgs, int64_t);
				*(int64_t *)buf = htonll(val);
				buf += 8;
			}
			break;
		case 'd':
			{
				double val = va_arg(vaArgs, double);
				*(double *)buf = Endian::bigDouble(val); // TODO IEEE 754 ??
				buf += 8;
			}
			break;
		case 'f':
			{
#ifdef WIN32
				float val = va_arg(vaArgs, float);
#else
				float val = (float) va_arg(vaArgs, double);
#endif
				*(float *)buf = Endian::bigFloat(val); // TODO IEEE 754 ??
				buf += 4;
			}
			break;
		case 't':
			{
				char *str = va_arg(vaArgs, char *);
				size_t len = strlen(str);

				*(int16_t *)buf = htons(len);
				buf += 2;

				wchar_t *tmp = new wchar_t[len + 1];
				mbstowcs_s(&len, tmp, len + 1, str, len);
#ifdef WIN32
				--len; // strip 0x0000
#endif
				for (size_t k = 0; k < len; ++k)
				{
					//wbuf[k] = (int16_t)htons((int16_t) tmp[k]);
					*(int16_t *)buf = (int16_t)htons((int16_t) tmp[k]);
					buf += 2;
				}
				delete[] tmp;
			}
			break;
		}
	}
	va_end(vaArgs);

	//assert(buf - buf2 == bytes);

	send((const char *)buf2, bytes);
	
	free(buf2);

	return bytes;
}

void VanillaClient::onData(const char *pData, size_t iSize)
{
	try
	{
		m_pPacketParser->parseInput(pData, iSize);
	}
	catch (PacketParser::Exception ex)
	{
		printf("PacketParser::Exception (packet id 0x%02X, last ok 0x%02X)\n", ex.m_iPacketId, ex.m_iLastCompletePacket);
		getchar();
	}
}
