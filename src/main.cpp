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

// WIFI, NTP
#include "wifi.h"
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

const char *ssid = SECRET_SSID;
const char *password = SECRET_WIFI_PASSWORD;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

void setup()
{
    Serial.begin(115200);
    Serial.print(F("Hello codefreeze!"));

    // initialize LED digital pin as an output.
    pinMode(GPIO_MINUTE_BIT_0, OUTPUT);
    pinMode(GPIO_MINUTE_BIT_1, OUTPUT);
    pinMode(GPIO_MINUTE_BIT_2, OUTPUT);
    pinMode(GPIO_MINUTE_BIT_3, OUTPUT);
    pinMode(D0, OUTPUT);

    // const long utcOffsetInSeconds = 3600 * 2;

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    WiFiUDP ntpUDP;
    NTPClient timeClient(ntpUDP, "pool.ntp.org");

    timeClient.begin();
}

uint32_t retrieve_minutes()
{
    return timeClient.getMinutes();
}

void loop()
{
    timeClient.update();
    const uint32_t minutes = retrieve_minutes();
    const uint32_t timestampMinutesMask = convertTimestampToMinuteBits(minutes * 60);

    const uint32_t timestampMask = getTimestampMask(minutes * 60);
    

    if (TEST_VARIABLE == 0)
    {
      digitalWrite(D0, HIGH);
    }
    
    // turn the LED on (HIGH is the voltage level)
    digitalWrite(GPIO_MINUTE_BIT_0, timestampMinutesMask & 0b1000);
    digitalWrite(GPIO_MINUTE_BIT_1, timestampMinutesMask & 0b0100);
    digitalWrite(GPIO_MINUTE_BIT_2, timestampMinutesMask & 0b0010);
    digitalWrite(GPIO_MINUTE_BIT_3, timestampMinutesMask & 0b0001);

    // wait for a second
    delay(1000);
}