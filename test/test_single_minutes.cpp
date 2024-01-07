#include <gtest/gtest.h>
#include <stdio.h>
// uncomment line below if you plan to use GMock
// #include <gmock/gmock.h>

// TEST(...)
// TEST_F(...)

#if defined(ARDUINO)
#include <Arduino.h>

void setup()
{
    // should be the same value as for the `test_speed` option in "platformio.ini"
    // default value is test_speed=115200
    Serial.begin(115200);

    ::testing::InitGoogleTest();
    // if you plan to use GMock, replace the line above with
    // ::testing::InitGoogleMock();
}

void loop()
{
  // Run tests
  if (RUN_ALL_TESTS())
  ;

  // sleep for 1 sec
  delay(1000);
}


#else

uint32_t convertTimestampToMinuteBits(uint32_t timestamp) {
  uint32_t seconds_since_last_full_hour = timestamp % 3600;
  std::cout <<  "DEBUG:" << seconds_since_last_full_hour << "\n";
  uint32_t minutes_since_last_full_hour = seconds_since_last_full_hour / 60;
  std::cout <<  "DEBUG:" << minutes_since_last_full_hour << "\n";
  uint32_t single_minutes_row_value = minutes_since_last_full_hour % 5;
  std::cout <<  "DEBUG:" << single_minutes_row_value << "\n";
  uint32_t minute_bits = 0;
  for(int i = 0; i < single_minutes_row_value; i++) {
    minute_bits |= (0b1000 >> i);
  }
  return minute_bits;
}

TEST(single_minutes, convertUnixMidnightToMinuteBits) {
  // given
  uint32_t midnight = 1704578400;

  // when
  uint32_t minutes_actual = convertTimestampToMinuteBits(midnight);

  // then
  EXPECT_EQ(minutes_actual, 0);
}

TEST(single_minutes, convertUnixOneSecondToMidnightToMinuteBits) {
  uint32_t one_second_to_midnight = 1704578399;

  uint32_t minutes_actual = convertTimestampToMinuteBits(one_second_to_midnight);

  EXPECT_EQ(minutes_actual, 0b1111);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    // if you plan to use GMock, replace the line above with
    // ::testing::InitGoogleMock(&argc, argv);

    if (RUN_ALL_TESTS())
    ;

    // Always return zero-code and allow PlatformIO to parse results
    return 0;
}
#endif
