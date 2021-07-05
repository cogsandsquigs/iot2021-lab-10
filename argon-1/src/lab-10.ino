#include <Wire.h>

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