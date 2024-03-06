#include <Arduino.h>
#include <Wire.h>

#define I2C_SLAVE_ADDRESS 0x4

void setup()
{
    Wire.begin();
    Serial.begin(115200);
}

uint16_t get_adc_value()
{
    uint16_t adc_value = 0;

    Wire.requestFrom(I2C_SLAVE_ADDRESS, 1);
    while (Wire.available())
    {
        adc_value = Wire.read();
    }

    delayMicroseconds(10);

    Wire.requestFrom(I2C_SLAVE_ADDRESS, 1);
    while (Wire.available())
    {
        adc_value |= Wire.read() << 8;
    }

    return adc_value;
}

void loop()
{
    uint16_t adc_value = get_adc_value();

    Serial.println(adc_value, HEX);

    delay(1000);
}
