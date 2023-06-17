#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println(EEPROM.length());
}

int address = 0;
char value;

void loop() {
  Serial.println("read...");
  for (address = 0; address < EEPROM.length(); address++) {
    value = EEPROM.read(address);
    Serial.print(address);
    Serial.print("\t");
    Serial.print(value, DEC);
    Serial.println();
  }

  delay(3000);
  Serial.println("write...");
  for (address = 0; address < EEPROM.length(); address++) {
    value = address % 8;
    EEPROM.write(address, value);
  }
  Serial.println("writed");

  delay(1000);
  Serial.println("exit");
  exit(0);
}
