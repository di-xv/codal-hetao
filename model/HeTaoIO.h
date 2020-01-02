/*
The MIT License (MIT)

Copyright (c) 2017 Lancaster University.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifndef HETAO_IO_H
#define HETAO_IO_H

#include "CodalConfig.h"
#include "ZPin.h"
#include "ZSPI.h"

//
// Unique Pin number for each pin (synonymous with mbedos PinName)
//


//
// Component IDs for each pin.
// The can be user defined, but uniquely identify a pin when using the eventing APIs/
//
#define ID_PIN_MUTE     (DEVICE_ID_IO_P0 + 0)
#define ID_PIN_AUDIO    (DEVICE_ID_IO_P0 + 1)
#define ID_TTL_TX       (DEVICE_ID_IO_P0 + 2)
#define ID_TTL_RX       (DEVICE_ID_IO_P0 + 3)
#define ID_U1_DE        (DEVICE_ID_IO_P0 + 4)
#define ID_U1_TX        (DEVICE_ID_IO_P0 + 5)
#define ID_U1_RX        (DEVICE_ID_IO_P0 + 6)
#define ID_LCD_RST      (DEVICE_ID_IO_P0 + 7)
#define ID_SCL          (DEVICE_ID_IO_P0 + 8)
#define ID_SDA          (DEVICE_ID_IO_P0 + 9)
#define ID_LED          (DEVICE_ID_IO_P0 + 10)
#define ID_PWR_ON       (DEVICE_ID_IO_P0 + 11)
#define ID_PWR_KEY      (DEVICE_ID_IO_P0 + 12)
#define ID_PLUGIN       (DEVICE_ID_IO_P0 + 13)
#define ID_BTN0         (DEVICE_ID_IO_P0 + 14)
#define ID_BTN1         (DEVICE_ID_IO_P0 + 15)
#define ID_BTN2         (DEVICE_ID_IO_P0 + 16)
#define ID_BTN3         (DEVICE_ID_IO_P0 + 17)
#define ID_BTN4         (DEVICE_ID_IO_P0 + 18)
#define ID_BTN5         (DEVICE_ID_IO_P0 + 19)
#define ID_BTN6         (DEVICE_ID_IO_P0 + 20)
#define ID_BTN7         (DEVICE_ID_IO_P0 + 21)
#define ID_BTN8         (DEVICE_ID_IO_P0 + 22)
#define ID_BTN9         (DEVICE_ID_IO_P0 + 23)
#define ID_BTN10         (DEVICE_ID_IO_P0 + 24)
#define ID_BTN11         (DEVICE_ID_IO_P0 + 25)
#define ID_BTN12         (DEVICE_ID_IO_P0 + 26)
#define ID_BTN13         (DEVICE_ID_IO_P0 + 27)
#define ID_BTN14         (DEVICE_ID_IO_P0 + 28)
#define ID_BTN15         (DEVICE_ID_IO_P0 + 29)

namespace codal {
/**
 * Represents a collection of all I/O pins exposed by the device.
 */
class HeTaoIO {
public:

    ZPin mute;
    ZPin ttl_tx;
    ZPin ttl_rx;
    ZPin lcd_rst;
    ZPin scl;
    ZPin sda;
    // use ZSPI swap ZPin
    //    ZPin led;
    ZPin pwr_on;
    ZPin pwr_key;
    ZPin plugin;
    ZPin btn0;
    ZPin btn1;
    ZPin btn2;
    ZPin btn3;
    ZPin btn4;
    ZPin btn5;
    ZPin btn6;
    ZPin btn7;
    ZPin btn8;
    ZPin btn9;
    ZPin btn10;
    ZPin btn11;
    ZPin btn12;
    ZPin btn13;
    ZPin btn14;
    ZPin btn15;

    ZPin buttonUp;
    ZPin buttonDown;
    ZPin buttonLeft;
    ZPin buttonRight;

    /**
     * Constructor.
     */
    HeTaoIO();
};
}

#endif
