#ifndef _STDINC_H
#define _STDINC_H

#include <stdio.h>

#ifdef WIN32

#include "misc/windows.h"

#else

#include "misc/linux.h"

#endif

#define ntohll(x) (((__int64)(ntohl((int)((x << 32) >> 32))) << 32) | (unsigned int)ntohl(((int)(x >> 32))))
#define htonll(x) ntohll(x)

#endif
