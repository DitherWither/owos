#include "terminal.h"
#include "font.h"
#include "util.h"
#include <limine.h>
#include <stdint.h>
#include <stddef.h>

// The Limine requests can be placed anywhere, but it is important that
// the compiler does not optimise them away, so, usually, they should
// be made volatile or equivalent.

static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

struct limine_framebuffer *term_fb = NULL;

int cursor_x = 0;
int cursor_y = 0;

void terminal_init(void) {
    // Ensure we got a framebuffer.
    if (framebuffer_request.response == NULL
     || framebuffer_request.response->framebuffer_count < 1) {
        hcf();
    }

    // Fetch the first framebuffer.
    term_fb = framebuffer_request.response->framebuffers[0];
    terminal_clear();
}


void terminal_draw_pixel(int x, int y, int color) {
    uint32_t *fb_ptr = (uint32_t*) term_fb->address;
    fb_ptr[x + (term_fb->pitch / 4) * y] = color;
}

void terminal_draw_rect(int x, int y, int height, int width, int color) {
    uint32_t *fb_ptr = (uint32_t*) term_fb->address;
    uint64_t y_multiplier = term_fb->pitch / 4;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fb_ptr[(x + j) + y_multiplier * (y + i)] = color;
        }
    }
}

void terminal_clear(void) {
    int height = term_fb->height;
    int width = term_fb->width;

    cursor_x = 0;
    cursor_y = 0;

    terminal_draw_rect(0, 0, height, width, TERM_BACKGROUND_COLOR);
}

void terminal_print_char(int x, int y, char letter) {
    const uint8_t* letter_character = font_get_char(letter);

    for (int j = 0; j < (FONT_CHAR_WIDTH - 1); j++) {
        for (int i = 0; i < (FONT_CHAR_HEIGHT); i++) {
            if (letter_character[j] & (1 << i)) {
                terminal_draw_rect( (x + j * FONT_SIZE_MULTIPLIER),  (y + i * FONT_SIZE_MULTIPLIER), FONT_SIZE_MULTIPLIER, FONT_SIZE_MULTIPLIER, TERM_FOREGROUND_COLOR);
            }
        }
    }

}

void terminal_write_string(const char* str) {
    while (*str) {
        if (*str == '\n') {
            cursor_y += FONT_CHAR_WIDTH * FONT_SIZE_MULTIPLIER + 1;
            cursor_x = 0;
            str++;
            continue;
        }

        terminal_print_char(cursor_x, cursor_y, *str);
        str++;
        cursor_x += FONT_CHAR_WIDTH * FONT_SIZE_MULTIPLIER;
    }
}