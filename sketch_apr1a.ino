#include "DHT.h"
#include "Adafruit_BMP085.h"

#define pin1 13
#define pin2 32

DHT dht1(pin1, DHT11);   //Azul
DHT dht2(pin2, DHT22);   //Blanco

Adafruit_BMP085 bmp;

void setup() {
  Serial.being(115200);
  Serial.println("Test de sensores: ");

  dht1.being();
  dht2.being();

  bmp.being();
}

void loop() {
  
  delay(2000);
  leerdht1();

  delay(2000);
  leerdht2();

  delay(2000);
  leerbmp();

}

void leerdht1(){

  float t1= dht1.readTemperature();
  float h1= dht1.readHumidity();

  while(isnan(t1) || isnan(h1))
  {
    Serial.println("Lectura fallida en el sensor DHT11, repitiendo la lectura...");
    delay(2000);
    t1= dht1.readTemperature();
    h1= dht1.readHumidity();
  }

  Serial.print("Temperatura DHT1: ");
  Serial.print(t1);
  Serial.println(" C ");

  Serial.print("Humedad DHT1: ");
  Serial.print(h1);
  Serial.println(" % ");

  Serial.println("----------------");

}

void leerdht2(){

  float t2= dht2.readTemperature();
  float h2= dht2.readHumidity();

  while(isnan(t2) || isnan(h2))
  {
    Serial.println("Lectura fallida en el sensor DHT12, repitiendo la lectura...");
    delay(2000);
    t2= dht1.readTemperature();
    h2= dht1.readHumidity();
  }

  Serial.print("Temperatura DHT2: ");
  Serial.print(t2);
  Serial.println(" C ");

  Serial.print("Humedad DHT2: ");
  Serial.print(h2);
  Serial.println(" % ");

  Serial.println("----------------");

}


void leerbmp(){

  float temp= bmp.readTemperature();
  float presion= bmp.readPressure();
  float altitud= bmp.readAltituted();

}