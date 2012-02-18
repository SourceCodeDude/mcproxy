#ifndef _WINDOWS_H
#define _WINDOWS_H

#include "stdint.h"
#ifndef WIN32_LEAN_AND_MEAN
  #define WIN32_LEAN_AND_MEAN
#endif
#include <winsock2.h>
#include <windows.h>

#ifndef FD_TO_HANDLE
# define FD_TO_HANDLE(fd) _get_osfhandle (fd)
#endif
#ifndef HANDLE_TO_FD
# define HANDLE_TO_FD(handle) _open_osfhandle (handle, 0)
#endif
#include <io.h>

#endif
