#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 7, 6);

const int power = 8;
const int red = 4;
const int green = 3;

const int x = A1;
const int y = A3;
const int joystickButtonPin = 2;

int threshold = 600; 
int sensorValue;
int joystickValue;

const int deadzoneMin = 450; 
const int deadzoneMax = 550;
const int adjustmentAmount = 10;
const unsigned long adjustmentDelay = 300;
unsigned long lastAdjustmentTime = 0;

void setup() {

  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(power, OUTPUT);
  pinMode(red, OUTPUT); //maybe will remove these from circuit as they are primarily for testing when motor should be on
  pinMode(green, OUTPUT);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Starting");
  delay(2000); 
  lcd.clear();
  
}

void loop() {

  digitalWrite(power, HIGH); 
  delay(10); 
  sensorValue = analogRead(A0);
  digitalWrite(power, LOW); 
  
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);
  
  lcd.setCursor(0, 0);
  lcd.print("Threshold: ");
  lcd.print(threshold);
  
  lcd.setCursor(0, 1);
  lcd.print("Value: ");
  lcd.print(sensorValue);
  lcd.print("       ");
  
  if (sensorValue < threshold) { 
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
  } else { 
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
  }
  
  delay(100); 
  
  joystickValue = analogRead(x);
  Serial.print("Joystick X value: ");
  Serial.println(joystickValue);
  
  if (millis() - lastAdjustmentTime > adjustmentDelay) {
    /*
    deadzone is a range of small left/right joystick movements,
    needs to read greater than the deadzone to prevent accidental input
    */

    if (joystickValue > deadzoneMax) {
      threshold += adjustmentAmount;
      if (threshold > 1000) threshold = 1000;
      lastAdjustmentTime = millis();
      updateThreshold();
      Serial.println("Threshold increased");
    }
    
    if (joystickValue < deadzoneMin) {
      threshold -= adjustmentAmount;
      if (threshold < 0) threshold = 0;
      lastAdjustmentTime = millis();
      updateThreshold();
      Serial.println("Threshold decreased");
    }
  }
}

void updateThreshold() {
  lcd.setCursor(10, 0);
  lcd.print("        ");
  lcd.setCursor(10, 0);
  lcd.print(threshold);
  
  if (joystickValue > deadzoneMax) {
    lcd.setCursor(15, 0);
    lcd.print("<");
  }
  else if (joystickValue < deadzoneMin) {
    lcd.setCursor(15, 0);
    lcd.print(">");
  }
  else {
    lcd.setCursor(15, 0);
    lcd.print(" ");
  }
}
