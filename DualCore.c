#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "pico/multicore.h"


void blink1() {
    const uint LEFT_LED_PIN = 2;
    gpio_init(LEFT_LED_PIN);
    gpio_set_dir(LEFT_LED_PIN, GPIO_OUT);
    while(1) {
        gpio_put(LEFT_LED_PIN, 1);
        printf("Core 1 blink\n");
        sleep_ms(50);
        gpio_put(LEFT_LED_PIN, 0);
        sleep_ms(450);
    }
}

void blink2() {
    const uint RIGHT_LED_PIN = 16;
    gpio_init(RIGHT_LED_PIN);
    gpio_set_dir(RIGHT_LED_PIN, GPIO_OUT);
    while(1) {
        gpio_put(RIGHT_LED_PIN, 1);
        printf("Core 2 blink\n");
        sleep_ms(50);
        gpio_put(RIGHT_LED_PIN, 0);
        sleep_ms(250);
    }
}

int main()
{
    stdio_init_all();
    multicore_launch_core1(blink1);
    blink2();


    return 0;
}
