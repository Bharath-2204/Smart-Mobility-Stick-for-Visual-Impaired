#define LED_PIN 3
#define POWER_PIN 7
#define SIGNAL_PIN A5
#define THRESHOLD 300
int const trigPin = 10;
int const echoPin = 9;
int const buzzPin = 2;
int value = 0; 
const int LIGHT_SENSOR_PIN = A0; 
const int LED = 4; 
const int ANALOG_THRESHOLD = 500;
const int buttonPin = 5;
const int redPin = 11;
const int greenPin = 12;
const int bluePin = 13;
void setup() {
 Serial.begin(9600);
 pinMode(LED_PIN, OUTPUT); 
 pinMode(POWER_PIN, OUTPUT); 
 
 pinMode(trigPin, OUTPUT); 
 pinMode(echoPin, INPUT); 
 pinMode(buzzPin, OUTPUT);
 pinMode(LED, OUTPUT);
 pinMode(buttonPin, INPUT);
 pinMode(redPin, OUTPUT);
 pinMode(greenPin, OUTPUT);
 pinMode(bluePin, OUTPUT);
}
void loop() {
 //Water Sensor
 
 
digitalWrite(POWER_PIN, HIGH); 
delay(10); 7 value = analogRead(SIGNAL_PIN); 
 digitalWrite(POWER_PIN, LOW); 
 if (value > THRESHOLD) {
 Serial.print("The water is detected");
 digitalWrite(LED_PIN, HIGH); 
 } else {
 digitalWrite(LED_PIN, LOW); 
 }
 //Proximity Sensor
 int duration, distance;
 digitalWrite(trigPin, HIGH); 
 delay(1);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1;
 if (distance <= 50 && distance >= 0) {
 digitalWrite(buzzPin, HIGH);
 } else {
 digitalWrite(buzzPin, LOW);
 }
 delay(60);
 
 //Night Sensor
 int analogValue;
 analogValue = analogRead(LIGHT_SENSOR_PIN); 
 if(analogValue < ANALOG_THRESHOLD)
 digitalWrite(LED, HIGH); 
 else
 digitalWrite(LED, LOW); 
 //RGB Module
 int buttonState;
 buttonState = digitalRead(buttonPin);
 int counter = 0;
 
 
if (buttonState == LOW) {
digitalWrite(redPin, HIGH);
8 delay(1000);
 digitalWrite(greenPin, HIGH);
 delay(1000);
 digitalWrite(bluePin, HIGH);
 delay(1000);
 }{
 digitalWrite(redPin, LOW);
 digitalWrite(greenPin, LOW);
 digitalWrite(bluePin, LOW);
 
}
}
