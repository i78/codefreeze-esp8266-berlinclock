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
    // initialize LED digital pin as an output.
    pinMode(GPIO_MINUTE_BIT_0, OUTPUT);
    pinMode(GPIO_MINUTE_BIT_1, OUTPUT);
    pinMode(GPIO_MINUTE_BIT_2, OUTPUT);
    pinMode(GPIO_MINUTE_BIT_3, OUTPUT);

    
    const long utcOffsetInSeconds = 3600 * 2;

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    WiFiUDP ntpUDP;
    NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

    timeClient.begin();
}

uint32_t retrieve_ntp_time()
{
    return timeClient.getEpochTime();    
}

void loop()
{
    const int32_t fakeTimestamp = retrieve_ntp_time();
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
    delay(1000);
}