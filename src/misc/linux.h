#ifndef _LINUX_H
#define _LINUX_H

#include <stdlib.h>
#include <stdint.h>

typedef int64_t __int64;
typedef unsigned long DWORD;

int wcstombs_s(size_t *outsize, char *mbstr, size_t inbytes, const wchar_t *wcstr, size_t max);
int mbstowcs_s(size_t *outsize, wchar_t *wcstr, size_t inwords, const char *mbstr, size_t max);

#ifndef FD_TO_HANDLE
# define FD_TO_HANDLE(fd) (fd)
#endif
#ifndef HANDLE_TO_FD
# define HANDLE_TO_FD(handle) (handle)
#endif

#endif

