#include <stdio.h> //biblioteca padrão da linguagem C
#include "pico/stdlib.h" //subconjunto central de bibliotecas do SDK Pico
#include "hardware/pwm.h" //biblioteca para controlar o hardware de PWM

#define SERVO_PIN 22 //pino do servomotor conectado a GPIO 22
const uint16_t WRAP_PERIOD = 24999; //valor máximo do contador - WRAP para 50Hz (20ms)
const float PWM_DIVISER = 125.0f; //divisor do clock para o PWM (50Hz)
const uint16_t MIN_PULSE_WIDTH = 500; //largura de pulso para 0 graus (500µs)
const uint16_t MAX_PULSE_WIDTH = 2400; //largura de pulso para 180 graus (2400µs)

//função para configurar o módulo PWM
void pwm_setup() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM

    uint slice = pwm_gpio_to_slice_num(SERVO_PIN); //obter o canal PWM da GPIO

    pwm_set_clkdiv(slice, PWM_DIVISER); //define o divisor de clock do PWM
    pwm_set_wrap(slice, WRAP_PERIOD); //definir o valor de wrap para 20ms (50Hz)
    pwm_set_enabled(slice, true); //habilita o PWM no slice correspondente
}

//função para definir o ângulo do servomotor
void set_servo_angle(uint16_t pulse_width) {
    pwm_set_gpio_level(SERVO_PIN, pulse_width); //define o ciclo ativo (largura de pulso)
}

//função principal
int main() {
    stdio_init_all(); //inicializa o sistema padrão de I/O

    pwm_setup(); //configura o PWM para o servomotor

    // Posiciona o servomotor em 180 graus (2400µs)
    set_servo_angle(MAX_PULSE_WIDTH);
    printf("Posição: 180 graus\n");
    sleep_ms(5000); // Aguarda 5 segundos

    // Posiciona o servomotor em 90 graus (1470µs)
    set_servo_angle(1470);
    printf("Posição: 90 graus\n");
    sleep_ms(5000); // Aguarda 5 segundos

    // Posiciona o servomotor em 0 graus (500µs)
    set_servo_angle(MIN_PULSE_WIDTH);
    printf("Posição: 0 graus\n");
    sleep_ms(5000); // Aguarda 5 segundos

    // Movimentação periódica suave entre 0 e 180 graus
    while (true) {
        // Movimentação de 0° a 180°
        for (uint16_t pulse_width = MIN_PULSE_WIDTH; pulse_width <= MAX_PULSE_WIDTH; pulse_width += 5) {
            set_servo_angle(pulse_width);
            sleep_ms(10); // Aguarda 10ms para suavizar a movimentação
        }

        // Movimentação de 180° a 0°
        for (uint16_t pulse_width = MAX_PULSE_WIDTH; pulse_width >= MIN_PULSE_WIDTH; pulse_width -= 5) {
            set_servo_angle(pulse_width);
            sleep_ms(10); // Aguarda 10ms para suavizar a movimentação
        }
    }

    return 0;
}