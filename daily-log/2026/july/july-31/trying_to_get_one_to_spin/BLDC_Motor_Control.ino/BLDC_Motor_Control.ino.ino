#include <Servo.h>



Servo myESC;

void setup() {

  Serial.begin(9600);
  myESC.attach(9);
 
  myESC.writeMicroseconds(1000); 
  delay(2000); // Wait 2 seconds for the ESC to arm
  myESC.writeMicroseconds(2000); 
  delay(2000); // Wait 2 seconds for the ESC to arm

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
