// Created by Max Heywood and the Jack and Co Team
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
  homeServos(); // Now defined below
  
  Serial.println("Loading...");
  delay(1000);
  Serial.println("Welcome to Science Olympics IDE (Compass)");
  Serial.println("Type h for help");
}

//////////////////////////////
//          Loop
//////////////////////////////
void loop() {
  if (Serial.available() > 0) {
    message = Serial.read();

    // Start
    if (message == 's') {
      Serial.println("Starting...");
    }
    // Help menu
    else if (message == 'h') {
      helpMenu();
    }
    // Set Move - Now calls the functional setAngle()
    else if (message == 'm') {
      setAngle();
    }
    else if (message == 'q') {
      quit();
    }
    else if (message == 'x') {
      homeServos();
    }
    else if (message == 'e') {
      danceParty();
    }
  }
}

//////////////////////////////
//        Functions
//////////////////////////////

void homeServos() {
  Serial.println("Homing Servo to 90...");
  position = 90;
  yawServo.write(position);
}

void setAngle() {
  Serial.println("Enter Angle (0-180) and press Enter:");
  
  // Wait for user to type something
  while (Serial.available() == 0) {
    // Just waiting for input
  }

  // Parse integer from Serial Monitor
  int newPos = Serial.parseInt(); 

  if (newPos >= 0 && newPos <= 180) {
    position = newPos;
    yawServo.write(position);
    Serial.print("Angle: ");
    Serial.println(position);
  } else {
    Serial.println("Invalid Angle! Please use 0-180.");
  }
}

void clearSerial() {
  for (int i = 0; i < 15; i++) {
    Serial.println();
  }
}

void quit() {
  Serial.println("Quitting. Restart Arduino to reconnect.");
  Serial.end();
}

void helpMenu() {
  Serial.println("\n--- Controls ---");
  Serial.println("s - Start");
  Serial.println("m - Set Angle (Followed by a number)");
  Serial.println("x - Home servo");
  Serial.println("e - Dance");
  Serial.println("q - Quit");
}

void danceParty() {
  Serial.println("Dancing!");
  for (int i = 0; i <= 180; i += 20) {
    yawServo.write(i);
    delay(100);
  }
  homeServos();
}