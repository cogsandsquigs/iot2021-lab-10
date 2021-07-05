/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/home/ianp/Documents/iot2021/labs/lab-10/argon-1/src/lab-10.ino"
#include <Wire.h>

void setup();
void loop();
#line 3 "/home/ianp/Documents/iot2021/labs/lab-10/argon-1/src/lab-10.ino"
SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(MANUAL);

void setup()
{
    Serial.begin(9600);
    while (!Serial.isConnected())
        ;
    Wire.begin();
}

void loop()
{
    if (Serial.available())
    {
        // read the incoming byte:
        char value = Serial.read();
        //Serial.printlnf("new input: %c", value);

        Wire.beginTransmission(0x40);
        Wire.write(value);
        Wire.endTransmission();

        if (value == '?')
        {
            Wire.requestFrom(0x40, 1);
            while (Wire.available() == 0)
                ;
            int data = Wire.read();
            Serial.printlnf("Button input: %d", data);
        }
    }
}