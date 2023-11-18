#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
uint8_t counter = 0;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("Engenharia Biomedica");

}

void loop() {
  while (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  while (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(2000);
  counter = counter > 254 ? 0 : counter+1;
  SerialBT.println( "Temperatura: "+ String(counter) );
}
