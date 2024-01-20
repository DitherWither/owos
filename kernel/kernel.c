#include <stdint.h>
#include <stddef.h>
#include <limine.h>
#include <stdio.h>
#include <font.h>
#include <memory.h>
#include <util.h>
#include <terminal.h>
#include <stb_sprintf.h>


// The following will be our kernel's entry point.
// If renaming _start() to something else, make sure to change the
// linker script accordingly.
void _start(void) {
    terminal_init();

    // terminal_draw_diagonal();
    printf("Hello, World!\nThis is a new line\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }

    // We're done, just hang...
    hcf();
}
