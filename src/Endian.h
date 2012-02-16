class Endian;

#ifndef _ENDIANNN_H
#define _ENDIANNN_H

class Endian
{
private:
	Endian();

public:
	static void init();

	static short (*bigShort) (short s);
	static short (*littleShort) (short s);
	static int (*bigLong) (int i);
	static int (*littleLong) (int i);
	static float (*bigFloat) (float f);
	static float (*littleFloat) (float f);
	static double (* bigDouble) (double d);
};

#endif
