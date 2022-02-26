//Beetech yazılım hizmetleri 
//kalibre edilmiş sistem kodu
#include "HX711.h"

#define CLK 5
#define DOUT 4
#define calibration_factor 25,94
HX711 scale;

int resetPin = 10;
float weight;

void setup() {
  Serial.begin(9600);
  pinMode(resetPin, INPUT);
  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor);
  scale.tare();                           
}

void loop() {
  weight = scale.get_units();
  Serial.print("Agirlik:");
  Serial.print(weight);
  Serial.println("  Kg");
  if(digitalRead(resetPin) ==1){
    scale.tare();     
  }
  scale.power_down();            
  delay(1500);
  
  scale.power_up(); 
}
