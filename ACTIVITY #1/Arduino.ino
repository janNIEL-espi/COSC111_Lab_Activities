// Define the pins for the LEDs
int ledPins[] = {12, 11, 10, 9, 8}; // LED pins
int numLeds = 5;                    // Number of LEDs

void setup() {
  // Set each pin as an OUTPUT
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Turn on LEDs one by one
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH); // Turn LED on
    delay(1000);                    // 1 second delay
  }

  // Turn off LEDs one by one
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);  // Turn LED off
    delay(1000);                    // 1 second delay
  }
}
