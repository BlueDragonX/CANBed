#ifndef _CANNY_DETECT_H_
#define _CANNY_DETECT_H_

#include <Arduino.h>

// Guess the CANBed board based on the microcontroller in use. It is assumed
// that this library is only used for actual Canny devices. It doesn't appear
// as if there's a way to directly detect whether or not a Longan board is in
// use vs, for example, a regular Arduino Leonardo or P2040.

// CANBed V1
#if defined(ARDUINO_AVR_LEONARDO)
#include "Canny/MCP2515.h"
namespace Canny {
MCP2515 can_mcp2515(17);
}
::Canny::Controller& CAN = ::Canny::can_mcp2515;

// CANBed M4
#elif defined(ARDUINO_SAMD_VARIANT_COMPLIANCE)
#include "Canny/SAME51.h"
namespace Canny {
SAME51 can_same51;
}
::Canny::Controller& CAN = ::Canny::can_same51;

// CANBed RP2040 and Dual.
#elif defined(RASPBERRYPI_PICO)
#include "Canny/MCP2518.h"
#include "Canny/MCP2515.h"
namespace Canny {
MCP2518 can_mcp2518(12);
MCP2515 can_mcp2515(9);
}
::Canny::Controller& CAN = ::Canny::can_mcp2518;
::Canny::Controller& CAN1 = ::Canny::can_mcp2515;

#endif

#endif  // _CANNY_DETECT_H_
