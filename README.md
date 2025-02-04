# Controle de LEDs RGB com Raspberry Pi Pico

Este projeto demonstra o uso da Raspberry Pi Pico para alternar entre três LEDs coloridos (vermelho, azul e verde) usando um temporizador repetitivo.

## Componentes necessários
- Raspberry Pi Pico
- LEDs (vermelho, azul e verde)
- Resistores apropriados (220Ω recomendados)
- Protoboard e jumpers

## Funcionamento
O código alterna entre três LEDs, acendendo um de cada vez em um intervalo de 3 segundos. Ele usa um temporizador repetitivo para realizar essa alternância e imprime no terminal qual LED está ativo. Além disso, uma mensagem informativa é exibida a cada 1 segundo no console.

### Pinos utilizados:
- **LED Vermelho:** GPIO 13
- **LED Azul:** GPIO 12
- **LED Verde:** GPIO 11

## Estrutura do código
- **inicializa():** Configura os pinos dos LEDs como saída.
- **rrepeating_timer_callback():** Alterna os LEDs de acordo com um estado cíclico.
- **main():** Inicializa o sistema e configura o timer repetitivo para chamar a função de callback a cada 3 segundos.

## Como usar
1. Conecte os LEDs aos pinos correspondentes na Raspberry Pi Pico.
2. Compile e carregue o código na placa utilizando um ambiente de desenvolvimento compatível (exemplo: Raspberry Pi Pico SDK com CMake e GCC).
3. Abra um terminal serial para visualizar as mensagens de status.

## Dependências
O código utiliza as bibliotecas padrão do Raspberry Pi Pico:
- `stdio.h`
- `pico/stdlib.h`
- `hardware/timer.h`

Certifique-se de ter o SDK do Raspberry Pi Pico configurado corretamente antes da compilação.

## Exemplo de saída no terminal
```
Passou 1 segundo!
Passou 1 segundo!
led vermelho Ligado
Passou 1 segundo!
Passou 1 segundo!
led azul Ligado
Passou 1 segundo!
Passou 1 segundo!
led verde Ligado
```

## Autor
DIEGO MICKAEL DE SÁ PEREIRA

## Licença
Este código é de livre uso e modificação.

