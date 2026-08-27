#include <Servo.h>

Servo myESC;  // Create a servo object to control the ESC

void setup() {
  myESC.attach(9); // Attach the ESC signal wire to digital pin 9
  
  // Optional: ESC Arming sequence (sending a low signal on startup)
  //myESC.writeMicroseconds(1000); 
  //delay(2000); // Wait 2 seconds for the ESC to arm
}

void loop() {
  myESC.writeMicroseconds(1700);
}
