//It uses MQ-6 gas sensor for detection of LPG gas leakage 
int redLed = 8;
int greenLed = 9;
int buzzer = 10;
int smokeA0 = A5;
// Your threshold value
int sensorThres = 400;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  //if value greater than 400 than there is leakage of GAS
  { ///if leakage is observed
    digitalWrite(redLed, HIGH); //glow red LED
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);//buzzer will be sound
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }
  delay(100);
}


