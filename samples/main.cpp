#include "HeTao.h"

HeTao bp;

// LED SPI BUFFER
uint8_t buf_bytes[] = {0x88, 0x8E, 0xE8, 0xEE};
uint8_t txBuffer[8*3*4];
uint32_t txSize = 8*3*4;

void show(int id, uint8_t red, uint8_t green, uint8_t blue, ZSPI &led) {
    if (id < 8) {
        uint8_t mask = 0x03;
        int index = id * 12;
        txBuffer[index] = buf_bytes[green >> 6 & mask];
        txBuffer[index + 1] = buf_bytes[green >> 4 & mask];
        txBuffer[index + 2] = buf_bytes[green >> 2 & mask];
        txBuffer[index + 3] = buf_bytes[green & mask];

        txBuffer[index + 4] = buf_bytes[red >> 6 & mask];
        txBuffer[index + 5] = buf_bytes[red >> 4 & mask];
        txBuffer[index + 6] = buf_bytes[red >> 2 & mask];
        txBuffer[index + 7] = buf_bytes[red & mask];

        txBuffer[index + 8] = buf_bytes[blue >> 6 & mask];
        txBuffer[index + 9] = buf_bytes[blue >> 4 & mask];
        txBuffer[index + 10] = buf_bytes[blue >> 2 & mask];
        txBuffer[index + 11] = buf_bytes[blue & mask];
    }

    led.transfer(txBuffer, txSize, rxBuffer, rxSize);
}

int main() {
    bp.init();

    int state = 0;

    codal::Pin led_mosi(ID_LED, PB_8, PIN_CAPABILITY_DIGITAL);
    codal::Pin *led_miso = NULL;
    codal::Pin *led_sclk = NULL;
    ZSPI led(led_mosi, *led_miso, *led_sclk);

    led.setFrequency(3200000);

    uint64_t k = 0;

    while (1) {
        uint64_t m = k % 8;
        show(m, 0, 0, 0, led);
        k++;
        m = k % 8;
        show(m, 15, 15, 15, led);
        fiber_sleep(10000);
        state = !state;
    }
}
