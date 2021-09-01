// ----------------------------------------------------------------------------
// AT42QT2120.h
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef AT42QT2120_H
#define AT42QT2120_H
#include "AT42QT.h"


class AT42QT2120 : public AT42QT
{
public:
  static const uint8_t DEVICE_ADDRESS = 0x1C;
  static const uint8_t CHIP_ID = 0x3E;

  AT42QT2120(TwoWire & wire=Wire,
    int8_t change_pin=-1,
    int8_t reset_pin=-1);

  union Status
  {
    struct
    {
      uint32_t any_key : 1;
      uint32_t slider : 1;
      uint32_t space0 : 4;
      uint32_t overflow : 1;
      uint32_t calibrating : 1;
      uint32_t keys: 12;
      uint32_t space1 : 12;
    };
    uint32_t bytes;
  };
  Status getStatus();
  bool calibrating();

  uint8_t getSliderPosition();

  void triggerCalibration();

  void reset();

  // each interval is 16ms
  // an interval_count of 4 equals 16ms*4=64ms between measurements
  // power down device by writing a zero interval_count
  // wake device by resetting or writing a nonzero interval_count
  uint8_t getMeasurementIntervalCount();
  void setMeasurementIntervalCount(uint8_t interval_count);
private:
  enum struct RegisterAddresses
  {
    CHIP_ID = 0,
    FIRMWARE_VERSION,
    DETECTION_STATUS,
    KEY_STATUS,
    SLIDER_POSITION = 5,
    CALIBRATE,
    RESET,
    LOW_POWER_MODE,
    TOWARDS_TOUCH_DRIFT_COMPENSATION,
    AWAY_TOUCH_DRIFT_COMPENSATION,
    DETECTION_INTEGRATOR,
    TOUCH_RECAL_DELAY,
    DRIFT_HOLD_TIME,
    SLIDER_OPTION,
    CHARGE_TIME,
    KEY0_DTHR,
    KEY1_DTHR,
    KEY2_DTHR,
    KEY3_DTHR,
    KEY4_DTHR,
    KEY5_DTHR,
    KEY6_DTHR,
    KEY7_DTHR,
    KEY8_DTHR,
    KEY9_DTHR,
    KEY10_DTHR,
    KEY11_DTHR,	
    KEY0_CTRL,
    KEY1_CTRL,
    KEY2_CTRL,
    KEY3_CTRL,
    KEY4_CTRL,
    KEY5_CTRL,
    KEY6_CTRL,
    KEY7_CTRL,
    KEY8_CTRL,
    KEY9_CTRL,
    KEY10_CTRL,
    KEY11_CTRL,	
    KEY0_PULSE_SCALE,
    KEY1_PULSE_SCALE,
    KEY2_PULSE_SCALE,
    KEY3_PULSE_SCALE,
    KEY4_PULSE_SCALE,
    KEY5_PULSE_SCALE,
    KEY6_PULSE_SCALE,
    KEY7_PULSE_SCALE,
    KEY8_PULSE_SCALE,
    KEY9_PULSE_SCALE,
    KEY10_PULSE_SCALE,
    KEY11_PULSE_SCALE,
    KEY0_SIGNAL,
    KEY1_SIGNAL = 54,
    KEY2_SIGNAL = 56,
    KEY3_SIGNAL = 58,
    KEY4_SIGNAL = 60,
    KEY5_SIGNAL = 62,
    KEY6_SIGNAL = 64,
    KEY7_SIGNAL = 66,
    KEY8_SIGNAL = 68,
    KEY9_SIGNAL = 70,
    KEY10_SIGNAL = 72,
    KEY11_SIGNAL = 74,	
    KEY0_REFERENCE = 76,
    KEY1_REFERENCE = 78,
    KEY2_REFERENCE = 80,
    KEY3_REFERENCE = 82,
    KEY4_REFERENCE = 84,
    KEY5_REFERENCE = 86,
    KEY6_REFERENCE = 88,
    KEY7_REFERENCE = 90,
    KEY8_REFERENCE = 92,
    KEY9_REFERENCE = 94,
    KEY10_REFERENCE = 96,
    KEY11_REFERENCE = 98,	
  };

};

#endif
