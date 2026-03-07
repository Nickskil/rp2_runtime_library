#include <stdio.h>
#include "hal/led/led.h"
#include "hal/i2c/i2c.h"
#include "peri/oled_4400/ssd1306.h"


int main(){   
    // Init Phase
    static i2c_rp2_t i2c_mod = {
        .pin_sda = 0,
        .pin_scl = 1,
        .i2c_mod = i2c0,
        .fi2c_khz = 100,
        .avai_devices = 0,
        .init_done = false
    };
    scan_i2c_bus_for_device(&i2c_mod);

    init_default_led();
    stdio_init_all();
    sleep_ms(3000);

    // Pre-Phase
    static ssd1306_t oled = {
        .i2c_mod = &i2c_mod,
        .render_area = NULL,
        .init_done = false
    };
    if(ssd1306_init(&oled)) {
        printf("SSD1306 Initialized Successfully!\n");
    } else {
        printf("Failed to Initialize SSD1306. Check I2C connection.\n");
    }
    set_state_default_led(true);

    // Main Loop
    while (true) {  
        sleep_ms(1000);
        printf("Hello, World!\n");
        toggle_state_default_led();
    }
}