// ----------------------------------------------------------------------------
// AT42QT.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef AT42QT_DEFINITIONS_H
#define AT42QT_DEFINITIONS_H


template<typename T>
void AT42QT::write(DeviceAddress device_address,
  uint8_t register_address,
  T data)
{
  int byte_count = sizeof(data);
  wire_ptr_->beginTransmission((uint8_t)device_address);
  wire_ptr_->write(register_address);
  for (int byte_n=0; byte_n<byte_count; ++byte_n)
  {
    wire_ptr_->write((data >> (BITS_PER_BYTE * byte_n)) & BYTE_MAX);
  }
  wire_ptr_->endTransmission();
}

template<typename T>
void AT42QT::read(DeviceAddress device_address,
  uint8_t register_address,
  T & data)
{
  int byte_count = sizeof(data);
  wire_ptr_->beginTransmission((uint8_t)device_address);
  wire_ptr_->write(register_address);
  wire_ptr_->endTransmission(false);

  wire_ptr_->requestFrom(device_address,byte_count);
  data = 0;
  for (int byte_n=0; byte_n<byte_count; ++byte_n)
  {
    data |= (wire_ptr_->read()) << (BITS_PER_BYTE * byte_n);
  }
}

#endif
