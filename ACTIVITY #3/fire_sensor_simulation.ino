#define Temp_Sensor_Pin A0   
#define Photo_Sensor_Pin A2  
#define LED_PIN 12  
         
const float Tempmax_Treshold = 50.0;    
const int Brightnessmax_Treshold = 220; 
const int BetaValue = 3950;                
const int Series_Resistance = 10;   

float ReadTemperature();
int ReadBrightness();
String BrightnessStatus(int BrightnessValue);
void CheckFire(float Temp, int Brightness);

void setup() {

  Serial.begin(9600);
  pinMode(Temp_Sensor_Pin, INPUT);
  pinMode(Photo_Sensor_Pin, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  float Temperature = ReadTemperature();
  int Brightness = ReadBrightness();

  Serial.print("Temperature: ");
  Serial.print(Temperature);
  Serial.println(" °C");

  Serial.print("Brightness: ");
  Serial.println(BrightnessStatus(Brightness));  

  CheckFire(Temperature, Brightness);
  delay(1000);
}

float ReadTemperature() {
  int SensorValue = analogRead(Temp_Sensor_Pin);  
  float Resistance = Series_Resistance * (1023.0 / SensorValue - 1.0);
  float TemperatureK = BetaValue / (log(Resistance / Series_Resistance) + BetaValue / 298.15);
  float TemperatureC = TemperatureK - 273.15;
  return TemperatureC;
}

int ReadBrightness() {
  return analogRead(Photo_Sensor_Pin); 
}

String BrightnessStatus(int BrightnessValue) {
  if (BrightnessValue > Brightnessmax_Treshold) {
    return "Bright";
  } else {
    return "Dark";
  }
}

void CheckFire(float Temp, int Brightness) {
  if (Temp >= Tempmax_Treshold && Brightness >= Brightnessmax_Treshold) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(LED_PIN, HIGH);
      delay(100);
      digitalWrite(LED_PIN, LOW);
      delay(100);
    }
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}