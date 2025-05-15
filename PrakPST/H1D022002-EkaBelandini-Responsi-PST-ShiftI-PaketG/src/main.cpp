#include <Arduino.h>

int trigPin = D0;
int echoPin = D1;
int ledPeringatan = D2; // yang merah
int ledAman = D3;       // yang hijau

long duration;
long distance;

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(ledPeringatan, OUTPUT);
  pinMode(ledAman, OUTPUT);
  
  digitalWrite(ledPeringatan, LOW);
  digitalWrite(ledAman, LOW);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = 0.034 * duration / 2;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 10) {
    digitalWrite(ledPeringatan, HIGH); // LED merah nyala
    digitalWrite(ledAman, LOW);
  } else {
    digitalWrite(ledPeringatan, LOW);
    digitalWrite(ledAman, HIGH);       // LED hijau nyala
  }

  delay(1000); // di cek ulang tiap 1 detik
}