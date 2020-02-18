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

/**
  * Class definition for MicroBit NEXT IO.
  * Represents a collection of all I/O pins on the device.
  */

#include "CodalConfig.h"
#include "HeTaoIO.h"

using namespace codal;

/**
  * Constructor.
  *
  * Create a representation of all given I/O pins on the edge connector
  *
  * Accepts a sequence of unique ID's used to distinguish events raised
  * by MicroBitPin instances on the default EventModel.
  */
HeTaoIO::HeTaoIO() :
        mute(ID_PIN_MUTE, PA_0, PIN_CAPABILITY_DIGITAL),
        ttl_tx(ID_TTL_TX, PA_2, PIN_CAPABILITY_AD),
        ttl_rx(ID_TTL_RX, PA_3, PIN_CAPABILITY_AD),
        lcd_rst(ID_LCD_RST, PB_1, PIN_CAPABILITY_DIGITAL),
        scl(ID_SCL, PB_6, PIN_CAPABILITY_DIGITAL),
        sda(ID_SDA, PB_7, PIN_CAPABILITY_DIGITAL),
        led(ID_LED, PD_2, PIN_CAPABILITY_DIGITAL),
        pwr_on(ID_PWR_ON, PB_12, PIN_CAPABILITY_DIGITAL),
        pwr_key(ID_PWR_KEY, PB_13, PIN_CAPABILITY_DIGITAL),
        plugin(ID_PLUGIN, PB_14, PIN_CAPABILITY_DIGITAL),
        btn0(ID_BTN0, PC_0, PIN_CAPABILITY_DIGITAL),
        btn1(ID_BTN1, PC_1, PIN_CAPABILITY_DIGITAL),
        btn2(ID_BTN2, PC_2, PIN_CAPABILITY_DIGITAL),
        btn3(ID_BTN3, PC_3, PIN_CAPABILITY_DIGITAL),
        btn4(ID_BTN4, PC_4, PIN_CAPABILITY_DIGITAL),
        btn5(ID_BTN5, PC_5, PIN_CAPABILITY_DIGITAL),
        btn6(ID_BTN6, PC_6, PIN_CAPABILITY_DIGITAL),
        btn7(ID_BTN7, PC_7, PIN_CAPABILITY_DIGITAL),
        btn8(ID_BTN8, PC_8, PIN_CAPABILITY_DIGITAL),
        btn9(ID_BTN9, PC_9, PIN_CAPABILITY_DIGITAL),
        btn10(ID_BTN10, PC_10, PIN_CAPABILITY_DIGITAL),
        btn11(ID_BTN11, PC_11, PIN_CAPABILITY_DIGITAL),
        btn12(ID_BTN12, PC_12, PIN_CAPABILITY_DIGITAL),
        btn13(ID_BTN13, PC_13, PIN_CAPABILITY_DIGITAL),
        btn14(ID_BTN14, PC_14, PIN_CAPABILITY_DIGITAL),
        btn15(ID_BTN15, PC_15, PIN_CAPABILITY_DIGITAL),

        buttonUp(ID_BTN1, PC_1, PIN_CAPABILITY_DIGITAL),
        buttonLeft(ID_BTN8, PC_8, PIN_CAPABILITY_DIGITAL),
        buttonDown(ID_BTN9, PC_9, PIN_CAPABILITY_DIGITAL),
        buttonRight(ID_BTN10, PC_10, PIN_CAPABILITY_DIGITAL),

        // for spi led
//        spi_led_pin(ID_2812, PB_8, PIN_CAPABILITY_DIGITAL),

        // for jacdac
        tx(ID_PIN_P32, PA_9, PIN_CAPABILITY_AD) // purple - TX
{

}
