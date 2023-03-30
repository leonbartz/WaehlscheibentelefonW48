void blinkFor(int times) {
  int delayTime = 200;
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
}

void loop() {
  int counterCircuitBreak = 0;
  int counterEnd = 0;

  // Wait for the dial to stop working, then print result
  while(counterEnd <= 30) {
    int input = digitalRead(2);
    if(input == LOW) {
      // Circuit broken
      counterCircuitBreak = counterCircuitBreak + 1;
    } else {
      // No signal
      counterEnd = counterEnd + 1;
    }
    // 70 is roundabout the interval of the circuitbreaking element
    delay(75);  
  }

  // Write result to console and blink
  if(counterCircuitBreak != 0) {
    // Write to Output
    Serial.print(counterCircuitBreak);
    Serial.println();
    // Blink chosen number
    blinkFor(counterCircuitBreak);
  }
}
