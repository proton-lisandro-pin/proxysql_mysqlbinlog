#include <ctime>
#include <cstdio>
#include <cstdarg>

#include "log.h"

void log(int level, const char *fmt, ...) {
	time_t timer;
	struct tm *tm_info;
	static char tstr[25];

	char *levelstr;
	switch (level) {
	case LOGLEVEL_INFO:
		levelstr = (char*)"INFO";
		break;
	case LOGLEVEL_ERROR:
		levelstr = (char *)"ERROR";
		break;
	default:
		levelstr = (char *)"DEFAULT";
	}

	time(&timer);
	tm_info = localtime(&timer);
	strftime(tstr, 25, "%Y-%m-%d %H:%M:%S", tm_info); \

	va_list ap;
	va_start(ap, fmt);
	fprintf(stderr, "%s [%s] ", tstr, levelstr);
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");

	va_end(ap);
};