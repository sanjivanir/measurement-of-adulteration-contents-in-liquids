#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensorPin = A0;
int greenLED = 7;
int redLED = 6;

//  Calibration values (adjust after testing)
int pureValue = 900;      // value for pure sample
int impureValue = 300;    // value for fully adulterated sample

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  Serial.begin(9600);

  lcd.setCursor(0,0);
  lcd.print("Food Quality");
  lcd.setCursor(0,1);
  lcd.print("System Start");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(sensorPin);

  // Map sensor value to purity %
  int purity = map(sensorValue, impureValue, pureValue, 0, 100);

  // Limit purity between 0–100
  purity = constrain(purity, 0, 100);

  //  Serial Monitor Output
  Serial.print("Sensor: ");
  Serial.print(sensorValue);
  Serial.print("  Purity: ");
  Serial.print(purity);
  Serial.println("%");

  //  LCD Display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Purity: ");
  lcd.print(purity);
  lcd.print("%");

  lcd.setCursor(0, 1);

  //  Classification
  if (purity > 80) {
    lcd.print("PURE");
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
  }
  else if (purity > 60) {
    lcd.print("SLIGHT IMPURE");
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
  }
  else {
    lcd.print("ADULTERATED");
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
  }

  delay(1000);
}
