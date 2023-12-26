#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

/*********************************************************/
namespace Globals
{
   /** Constants **/
   const int DEVICE_ID = 0x0a; // Change this to the ID of this device
   const char DEVICE_NAME[] = "Old Timer R3";
   const int BAUD_RATE = 9600;

   void whoIam()
   {
      // Display the microcontroller's information to the serial monitor
      Serial.println("Device Name: " + String(DEVICE_NAME));
      Serial.println("CPU: " + String(__AVR_ARCH__));
      Serial.println("Clock Speed: " + String(F_CPU));
      Serial.println("ARDUINO: " + String(ARDUINO));
      Serial.println("ARDUINO_AVR_UNO: " + String(ARDUINO_AVR_UNO));
      Serial.println();
      Serial.flush();
   }
}

#endif // GLOBALS_H
