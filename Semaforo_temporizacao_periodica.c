#include <stdio.h>
#include "pico/stdlib.h"

#define LED_VERDE 13//LED verde 
#define LED_AMARELO 12//LED verde 
#define LED_VERMELHO 11//LED vermelho 

bool repeating_timer_callback(struct repeating_timer *t);
static volatile int cont=0; 
int main()
{
    stdio_init_all();
    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO,GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE,GPIO_OUT);
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO,GPIO_OUT);

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    gpio_put(LED_VERMELHO,true);
    while(true){
        sleep_ms(100);
        printf("Processador ocupado em outra tarefa\n");
    }
    return 0;

}

bool repeating_timer_callback(struct repeating_timer *t) {
    if(cont == 0){
      gpio_put(LED_VERDE,false);
      gpio_put(LED_VERMELHO,true);
      cont++;
    }
    else if(cont == 1){
      gpio_put(LED_VERMELHO,false);
      gpio_put(LED_AMARELO,true);
      cont++;
    }
    else if(cont == 2){
      gpio_put(LED_VERDE,true);
      gpio_put(LED_AMARELO,false);
      cont++;
    }
    else if(cont == 3){
      cont = 0;
    }
    return true;
}