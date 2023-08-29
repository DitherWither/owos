#ifndef TERMINAL_H
#define TERMINAL_H

#define TERM_FOREGROUND_COLOR 0xffff00
#define TERM_BACKGROUND_COLOR 0x0000ff

void terminal_init(void);
void terminal_print_char(int x, int y, char letter);
void terminal_write_string(const char* str, int x, int y);
void terminal_draw_rect(int x, int y, int height, int width, int color);
void terminal_clear(void);

#endif