// ----------------------------------------------------------------------------
// AT42QT.cpp
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#include "AT42QT.h"


AT42QT::AT42QT(uint8_t device_address,
  uint8_t chip_id,
  TwoWire & wire,
  int8_t reset_pin) :
device_address_(device_address),
chip_id_(chip_id),
wire_ptr_(&wire),
reset_pin_(reset_pin)
{
  if(reset_pin_ >= 0)
  {
    pinMode(reset_pin_, OUTPUT);
    digitalWrite(reset_pin_, HIGH);
  }
}

void AT42QT::begin()
{
  wire_ptr_->begin();
}

void AT42QT::hardReset()
{
  if(reset_pin_ < 0) return;
  digitalWrite(reset_pin_, LOW);
  delay(1);
  digitalWrite(reset_pin_, HIGH);
}

uint8_t AT42QT::getChipId()
{
  uint8_t chip_id;
  read(CHIP_ID_REGISTER_ADDRESS,chip_id);
  return chip_id;
}

bool AT42QT::communicating()
{
  uint8_t chip_id = getChipId();
  return chip_id == chip_id_;
}

