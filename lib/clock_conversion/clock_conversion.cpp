#include <stdio.h>
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