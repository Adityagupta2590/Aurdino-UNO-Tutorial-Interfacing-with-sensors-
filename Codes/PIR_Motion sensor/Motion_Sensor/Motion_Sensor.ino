this uses PIR sensor for detecting any motion 
const int sensor_pin = 4;//digital pin 4
int sensor_value = 0; //zero when no motion
void setup() 
{
  pinMode(led, OUTPUT);
  pinMode(sensor_pin, INPUT);
 Serial.begin(9600);
 delay(1000);
}
void loop() {
 // Get sensor value
 sensor_value = digitalRead(sensor_pin);//check for motion
 // Print on serial
 if (sensor_value==1)
 {
  digitalWrite(led, HIGH);
 Serial.println("motion detected");
 }
 //Serial.println(sensor_pin);
 delay(1000);
}
