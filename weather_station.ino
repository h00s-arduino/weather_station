#include <DHT.h>
#include <Wire.h>
#include <BMP085.h>

#define DHT22_PIN 2

BMP085 bmp = BMP085();
DHT22 dht;

void setup(void) {
  Serial.begin(9600);
  Wire.begin();
  dht.setup(2);
  delay(2000);
  
  bmp.init(MODE_ULTRA_HIGHRES, 19000, true);
}

void loop(void) {
  int dht_temperature = -1000;
  int dht_humidity = -1000;
  long bmp_temperature = -1000;
  long bmp_pressure = -1000;
  byte data;
  
  delay(5000);
  
  dht_temperature = dht.getTemperature();
  dht_humidity = dht.getHumidity();
  
  bmp.getPressure(&bmp_pressure);
  bmp.getTemperature(&bmp_temperature);
  
  if (Serial.available() > 0) {
    while(Serial.available() > 0) {
      data = Serial.read();
    }
    Serial.print(dht_temperature);
    Serial.print("|");
    Serial.print(dht_humidity);
    Serial.print("|");
    Serial.print(bmp_temperature);
    Serial.print("|");
    Serial.println(bmp_pressure);    
  }

}
