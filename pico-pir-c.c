#include "pico/stdlib.h"

#define PIR_PIN 17
#define LIGHT_PIN 16

void initialize_pir() {
    gpio_init(PIR_PIN);
    gpio_set_dir(PIR_PIN, GPIO_IN);
}

bool movement_detected() {
    return gpio_get(PIR_PIN);
}

void initialize_light() {
    gpio_init(LIGHT_PIN);
    gpio_set_dir(LIGHT_PIN, GPIO_OUT);
}

void turn_light_on(bool on) {
    gpio_put(LIGHT_PIN, on);
}

int main()
{
    stdio_init_all();

    initialize_pir();
    initialize_light();

    turn_light_on(true);
    sleep_ms(50);
    turn_light_on(false);
    sleep_ms(50);
    turn_light_on(true);
    sleep_ms(50);
    turn_light_on(false);
    sleep_ms(50);
    turn_light_on(true);
    sleep_ms(50);
    turn_light_on(false);
    sleep_ms(50);

    while (true) {
        if (movement_detected()) {
            turn_light_on(true);
        } else {
            turn_light_on(false);
        }
        sleep_ms(1000);
    }
}
