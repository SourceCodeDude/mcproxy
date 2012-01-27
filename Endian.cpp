#include "StdInc.h"
#include "Endian.h"
#include <stdio.h>

short (* Endian::bigShort) (short s);
short (* Endian::littleShort) (short s);
int (* Endian::bigLong) (int i);
int (* Endian::littleLong) (int i);
float (* Endian::bigFloat) (float f);
float (* Endian::littleFloat) (float f);
double (* Endian::bigDouble) (double f);

short ShortSwap( short s )
{
	unsigned char b1, b2;

	b1 = s & 255;
	b2 = (s >> 8) & 255;

	return (b1 << 8) + b2;
}

short ShortNoSwap( short s )
{
	return s;
}

int LongSwap (int i)
{
	unsigned char b1, b2, b3, b4;

	b1 = i & 255;
	b2 = ( i >> 8 ) & 255;
	b3 = ( i>>16 ) & 255;
	b4 = ( i>>24 ) & 255;

	return ((int)b1 << 24) + ((int)b2 << 16) + ((int)b3 << 8) + b4;
}

int LongNoSwap( int i )
{
	return i;
}

float FloatSwap( float f )
{
	union
	{
		float f;
		unsigned char b[4];
	} dat1, dat2;

	dat1.f = f;
	dat2.b[0] = dat1.b[3];
	dat2.b[1] = dat1.b[2];
	dat2.b[2] = dat1.b[1];
	dat2.b[3] = dat1.b[0];
	return dat2.f;
}

float FloatNoSwap( float f )
{
	return f;
}

double DoubleSwap(double d)
{
	union
	{
		double d;
		unsigned char b[8];
	} dat1, dat2;

	dat1.d = d;
	dat2.b[0] = dat1.b[7];
	dat2.b[1] = dat1.b[6];
	dat2.b[2] = dat1.b[5];
	dat2.b[3] = dat1.b[4];
	dat2.b[4] = dat1.b[3];
	dat2.b[5] = dat1.b[2];
	dat2.b[6] = dat1.b[1];
	dat2.b[7] = dat1.b[0];
	return dat2.d;
}

void Endian::init()
{
	char SwapTest[2] = { 1, 0 };

	if (*(short *)SwapTest == 1)
	{
		//printf("We're little endian\n");
		bigShort = ShortSwap;
		littleShort = ShortNoSwap;
		bigLong = LongSwap;
		littleLong = LongNoSwap;
		bigFloat = FloatSwap;
		littleFloat = FloatNoSwap;
		bigDouble = DoubleSwap;
	}
	else
	{
		//printf("We're big endian\n");
		bigShort = ShortNoSwap;
		littleShort = ShortSwap;
		bigLong = LongNoSwap;
		littleLong = LongSwap;
		bigFloat = FloatSwap;
		littleFloat = FloatNoSwap;
		bigDouble = DoubleSwap;
	}
}
