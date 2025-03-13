#include <Arduino.h>

int red = D0;
int yellow = D3;
int green = D4;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  digitalWrite(red, LOW);
  digitalWrite(red, HIGH);
  delay(1000);
  digitalWrite(yellow, HIGH);
  delay(2000);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  delay(3000);
  digitalWrite(green, LOW);
}

