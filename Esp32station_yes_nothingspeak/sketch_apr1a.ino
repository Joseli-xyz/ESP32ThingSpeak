#include "DHT.h"
#include "Adafruit_BMP085.h"
#include "ThingSpeak.h"
#include "WiFi.h"

#define pin1 13
#define pin2 32

const char* ssid ="HUAWEI-2.4G-t8Dt";
const char* password= "d737M7s8";

unsigned long channelID= 2499263;
const char* WriteAPIKey="BG1OQDPVK7RC19WF";

WiFiClient Client; 

DHT dht1(pin1, DHT11);  //Azul


Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(115200);
  Serial.println("Test de sensores: ");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Wifi Conectado");
  ThingSpeak.begin(Client);


  dht1.begin();

}

void loop() {

  delay(2000);
  leerdht1();

  ThingSpeak.writeFields(channelID, WriteAPIKey);
  Serial.println("Datos Enviados a ThingSpeak");
  delay(14000);
}

void leerdht1() {

  float t1 = dht1.readTemperature();
  float h1 = dht1.readHumidity();

  while (isnan(t1) || isnan(h1)) {
    Serial.println("Lectura fallida en el sensor DHT11, repitiendo la lectura...");
    delay(2000);
    t1 = dht1.readTemperature();
    h1 = dht1.readHumidity();
  }

  Serial.print("Temperatura DHT1: ");
  Serial.print(t1);
  Serial.println(" C ");

  Serial.print("Humedad DHT1: ");
  Serial.print(h1);
  Serial.println(" % ");

  Serial.println("----------------");

  ThingSpeak.setField(1, t1);
  ThingSpeak.setField(2, h1);
}

/*
void leerdht2() {

  float t2 = dht2.readTemperature();
  float h2 = dht2.readHumidity();

  while (isnan(t2) || isnan(h2)) {
    Serial.println("Lectura fallida en el sensor DHT12, repitiendo la lectura...");
    delay(2000);
    t2 = dht1.readTemperature();
    h2 = dht1.readHumidity();
  }

  Serial.print("Temperatura DHT2: ");
  Serial.print(t2);
  Serial.println(" C ");

  Serial.print("Humedad DHT2: ");
  Serial.print(h2);
  Serial.println(" % ");

  Serial.println("----------------");
}
*/

/*

void leerbmp() {

  float temp = bmp.readTemperature();
  float presion = bmp.readPressure();
  float altitud = bmp.readAltitude();
}

*/