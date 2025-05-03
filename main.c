#include <stdio.h>
#include "pico/stdlib.h"

__attribute__((section(".noinit"))) static uint32_t scratch_magic;
__attribute__((section(".noinit"))) static uint32_t scratch_count;

#define MAGIC_BABB 0x0000BABB

void check_reboot_counter() {
    printf("Initial MAGIC: 0x%08lX  COUNT: %lu\n", scratch_magic, scratch_count);

    if (scratch_magic == MAGIC_BABB) {
        scratch_count++;
    } else {
        scratch_magic = MAGIC_BABB;
        scratch_count = 1;
    }

    printf("After update:  MAGIC: 0x%08lX  COUNT: %lu\n", scratch_magic, scratch_count);
}

int main() {
    stdio_init_all();
    sleep_ms(3000);

    check_reboot_counter();

    for (int i = 5; i > 0; i--) {
        printf("Rebooting in %d...\n", i);
        sleep_ms(1000);
    }

    watchdog_enable(1, 1); // force watchdog reset
    while (1);
}
