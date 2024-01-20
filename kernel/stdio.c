#include <stdio.h>
#include <terminal.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <wchar.h>
#include <string.h>
#include <stdarg.h>
#define STB_SPRINTF_IMPLEMENTATION
// TODO add float support
#define STB_SPRINTF_NOFLOAT
#include <stb_sprintf.h>

// It is safe to assume that we will never exceed this number
// TODO: replace this with a proper allocation once we get memory management
static char printf_buf[4096] = { 0 };

int putchar(int c) {
    char str[2] = {(char)c, 0x00};

    // Calling terminal_write_string is simpler
    // than getting the position, and then calling write char
    terminal_write_string(str);

    return 0;
}

int puts(const char *s) {
    terminal_write_string(s);

    return 0;
}

int sprintf(char* buf, const char* fmt, ...) {
    va_list ap;

    va_start(ap, fmt);
    return stbsp_vsprintf(buf, fmt, ap);
}

int printf(const char* fmt, ...) {
    va_list ap;

    va_start(ap, fmt);
    int res = stbsp_vsnprintf(printf_buf, 4096, fmt, ap);
    va_end(ap);
    
    puts(printf_buf);
    return res;
}