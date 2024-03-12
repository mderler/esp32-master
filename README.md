# esp32-master

Dieses Repository beinhaltet das PlatformIO Projekt für die I2C Kommunikation auf dem ESP32.

## Flashen

Für das Flashen muss der ESP32 über USB mit dem Gerät verbunden werden. In der __platfromio.ini__ Datei muss noch der richtige USB Port definiert werden.
Danach kann durch PlatformIO der Code zum ESP32 geflashed werden.

## Code

```cpp
void setup()
{
    Wire.begin();          // Aktiviert I2C
    Serial.begin(115200);
}
```

```cpp
uint16_t get_adc_value()
{
    uint16_t adc_value = 0;

    Wire.requestFrom(I2C_SLAVE_ADDRESS, 1);  // Fragt das erste Byte beim ATtiny an.
    while (Wire.available())
    {
        adc_value = Wire.read();
    }

    delayMicroseconds(10);

    Wire.requestFrom(I2C_SLAVE_ADDRESS, 1);  // Fragt das zweite Byte beim ATtiny an.
    while (Wire.available())
    {
        adc_value |= Wire.read() << 8;
    }

    return adc_value;
}
```
