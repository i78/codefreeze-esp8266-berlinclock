#include <gtest/gtest.h>
#include <stdio.h>
#include <clock_conversion.h>
// uncomment line below if you plan to use GMock
// #include <gmock/gmock.h>

// TEST(...)
// TEST_F(...)

TEST(five_minute_row, convertUnixMidnightToFiveMinuteBits) {
  // given
  const uint32_t midnight = 1704578400;

  // when
  const uint32_t minutes_actual = convertTimestampToFiveMinuteBits(midnight);

  // then
  EXPECT_EQ(minutes_actual, 0);
}

TEST(five_minute_row, convertUnixOneSecondToMidnightToFiveMinuteBits) {
  // given
  const uint32_t oneSecondToMidnight = 1704578399;

  // when
  const uint32_t minutes_actual = convertTimestampToFiveMinuteBits(oneSecondToMidnight);

  // then
  EXPECT_EQ(minutes_actual, 0b11111111111);
}

TEST(five_minute_row, convertUnixFourMinutesPastNoonToFiveMinuteBits) {
  // given
  const uint32_t fourMinutesPastNoon = 1704708240;

  // when
  const uint32_t minutes_actual = convertTimestampToFiveMinuteBits(fourMinutesPastNoon);

  // then
  EXPECT_EQ(minutes_actual, 0);
}

TEST(five_minute_row, convertUnixTwentyThreeMinutesPastNoonToFiveMinuteBits) {
  // given
  const uint32_t twnetyThreeMinutesPastNoon = 1704709380;

  // when
  const uint32_t minutes_actual = convertTimestampToFiveMinuteBits(twnetyThreeMinutesPastNoon);

  // then
  EXPECT_EQ(minutes_actual, 0b11110000000);
}

TEST(five_minute_row, convertUnixThirtyFiveMinutesPastNoonToFiveMinuteBits) {
  // given
  const uint32_t thrityFiveMinutesPastNoon = 1704710100;

  // when
  const uint32_t minutes_actual = convertTimestampToFiveMinuteBits(thrityFiveMinutesPastNoon);

  // then
  EXPECT_EQ(minutes_actual, 0b11111110000);
}

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
0b1111
  // sleep for 1 sec
  delay(1000);
}


#else

#endif
