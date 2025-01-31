#include <stdio.h>
#include "pico/stdlib.h"

#define PIN_ledR 13
#define PIN_ledG 12
#define PIN_ledB 11

void inicializa();

int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}

void inicializa(){
    gpio_init(PIN_ledR);
    gpio_set_dir(PIN_ledR, GPIO_OUT);
    gpio_init(PIN_ledG);
    gpio_set_dir(PIN_ledG, GPIO_OUT);
    gpio_init(PIN_ledB);
    gpio_set_dir(PIN_ledB, GPIO_OUT);

    
    stdio_init_all();
}