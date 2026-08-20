#include <Servo.h>

int temp_speed = 1100;

Servo myESC;
const int IR = 8;

int count = 0;
bool lastState = LOW;

int speed = 0;
int step = 1;

void setup() {
  Serial.begin(9600);
  myESC.attach(9);

  pinMode(IR, INPUT);

  Serial.println("ESC_CALLIBERATION");
  Serial.println("5. Press Enter in Serial Monitor when if the ESC battery is unplugged");
  
  while (Serial.available() == 0) {} // Wait for user to press Enter
  while (Serial.available() > 0) { Serial.read(); } // Clear buffer
  
  Serial.println("Sending-Max-Throttle");
  myESC.writeMicroseconds(2050);  //2050 instead of 2000 since during testing closest I could get it to max out was at 2050
  
  Serial.println("3. Plug in the ESC battery");
  Serial.println("5. Press Enter in Serial Monitor after the beeps.");

  while (Serial.available() == 0) {} // Wait for user to press Enter
  while (Serial.available() > 0) { Serial.read(); } // Clear buffer

  Serial.println("Sending MIN throttle (1000 us)...");
//  delay(5000);
  myESC.writeMicroseconds(942); //942 instead of 1000 since during testing I could get the min to be at exactly 942
  
  Serial.println("Calibration Complete");


  while (temp_speed != round(speed)) {
    speed = speed + 1;
    myESC.writeMicroseconds(speed);
    delay(6);
  }
  myESC.writeMicroseconds(temp_speed);
  speed = temp_speed;
}

void loop() {

  count = 0;

  int senState = digitalRead(IR);
      if (senState != lastState) {
    lastState = senState;
    Serial.println(count);
    count = count + 1;
    }

}
