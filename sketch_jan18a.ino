#include <Stepper.h>
#include <LiquidCrystal_I2C.h> 
// Define Constants


 
// Number of steps per output rotation
const int STEPS_PER_REV = 500;
const int SPEED_CONTROL = A0;


LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
Stepper stepper(STEPS_PER_REV, 1, 3, 2, 4);
 
void setup() {
  // nothing to do inside the void setup
  lcd.init(); // initialize the lcd
  lcd.backlight();
}
 
void loop() {
  // read the sensor value:
  int sensorReading = analogRead(SPEED_CONTROL);
  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  // set the motor speed:
  if (motorSpeed > 0) {
    stepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    stepper.step(STEPS_PER_REV / 100);
  }

  lcd.clear();                 // clear display
  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print(sensorReading);
}
