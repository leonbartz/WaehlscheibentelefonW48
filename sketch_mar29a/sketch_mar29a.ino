void sDelay() {
  delay(1000);
}

void blinkFor(int times) {
  int delayTime = 400;
  int counter = 0;
  while(counter < times) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(delayTime);
    digitalWrite(LED_BUILTIN, LOW);
    delay(delayTime);
    counter = counter + 1;
  }
}

void setup() {
  Serial.begin(9600);
  // Sets the onboard LED as our output
  pinMode(LED_BUILTIN, OUTPUT);
  // Gets the HIGH and LOW from Digital 2
  pinMode(2, INPUT);
  // Hello i am alive
  blinkFor(3);
  // short delay
  sDelay();
}


// the loop function runs over and over again forever
void loop() {
  int input = digitalRead(2);
  if(input == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  Serial.print(input);
  Serial.println();
  delay(10);
}