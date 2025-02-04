#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos para os LEDs RGB
#define PIN_ledR 13
#define PIN_ledB 12
#define PIN_ledG 11

// Variável de controle para alternar entre os LEDs
static volatile uint16_t estado = 0;

// Função para inicializar os pinos dos LEDs
void inicializa();

// Função de callback chamada pelo timer repetitivo
bool rrepeating_timer_callback(struct repeating_timer *t){
    static bool led_on = true; // Estado do LED
    
    // Alternância do LED baseado na variável de estado
    if(estado == 0){
        gpio_put(PIN_ledR, led_on);
        gpio_put(PIN_ledG, 0);
        gpio_put(PIN_ledB, 0);
        printf("led vermelho %s\n", led_on ? "Ligado" : "Desligado");
        estado = 1; // Muda para o próximo estado
        return true;
    }
    if(estado == 1){
        gpio_put(PIN_ledR, 0);
        gpio_put(PIN_ledG, 0);
        gpio_put(PIN_ledB, led_on);
        printf("led azul %s\n", led_on ? "Ligado" : "Desligado");
        estado = 2; // Muda para o próximo estado
        return true;
    }
    if(estado == 2){
        gpio_put(PIN_ledR, 0);
        gpio_put(PIN_ledG, led_on);
        gpio_put(PIN_ledB, 0);
        printf("led verde %s\n", led_on ? "Ligado" : "Desligado");
        estado = 0; // Retorna ao primeiro estado
        return true;
    }
}

int main()
{
    stdio_init_all(); // Inicializa o sistema de entrada e saída padrão
    inicializa(); // Configura os pinos dos LEDs

    struct repeating_timer timer;
    // Configura um timer para chamar a função de callback a cada 3 segundos
    add_repeating_timer_ms(3000, rrepeating_timer_callback, NULL, &timer);

    // Loop infinito que imprime uma mensagem a cada 1 segundo
    while (true) {
        printf("Passou 1 segundo!\n");
        sleep_ms(1000);
    }
}

// Função para inicializar os pinos dos LEDs
void inicializa(){
    gpio_init(PIN_ledR);
    gpio_set_dir(PIN_ledR, GPIO_OUT);
    gpio_init(PIN_ledG);
    gpio_set_dir(PIN_ledG, GPIO_OUT);
    gpio_init(PIN_ledB);
    gpio_set_dir(PIN_ledB, GPIO_OUT);
}
