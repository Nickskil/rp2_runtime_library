#include <stdio.h>
#include "hal/led/led.h"

int main(){   
    // Init Phase
    init_default_led(); 
    stdio_init_all();
    sleep_ms(3000);

    // Pre-Phase
    set_state_default_led(true);
    printf("a\n");

    // Main Loop
    while (true) {  
        sleep_ms(1000);
        printf("Hello, World!\n");
        toggle_state_default_led();
    }
}