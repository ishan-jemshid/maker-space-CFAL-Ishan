#include <Servo.h>

Servo myESC;

void setup() {
  Serial.begin(9600);
  myESC.attach(9);

  Serial.println("--- ESC Calibration ---");
  Serial.println("1. Unplug the ESC battery.");
  Serial.println("5. Press Enter in Serial Monitor when if the ESC battery is unplugged");
  while (Serial.available() == 0) {} // Wait for user to press Enter
  while (Serial.available() > 0) { Serial.read(); } // Clear buffer
  
  Serial.println("2. Sending MAX throttle (2000 us)...");
  myESC.writeMicroseconds(2050);
  
  Serial.println("3. NOW plug in the ESC battery!");
  Serial.println("4. Wait for the initial musical beeps (approx 3-5 seconds)...");
  Serial.println("5. Press Enter in Serial Monitor when you hear the beeps.");

  while (Serial.available() == 0) {} // Wait for user to press Enter
  while (Serial.available() > 0) { Serial.read(); } // Clear buffer

  Serial.println("Sending MIN throttle (1000 us)...");
//  delay(5000);
  myESC.writeMicroseconds(942);
  
  Serial.println("Wait for confirmation beeps... Calibration Complete!");
  delay(3000);
}

void loop() {
  
  Serial.println("Speed : ");
  while (Serial.available() == 0) {}

  int speed = Serial.parseInt();

  while (Serial.available() > 0) {
    Serial.read(); 

  }

  myESC.writeMicroseconds(speed);
  Serial.println(speed);

  delay(500);
}
