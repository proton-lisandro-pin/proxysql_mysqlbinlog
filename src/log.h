#ifndef LOG_H
#define LOG_H

#define LOGLEVEL_INFO   1
#define LOGLEVEL_ERROR  2

void log(int level, const char *fmt, ...);

#define log_info(fmt, ...)   log(LOGLEVEL_INFO, fmt, ## __VA_ARGS__);
#define log_error(fmt, ...)  log(LOGLEVEL_ERROR, fmt, ## __VA_ARGS__);

#endif // LOG_H