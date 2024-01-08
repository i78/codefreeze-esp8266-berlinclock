#include <gtest/gtest.h>
#include <stdio.h>
#include <clock_conversion.h>
// uncomment line below if you plan to use GMock
// #include <gmock/gmock.h>

// TEST(...)
// TEST_F(...)

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
