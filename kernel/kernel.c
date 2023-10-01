#include <stdint.h>
#include <stddef.h>
#include <limine.h>
#include "stdio.h"
#include "font.h"
#include "memory.h"
#include "util.h"
#include "terminal.h"

// The following will be our kernel's entry point.
// If renaming _start() to something else, make sure to change the
// linker script accordingly.
void _start(void) {
    terminal_init();

    // terminal_draw_diagonal();
    puts("Hello, World!\n\nThis is a new line");

    // We're done, just hang...
    hcf();
}
