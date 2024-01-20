#ifndef STDIO_H
#define STDIO_H

#include <terminal.h>

#include <stdarg.h>

int putchar(int c);
int puts(const char *s);
int sprintf(char* buf, const char* fmt, ...);
int printf(const char* fmt, ...);

#endif