#include <DHT.h>
#include <Grove_Temperature_And_Humidity_Sensor.h>


#include <U8x8lib.h>

U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

DHT dht(3, DHT11);

void setup() {
dht.begin();
u8x8.begin();
u8x8.setFlipMode(1);
u8x8.clear();
}

void loop() {
float temperature = dht.readTemperature();
float humidity = dht.readHumidity();

if (humidity > 70)
{
  tone(5, 700, 300);
}



u8x8.setFont(u8x8_font_chroma48medium8_r);
u8x8.setCursor(0, 0);
u8x8.println(temperature);
u8x8.println(humidity);
}
