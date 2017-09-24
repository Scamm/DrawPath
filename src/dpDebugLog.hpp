#ifndef __DP_DEBUGLOG_HPP__
#define __DP_DEBUGLOG_HPP__

#include "windows.h"
#include <cstdio>

#define LOG(fmt, ...) output(fmt, ##__VA_ARGS__)

#ifdef _DEBUG
inline void output(const char* format, ...) {
	char buff[1024];
	va_list arg;
	va_start(arg, format);
	_vsnprintf_s(buff, sizeof(buff), format, arg);
	va_end(arg);

	OutputDebugStringA(buff);
	OutputDebugStringA("\n");
}
#else
inline void output(const char* format, ...) {}
#endif

#endif
