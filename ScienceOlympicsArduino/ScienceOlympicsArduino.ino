// Created by Max Heywood and the Jack and Co Team
//////////////////////////////
//       Instructions
//////////////////////////////
// 1. Clear the Console
// 2. Compile the Code
// 3. Open the Serial Monitor
//////////////////////////////
//         Imports
//////////////////////////////
#include <Servo.h>
Servo yawServo;
//////////////////////////////
//        Variables
//////////////////////////////
char message;
int position = 90;
//////////////////////////////
//          Setup
//////////////////////////////
void setup() {
  yawServo.attach(2);
  Serial.begin(9600);
  clearSerial();
  homeServos();
  Serial.println("Loading...");
  delay(1000);
  Serial.println("Welcome to Science Olympics IDE");
  Serial.println("Type H for help");
  yawServo.write(position);
}
//////////////////////////////
//          Loop
//////////////////////////////
void loop() {

  if (Serial.available() > 0) {
    message = Serial.read();

    // Start
    if (message == 's') {
      Serial.println("Starting");
    }

    // Help menu
    else if (message == 'h') {
      helpMenu();
    }

    // Move left
    else if (message == 'd') {
      moveLeft();
    }

    // Move right
    else if (message == 'a') {
      moveRight();
    }

    // Home servo
    else if (message == 'x') {
      homeServos();
    }

    // Quit
    else if (message == 'q') {
      quit();
    }
    // Dance
    else if (message == 'e') {
      danceParty();
    }
  }
}
//////////////////////////////
//        Functions
//////////////////////////////
void moveLeft() {
  Serial.println();
  Serial.println("Left");
  position += 10;
  position = constrain(position, 0, 180);
  yawServo.write(position);
}

void moveRight() {
  Serial.println();
  Serial.println("Right");
  position -= 10;
  position = constrain(position, 0, 180);
  yawServo.write(position);
}

void homeServos() {
  Serial.println();
  Serial.println("Homing servo");
  position = 90;
  yawServo.write(position);
}

void clearSerial() {
  for (int i = 0; i < 15; i++) {
    Serial.println();
  }
}

void quit() {
  Serial.println();
  clearSerial();
  Serial.println("Quitting");
  Serial.end();
}

void helpMenu() {
  Serial.println();
  Serial.println("Controls");
  Serial.println("-------------------------------");
  Serial.println("S - Start");
  Serial.println("A - Move Left");
  Serial.println("D - Move Right");
  Serial.println("X - Home servo");
  Serial.println("E - Dance");
  Serial.println("Q - Quit");
}

void danceParty() {
  Serial.println("Dancing!");
  homeServos();
  yawServo.write(80);
  yawServo.write(100);
  yawServo.write(70);
  yawServo.write(110);
  yawServo.write(60);
  yawServo.write(120);
  yawServo.write(50);
  yawServo.write(130);
  yawServo.write(40);
  yawServo.write(140);
  yawServo.write(30);
  yawServo.write(150);
  yawServo.write(20);
  yawServo.write(160);
  yawServo.write(10);
  yawServo.write(170);
  yawServo.write(0);
  yawServo.write(180);
}