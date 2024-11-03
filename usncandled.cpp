#include <NewPing.h>
#include <Servo.h>

const int ledM = 13;
const int ledB = 12;
const int ledH = 11;
Servo mesin;
NewPing sensor(4, 2, 400);
int jarak;

void setup() {
  mesin.attach(8);
  pinMode(ledM, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledH, OUTPUT);
}

void loop() {
  jarak = sensor.ping_cm();
  
  if (jarak % 2 == 0 && jarak % 3 != 0 && jarak % 7 != 0) {
    digitalWrite(ledM, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledH, LOW);
    mesin.write(20);
  }
  else if (jarak % 3 == 0 && jarak % 2 != 0 && jarak % 7 != 0) {
    digitalWrite(ledM, LOW);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledH, LOW);
    mesin.write(30);
  }
  else if (jarak % 7 == 0 && jarak % 3 != 0 && jarak % 2 != 0) {
    digitalWrite(ledM, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledH, HIGH);
    mesin.write(70);
  }
  else if (jarak % 2 == 0 && jarak % 3 == 0 && jarak % 7 != 0) {
    digitalWrite(ledM, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledH, LOW);
    mesin.write(50);
  }
  else if (jarak % 2 != 0 && jarak % 3 != 0 && jarak % 7 != 0) {
    digitalWrite(ledM, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledH, LOW);
    mesin.write(0);
  }
  
  delay(500);
}