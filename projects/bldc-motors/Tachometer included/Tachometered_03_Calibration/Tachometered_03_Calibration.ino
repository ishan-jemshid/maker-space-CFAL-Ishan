#include <Servo.h>

Servo myESC;
const int IR = 8;

unsigned long initime = 0;

int count = 0;
bool lastState = LOW;
long rpm = 0;

int speed = 0;
int step = 0;

void setup() {
  Serial.begin(9600);
  myESC.attach(9);

  pinMode(IR, INPUT);
  count = 0;

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

  myESC.writeMicroseconds(942); //942 instead of 1000 since during testing I could get the min to be at exactly 942
  
  Serial.println("Calibration Complete");
}


void loop() {

  Serial.print("Speed : ");
  while (Serial.available() == 0) {}

  int temp_speed = Serial.parseInt();

  while (Serial.available() > 0) {
    Serial.read(); 

  }
  
    Serial.println(temp_speed);

    if (temp_speed > speed){
      step = 1;
    }
    else{
      step = -1;
    }

  while (temp_speed != round(speed)) {
    speed = speed + step;
    myESC.writeMicroseconds(speed);
    delay(3);
  }
  myESC.writeMicroseconds(temp_speed);
  speed = temp_speed;


  initime = millis();
  count = 0;
  
  while (millis()-initime <= 5000){
  int senState = digitalRead(IR);
      if (senState != lastState) {
    lastState = senState;
//    Serial.println(count);
    count = count + 1;
    }
  }

  Serial.print("rotations = ");
  Serial.println(count/2);
  rpm = (count*6L);
  Serial.println(rpm);

}
