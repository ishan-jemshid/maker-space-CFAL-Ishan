#include <Servo.h>

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
  count = 0;

  myESC.writeMicroseconds(1500);
}


void loop() {

  int senState = digitalRead(IR);
      if (senState != lastState) {
    lastState = senState;
    Serial.println(count);
    count = count + 1;
    }

}
