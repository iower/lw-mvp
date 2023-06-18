#include <EEPROM.h>
#include <Wire.h>
#include "libs/LiquidCrystal_I2C/LiquidCrystal_I2C.cpp"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println(EEPROM.length());

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("TEST");
  lcd.setCursor(0, 1);
  lcd.print("LCD 1602");
}

int address = 0;
char value;

void loop() {
  for (;;) {
    Serial.println();
    Serial.print("lw-message-[");
    Serial.print(millis());
    Serial.print("]");
    Serial.println();
    delay(1000);
  }

  Serial.println("read...");

  lcd.setCursor(0, 1);
  lcd.print(millis()/1000);

  Serial.println("read...");
  for (address = 0; address < EEPROM.length(); address++) {
    value = EEPROM.read(address);
    Serial.print(address);
    Serial.print("\t");
    Serial.print(value, DEC);
    Serial.println();
  }

  delay(3000);
  exit(0);

  Serial.println("write...");
  for (address = 0; address < EEPROM.length(); address++) {
    value = address % 8;
    EEPROM.update(address, value);
  }
  Serial.println("updated");

  delay(1000);
  Serial.println("exit");
  exit(0);
}
