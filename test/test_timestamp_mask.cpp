#include <gtest/gtest.h>
#include <stdio.h>
#include <clock_conversion.h>
// uncomment line below if you plan to use GMock
// #include <gmock/gmock.h>

// TEST(...)
// TEST_F(...)

TEST(timestamp_mask, convertTimestampToMask) {
  // given
  const uint32_t time = 1704706621;

  // when
  const uint32_t mask_actual = getTimestampMask(time);

  // then
  //                       YYRYYRYOOOOYYOO
  EXPECT_EQ(mask_actual, 0b111111100001100);
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
