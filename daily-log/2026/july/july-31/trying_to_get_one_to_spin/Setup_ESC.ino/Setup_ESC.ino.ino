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
  myESC.writeMicroseconds(3000);
  
  Serial.println("3. NOW plug in the ESC battery!");
  Serial.println("4. Wait for the initial musical beeps (approx 3-5 seconds)...");
  Serial.println("5. Press Enter in Serial Monitor when you hear the beeps.");

  while (Serial.available() == 0) {} // Wait for user to press Enter
  while (Serial.available() > 0) { Serial.read(); } // Clear buffer

  Serial.println("Sending MIN throttle (1000 us)...");
  myESC.writeMicroseconds(2000);
  
  Serial.println("Wait for confirmation beeps... Calibration Complete!");
  delay(3000);
}

void loop() {
}
