#ifndef CLOCK_CONVERSION_H
#define CLOCK_CONVERSION_H

#include <stdio.h>
#include <iostream>

uint32_t convertTimestampToMinuteBits(uint32_t timestamp);
uint32_t convertTimestampToFiveMinuteBits(uint32_t timestamp);
uint32_t getTimestampMask(uint32_t minutes);

#endif