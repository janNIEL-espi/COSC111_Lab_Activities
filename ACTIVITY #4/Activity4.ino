#define PHOTO_SENSOR_PIN A2  // Photoresistor pin
#define LED_PIN 13           // LED pin


const int BRIGHTNESS_THRESHOLD = 22; 


int readBrightness();
String getBrightnessStatus(int brightnessValue);
void checkFireCondition(int brightness);
void handleSerialInput();


bool shouldBlink = false;

void setup() {
  Serial.begin(9600);
  pinMode(PHOTO_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
 
  handleSerialInput();
  int brightness = readBrightness();
  Serial.print("Brightness: ");
  Serial.print(brightness);
  Serial.println(" %");  

  Serial.print("Status: ");
  Serial.println(getBrightnessStatus(brightness)); 

  checkLightCondition(brightness);

  if (shouldBlink) {
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(100);
      digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  } else {
    digitalWrite(LED_PIN, LOW); 
  }

  delay(100);
}


int readBrightness() {
  int rawValue = analogRead(PHOTO_SENSOR_PIN);  
  return map(rawValue, 0, 1023, 0, 100);        
}


String getBrightnessStatus(int brightnessValue) {
  if (brightnessValue > BRIGHTNESS_THRESHOLD) {
    return "Bright";
  } else {
    return "Dark";
  }
}


void checkLightCondition(int brightness) {
  if (brightness >= BRIGHTNESS_THRESHOLD) {
    shouldBlink = true;
  }
}


void handleSerialInput() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();  
    if (input.equalsIgnoreCase("stop")) {
      shouldBlink = false;
      Serial.println("Blinking stopped.");
    }
  }
}