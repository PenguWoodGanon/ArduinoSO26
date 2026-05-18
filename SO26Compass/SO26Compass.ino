#include <Servo.h>

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(2);  // Servo signal wire on pin 9
  Serial.println("Welcome to Science Olympics IDE - Compass");
  Serial.println("Enter angle (0-180):");
}

void loop() {
  if (Serial.available() > 0) {
    int angle = Serial.parseInt();
    
    // Clear any leftover newline/carriage return
    while (Serial.available()) Serial.read();
    
    if (angle >= 0 && angle <= 180) {
      myServo.write(angle);
      Serial.print("Moved to: ");
      Serial.println(angle);
    } else {
      Serial.println("Invalid. Enter 0-180.");
    }
  }
}
