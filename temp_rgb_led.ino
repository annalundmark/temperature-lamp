#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

int redPin = 9; 
int greenPin = 10; 
int bluePin = 11; 

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");

  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
  
  float t = dht.readTemperature();


  // Check if any reads failed and exit early (to try again).
  if (isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  
  setColor(255, 0, 0); 

}

void setColor(int red, int green, int blue) 
{
  red = 255 - red; 
  green = 255 - green; 
  blue = 255 - blue; 
  analogWrite(redPin, red); 
  analogWrite(greenPin, green); 
  analogWrite(bluePin, blue); 
}
