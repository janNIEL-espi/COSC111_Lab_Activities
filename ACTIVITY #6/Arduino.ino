const int buttonPin = 12; // Connect your button to pin 12
int buttonState = 0;

void setup() {
    pinMode(buttonPin, INPUT); // Set button pin as input
    Serial.begin(9600); // Initialize serial communication
}

void loop() {
    buttonState = digitalRead(buttonPin); // Read button state (HIGH/LOW)

    // Send button state as 1 (pressed) or 0 (not pressed)
    if (buttonState == HIGH) { 
        Serial.println("1"); // Button pressed
    } else {
        Serial.println("0"); // Button not pressed
    }

    delay(200); // Adjust as needed to avoid spamming data
}
