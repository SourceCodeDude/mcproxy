#include "StdInc.h"
#include "VanillaClient.h"
#include "Endian.h"

VanillaClient::VanillaClient(ISocketHandler &h)
	: TcpSocket(h)
{
	m_pPacketParser = new PacketParser();
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
	char *buf = (char *)malloc(bytes);
	char *buf2 = buf;
	char c;
	for (char *i = (char *)szFormat; (c = *i) != '\0'; ++i)
	{
		switch (c)
		{
		case 'c':
			{
				char val = va_arg(vaArgs, char);
				*buf = val; // *buf++ ??
				++buf;
			}
			break;
		case 'i':
			{
				int val = va_arg(vaArgs, int);
				*(int *)buf = htonl(val);
				buf += sizeof(int);
			}
			break;
		case 's':
			{
				short val = va_arg(vaArgs, short);
				*(short *)buf = htons(val);
				buf += sizeof(short);
			}
			break;
		case 'l':
			{
				long long val = va_arg(vaArgs, long long);
				*(long long *)buf = htonll(val);
				buf += sizeof(long long);
			}
			break;
		case 'd':
			{
				double val = va_arg(vaArgs, double);
				*(double *)buf = Endian::bigDouble(val); // TODO IEEE 754 ??
				buf += sizeof(double);
			}
			break;
		case 'f':
			{
				float val = va_arg(vaArgs, float);
				*(float *)buf = Endian::bigFloat(val); // TODO IEEE 754 ??
				buf += sizeof(float);
			}
			break;
		case 't':
			{
				char *str = va_arg(vaArgs, char *);
				size_t len = strlen(str);

				*(short *)buf = ntohs(len);
				buf += sizeof(short);

				wchar_t *wbuf = (wchar_t *)buf;
				wchar_t *tmp = new wchar_t[len + 1];
				mbstowcs_s(&len, tmp, len + 1, str, len);
				--len; // strip 0x0000
				for (size_t k = 0; k < len; ++k)
				{
					//wbuf[k] = (wchar_t)ShortSwap((short)tmp[k]);
					wbuf[k] = (wchar_t)htons((short)tmp[k]);
				}
				delete[] tmp;
				buf += len * sizeof(wchar_t);
			}
			break;
		}
	}
	va_end(vaArgs);

	//assert(buf - buf2 == bytes);

	SendBuf(buf2, bytes, 0);
	free(buf2);

	return bytes;
}

void VanillaClient::OnRead()
{
	// OnRead of TcpSocket actually reads the data from the socket
	// and moves it to the input buffer (ibuf)
	TcpSocket::OnRead();

	// get number of bytes in input buffer
	size_t iSize = ibuf.GetLength();
	if (iSize > 0)
	{
		char tmp[TCP_BUFSIZE_READ];
		ibuf.Read(tmp, iSize);

		try
		{
			m_pPacketParser->parseInput(tmp, iSize);
			onData(tmp, iSize);
		}
		catch (PacketParser::Exception ex)
		{
			printf("PacketParser::Exception (packet id 0x%02X, last ok 0x%02X)\n", ex.m_iPacketId, ex.m_iLastCompletePacket);
			getchar();
		}
	}
}
