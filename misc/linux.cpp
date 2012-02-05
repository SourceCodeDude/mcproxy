#include "StdInc.h"
#include "linux.h"

int wcstombs_s(size_t *outsize, char *mbstr, size_t inbytes, const wchar_t *wcstr, size_t max)
{
	*outsize = wcstombs(mbstr, wcstr, max);
	return 0;
}

int mbstowcs_s(size_t *outsize, wchar_t *wcstr, size_t inwords, const char *mbstr, size_t max)
{
	*outsize = mbstowcs(wcstr, mbstr, max);
	return 0;
}
