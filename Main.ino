#include <Servo.h>

Servo yaw;
Servo artikulazioa1;
Servo artikulazioa2;
Servo pinza;

int pos = 0;

int repetizioak = 0;

void setup() {
  yaw.attach(8);
  artikulazioa1.attach(9);
  artikulazioa2.attach(10);
  pinza.attach(11);
  Serial.begin(9600);
  Serial.println("Mugimendua hasita");
  repeticiones = 0;
  delay(7000);
}

void loop() {
  while (repetizioak > 7) {
    delay(5000);
    
    yawAurreraka();
    aurreraInklinatu();
    pinzatu();
    atzeraInklinatu();
    yawAtzera();
    aurreraInklinatu();
    pinzatu();
    atzeraInklinatu();
    
    Serial.println(repetizioak);
    repetizioak++;
  }
}

void aurreraInklinatu() {
  for (pos = 2; pos <= 70; pos += 1) {
    artikulazioa1.write(pos);
    artikulazioa2.write(pos);
    delay(15);
  }
  delay(200);
}

void atzeraInklinatu() {
  for (pos = 70; pos >= 2; pos -= 1) {
    artikulazioa1.write(pos);
    artikulazioa2.write(pos);
    delay(15);
  }
  delay(200);
}

void pinzatu() {
  for (pos = 0; pos <= 30; pos += 1) {
    pinza.write(pos);
    delay(15);
  }
  delay(100);
  
  for (pos = 30; pos >= 0; pos -= 1) {
    pinza.write(pos);
    delay(15);
  }
  delay(200);
}

void yawAurreraka() {
  for (pos = 2; pos <= 190; pos += 1) {
    yaw.write(pos);
    delay(15);
  }
  delay(200);
}

void yawAtzeraka() {
  for (pos = 190; pos >= 2; pos -= 1) {
    yaw.write(pos);
    delay(15);
  }
  delay(200);
}
