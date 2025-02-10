#include "pico/stdlib.h"
#include "hardware/pwm.h"


#define PWM_PIN 22 //pino do LED conectado a GPIO como PWM
const uint16_t WRAP_PERIOD = 20000; //valor máximo do contador - WRAP
const float PWM_DIVISER = 125.0; //divisor do clock para o PWM


//função para configurar o módulo PWM
void pwm_setup()
{
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM


    uint slice = pwm_gpio_to_slice_num(PWM_PIN); //obter o canal PWM da GPIO


    pwm_set_clkdiv(slice, PWM_DIVISER); //define o divisor de clock do PWM


    pwm_set_wrap(slice, WRAP_PERIOD); //definir o valor de wrap


    pwm_set_gpio_level(PWM_PIN, 00); //definir o cico de trabalho (duty cycle) do pwm


    pwm_set_enabled(slice, true); //habilita o pwm no slice correspondente
}


int main() {


    stdio_init_all();
    pwm_setup();


    // Requisito 1: Ajuste para 180 graus - 2400µs (~0,12% de Duty Cycle)
    pwm_set_gpio_level(PWM_PIN, 2400);  // 2400µs
    sleep_ms(5000);  // Aguarda 5 segundos


    // Requisito 2: Ajuste para 90 graus - 1470µs (~0,0735% de Duty Cycle)
    pwm_set_gpio_level(PWM_PIN, 1470);  // 1470µs
    sleep_ms(5000);  // Aguarda 5 segundos


    // Requisito 3: Ajuste para 0 graus - 500µs (~0,025% de Duty Cycle)
    pwm_set_gpio_level(PWM_PIN, 500);   // 500µs
    sleep_ms(5000);  // Aguarda 5 segundos


    // Requisito 5: Movimentação suave do servomotor entre 0 e 180 graus
    while (true) {
        // Movimentando de 0 até 180 graus com incremento de ±5µs
        for (int pulse = 500; pulse <= 2400; pulse += 5) {
            pwm_set_gpio_level(PWM_PIN, pulse);  // Ajusta a posição
            sleep_ms(10);  // Atraso de 10ms para suavizar o movimento
        }


        // Movimentando de 180 até 0 graus com incremento de ±5µs
        for (int pulse = 2400; pulse >= 500; pulse -= 5) {
            pwm_set_gpio_level(PWM_PIN, pulse);  // Ajusta a posição
            sleep_ms(10);  // Atraso de 10ms para suavizar o movimento
        }
    }


    return 0;
}
