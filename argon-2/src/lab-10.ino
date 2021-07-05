#include <Wire.h>

SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(MANUAL);

const uint16_t led = D7;
const uint16_t button = D8;

uint response = 0;

void setup()
{
    Serial.begin(9600);

    Wire.begin(0x40);
    Wire.onReceive(receiveEvent);
    Wire.onRequest(requestEvent);

    pinMode(led, OUTPUT);
    pinMode(button, INPUT);
}

void loop()
{
    Serial.printlnf("%d", digitalRead(button));
}

void receiveEvent(int howMany)
{
    char x = Wire.read();
    if (x == '1')
    {
        digitalWrite(led, HIGH);
    }
    else if (x == '0')
    {
        digitalWrite(led, LOW);
    }
    else if (x == '?')
    {
        response = digitalRead(button);
    }
}

void requestEvent()
{
    Wire.write(response);
}
