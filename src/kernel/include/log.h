#ifndef LOG_H
#define LOG_H

#include <comm/cpu_ins.h>
#include <stdarg.h>
#include <klib.h>

void log_init();
void klog(const char * fmt, ...);

#endif
