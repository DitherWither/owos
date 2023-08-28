#include "util.h"

void hcf(void) {
    asm ("cli");
    for (;;) {
        asm ("hlt");
    }
}