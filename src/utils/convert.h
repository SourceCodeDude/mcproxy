#ifndef _CONVERT_H
#define _CONVERT_H

#ifdef WIN32
#include "../winiconv/iconv.h"
#else
#include <iconv.h>
#endif

int convert(iconv_t iv, char* input, size_t inlen, char** output, size_t* outlen);

#endif

