#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include "clock_conversion.h"

uint32_t convertTimestampToMinuteBits(uint32_t timestamp) {
  uint32_t seconds_since_last_full_hour = timestamp % 3600;
  uint32_t minutes_since_last_full_hour = seconds_since_last_full_hour / 60;
  uint32_t single_minutes_row_value = minutes_since_last_full_hour % 5;
  uint32_t minute_bits = 0;
  for(int i = 0; i < single_minutes_row_value; i++) {
    minute_bits |= (0b1000 >> i);
  }
  return minute_bits;
}

uint32_t convertTimestampToFiveMinuteBits(uint32_t timestamp) {
  uint32_t seconds_since_last_full_hour = timestamp % 3600;
  uint32_t minutes_since_last_full_hour = seconds_since_last_full_hour / 60;
  uint32_t fiveMinutesRowValue = minutes_since_last_full_hour / 5;
  uint32_t fiveMinuteBits = 0;
  for (int i = 0; i < fiveMinutesRowValue; i++)
  {
    fiveMinuteBits |= (0b10000000000 >> i);
  }
  
  return fiveMinuteBits;
}

uint32_t getTimestampMask(uint32_t minutes) {
  uint32_t timestampMinutesMask = convertTimestampToMinuteBits(minutes);
  uint32_t timestampFiveMinutesMask = convertTimestampToFiveMinuteBits(minutes);

  return (timestampFiveMinutesMask << 4) | timestampMinutesMask;
}