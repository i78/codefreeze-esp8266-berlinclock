/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"
#include <stdio.h>
#include <clock_conversion.h>
#include "hal.h"

#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#endif

void setup()
{
    // initialize LED digital pin as an output.
    pinMode(GPIO_MINUTE_BIT_0, OUTPUT);
    pinMode(GPIO_MINUTE_BIT_1, OUTPUT);
    pinMode(GPIO_MINUTE_BIT_2, OUTPUT);
    pinMode(GPIO_MINUTE_BIT_3, OUTPUT);
}

void loop()
{
    const int32_t fakeTimestamp = 1704540720;
    const int32_t timestampMask = convertTimestampToMinuteBits(fakeTimestamp);

    // turn the LED on (HIGH is the voltage level)
    digitalWrite(GPIO_MINUTE_BIT_0, timestampMask & 0b1000);
    delay(30);
    digitalWrite(GPIO_MINUTE_BIT_1, timestampMask & 0b0100);
    delay(30);
    digitalWrite(GPIO_MINUTE_BIT_2, timestampMask & 0b0010);
    delay(30);
    digitalWrite(GPIO_MINUTE_BIT_3, timestampMask & 0b0001);

    // wait for a second
    delay(100);

    // turn the LED off by making the voltage LOW
    digitalWrite(GPIO_MINUTE_BIT_0, LOW);    
    digitalWrite(GPIO_MINUTE_BIT_1, LOW);
    digitalWrite(GPIO_MINUTE_BIT_2, LOW);    
    digitalWrite(GPIO_MINUTE_BIT_3, LOW);

    // wait for a second
    delay(100);
}