#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>
#include <DHT.h>

#define DHTPIN 3
#define DHTTYPE DHT11
#define rainSensorPin A0

DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(9600);
  dht.begin();
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    while (1) {}
  }
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float p = bmp.readPressure() / 100.0F;
  int rainSensorValue = analogRead(rainSensorPin);

  if (isnan(h) || isnan(t) || isnan(p)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C\t");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Pressure: ");
  Serial.print(p);
  Serial.print(" hPa\t");
  Serial.print("Rain Sensor Value: ");
  Serial.println(rainSensorValue);

  delay(2000);
}
