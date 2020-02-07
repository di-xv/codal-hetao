#include "HeTao.h"

HeTao ht;

int main() {
    ht.init();

    codal::Pin led_mosi(ID_2812, PB_8, PIN_CAPABILITY_DIGITAL);
    codal::Pin *led_miso = NULL;
    codal::Pin *led_sclk = NULL;
    ZSPI_LED led(led_mosi, *led_miso, *led_sclk);

    uint64_t k = 0;

    led.show(0, 15, 15, 0, false);
    fiber_sleep(2000);

    for (int j = 0; j < 8; j += 3) {
        led.show(j, 15, 0, 0);
        led.show(j + 1, 0, 15, 0);
        led.show(j + 2, 0, 0, 15, false);
        fiber_sleep(5000);
    }

//  int state = 0;
//  while (1) {
//    ht.io.led.setDigitalValue(state);
//    fiber_sleep(1000);
//    state = !state;
//  }

    while (1) {
        uint64_t m = k % 8;
        led.show(m, 0, 0, 0);
        k++;
        m = k % 8;
        led.show(m, 15, 15, 15, false);
        fiber_sleep(1000);
    }
}
