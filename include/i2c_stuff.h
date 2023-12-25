#pragma once
#ifndef i2c_stuff_H
#define i2c_stuff_H

#include <Arduino.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/***************************************************************************/

namespace I2C_STUFF
{

  void i2c_scan()
  {
    int nDevices = 0;

    Serial.println("Scanning...");

    for (byte address = 1; address < 127; ++address)
    {
      // The i2c_scanner uses the return value of
      // the Wire.endTransmission to see if
      // a device did acknowledge to the address.
      Wire.beginTransmission(address);
      byte error = Wire.endTransmission();

      if (error == 0)
      {
        Serial.print("I2C device found at address 0x");
        if (address < 16)
        {
          Serial.print("0");
        }
        Serial.print(address, HEX);
        Serial.println("  !");

        ++nDevices;
      }
      else if (error == 4)
      {
        Serial.print("Unknown error at address 0x");
        if (address < 16)
        {
          Serial.print("0");
        }
        Serial.println(address, HEX);
      }
    }
    if (nDevices == 0)
    {
      Serial.println("No I2C devices found\n");
    }
    else
    {
      Serial.println("done, " + String(nDevices) + " device(s) found.\n");
    }
  } // i2c_scan
} // namespace I2C_STUFF

#endif // define i2c_stuff.h