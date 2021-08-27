// ----------------------------------------------------------------------------
// AT42QT2120.cpp
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#include "../AT42QT2120.h"


AT42QT2120::AT42QT2120(TwoWire & wire,
  int8_t reset_pin) :
AT42QT(DEVICE_ADDRESS,CHIP_ID,wire,reset_pin)
{};

bool AT42QT2120::anyTouched();
