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
