const int sensorPin = A0;      // Analog input from LM358 output 
const int servoPin = 9;        // Servo control pin
const int ledPin = 8;          // Watering indication LED

const int lowerThreshold = 812;  // Lower ADC threshold - very dry soil
const int upperThreshold = 818;  // Upper ADC threshold - wet soil

#include <Servo.h>
Servo valveServo;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  valveServo.attach(servoPin);
  valveServo.write(0); // Valve closed at start
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  int wateringStatus = 0; // 0 = off, 1 = on

  if (sensorValue < lowerThreshold) {
    // Soil dry, open valve and turn LED ON
    valveServo.write(90);
    digitalWrite(ledPin, HIGH);
    wateringStatus = 1;
  } 
  else if (sensorValue > upperThreshold) {
    // Soil wet, close valve and turn LED OFF
    valveServo.write(0);
    digitalWrite(ledPin, LOW);
    wateringStatus = 0;
  } 
  else {
    // Moderate moisture — keep valve off
    valveServo.write(0);
    digitalWrite(ledPin, LOW);
    wateringStatus = 0;
  }

  // 👉 Send data in "moisture,status" format
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.println(wateringStatus);

  delay(5000); // Delay between readings
}
