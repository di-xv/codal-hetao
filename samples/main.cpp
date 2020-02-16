#include "HeTao.h"
#include "ZI2C.h"
#include "JDMessageBusService.h"

HeTao ht;
JDMessageBusService serialBus;

#define APP_ID 9008

void message_bus_evt(Event e) {
    if (e.value == DEVICE_BUTTON_EVT_DOWN) {
        ht.spi_led.show(0, 15, 0, 0);
    }
    if (e.value == DEVICE_BUTTON_EVT_UP) {
        ht.spi_led.show(0, 0, 15, 0);
    }
}

void button_event(Event e) {
    if (e.value == DEVICE_BUTTON_EVT_DOWN) {
        Event(APP_ID, e.value);
    }
    if (e.value == DEVICE_BUTTON_EVT_UP) {
        Event(APP_ID, e.value);
    }
}

void test_gpio() {
    ht.io.scl.setDigitalValue(1);
    ht.io.sda.setDigitalValue(0);
    ht.io.ttl_tx.setDigitalValue(1);
    ht.io.ttl_rx.setDigitalValue(0);
}

void test_uart() {
    uint8_t recv[100];
    ZSingleWireSerial uart(ht.io.ttl_tx);
    uart.setBaud(115200);
    uart.send((uint8_t *) "hello", 5);
    uart.receive(recv, 5);
}

void test_i2c() {
    uint8_t recv[100];
    ZI2C i2c(ht.io.sda, ht.io.scl);
    i2c.setFrequency(100000);
    i2c.writeRegister(0x12, 0x00, 0x00);
    i2c.readRegister(0x12, 0x00, (uint8_t *) recv, 10);
}

int main() {
    ht.init();

    uint64_t k = 0;

    ht.spi_led.show(0, 15, 15, 0);
    fiber_sleep(2000);

    for (int j = 0; j < 8; j += 3) {
        ht.spi_led.show(j, 15, 0, 0);
        ht.spi_led.show(j + 1, 0, 15, 0);
        ht.spi_led.show(j + 2, 0, 0, 15);
        fiber_sleep(1000);
    }

    for (int j = 0; j < 8; j += 3) {
        ht.spi_led.show(j, 0, 0, 0);
        ht.spi_led.show(j + 1, 0, 0, 0);
        ht.spi_led.show(j + 2, 0, 0, 0);
        fiber_sleep(1000);
    }

    int state = 1;

    ht.messageBus.listen(ht.buttonUp.id, DEVICE_ID_ANY, button_event);
    ht.messageBus.listen(APP_ID, DEVICE_ID_ANY, message_bus_evt);
    serialBus.listen(APP_ID, DEVICE_ID_ANY);
    ht.jacdac.add(serialBus);
    ht.jacdac.start();

    while (1) {
        ht.spi_led.show(7, 0, 0, 15 * state);
        fiber_sleep(500);
        state = !state;
    }

    while (1) {
        uint64_t m = k % 8;
        ht.spi_led.show(m, 0, 0, 0);
        k++;
        m = k % 8;
        ht.spi_led.show(m, 15, 15, 15);
        fiber_sleep(1000);
    }
}
