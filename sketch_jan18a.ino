//ukljucimo library
#include <Stepper.h>
#include <LiquidCrystal_I2C.h> 

// definiramo konstante


const int STEPS_PER_REV = 500; // broj koraka pri jenonj rotaciji
const int SPEED_CONTROL = A0;


LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C adresa 0x27, 16 stupaca 2 reda
Stepper stepper(STEPS_PER_REV, 1, 3, 2, 4);
 
void setup() {
  lcd.init(); // inicijaliziramo led
  lcd.backlight();
}
 
void loop() {
  // čitamo vrijednost na potenciometru:
  int sensorReading = analogRead(SPEED_CONTROL);
  // mapiramo ga u rasponu od 0 do 100
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  // brzina motora
  if (motorSpeed > 0) {
    stepper.setSpeed(motorSpeed);
    // korak 1/100 od revolucije
    stepper.step(STEPS_PER_REV / 100);
  }

  lcd.clear();                 // očistimo display
  lcd.setCursor(0, 0);         // cursor pomaknemo na (0,0)
  lcd.print(sensorReading);
}
