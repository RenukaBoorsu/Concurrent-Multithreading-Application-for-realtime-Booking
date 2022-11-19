#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
void log_print(char* filename,char* func, int line, char *fmt,...);
#define LOG_PRINT(...) log_print(__FILE__,__func__, __LINE__, __VA_ARGS__ )
#define LOG_INFO(message, args...)      LOG_PRINT(LOG_FMT message NEWLINE, ## args)