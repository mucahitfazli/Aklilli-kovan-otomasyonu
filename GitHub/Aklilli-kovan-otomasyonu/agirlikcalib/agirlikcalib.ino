//Beetech yazılım hizmetleri 
// kalibrasyon değeri belirleme 
#include "HX711.h"
HX711 scale;

#define CLK  5
#define DOUT  4

int calibration_factor = 27700; 

void setup() {
  Serial.begin(9600);
  Serial.println("tartı kalibrasyonu ");
  Serial.println("Tüm ağırlıları tartıdan kaldırın ");

  scale.begin(DOUT, CLK);
  scale.set_scale();
  scale.tare(); //Reset the scale to 0
  
  Serial.println("tartıya ağırlığı bilinen bir nesneyi yerleştirin ");
  Serial.println("Aşağıdaki tuşları kullanarak kalibrasyon faktörünü ayarlayın ");
  Serial.println("'a' or 'z' sırasıyla 100 artırmak veya azaltmak ");
  Serial.println("'s' or 'x' sırasıyla 10 artırmak veya azaltmak ");
  Serial.println("'d' or 'c' sırasıyla 1 artırmak veya azaltmak ");
}

void loop() {
  scale.set_scale(calibration_factor); 
  Serial.print("Okuma: ");
  Serial.print(scale.get_units(), 2);
  Serial.print(" kg"); 
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor);
  Serial.println();
  
  if(Serial.available()){
    char input = Serial.read();
    if(input == 'a'){ calibration_factor += 100; }
    else if(input == 'z'){  calibration_factor -= 100; }
    else if(input == 's'){  calibration_factor += 10; }
    else if(input == 'x'){  calibration_factor -= 10; }
    else if(input == 'd'){  calibration_factor += 1; }
    else if(input == 'c'){  calibration_factor -= 1; }
  }
}
