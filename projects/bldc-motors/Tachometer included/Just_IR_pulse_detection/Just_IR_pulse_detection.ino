const int IR = 8;

int count = 0;
bool lastState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(IR, INPUT);
}

void loop() {
  int senState = digitalRead(IR);
  if (senState != lastState) {
    lastState = senState;
    Serial.println(count);
    count = count + 1;
  }

}
