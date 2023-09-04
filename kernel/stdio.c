#include "stdio.h"
#include "terminal.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <wchar.h>
#include <string.h>

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