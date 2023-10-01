#ifndef FONT_H
#define FONT_H

#include <stdint.h>

#define FONT_CHAR_WIDTH 8
#define FONT_CHAR_HEIGHT 8
#define FONT_SIZE_MULTIPLIER 2

const uint8_t* font_get_char(char c); 

#endif