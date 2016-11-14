//this usses ultrasonic sensor for detection application is shown for tank level indicator
const int buzzer = 7; // Sensor Input for buzzer
//const int trigPin = 2;// Sensor Input for ultra sonic
//const int echoPin = 4;// Sensor Input for ultra sonic
const int trigPin = 5;// Sensor Input for ultra sonic
const int echoPin = 6;// Sensor Input for ultra sonic
void setup() 
{
 pinMode(buzzer, INPUT); // set a pin for buzzer output
  Serial.begin(9600);  // initialize serial communication:
}

void loop() 
{ 
   long duration, inches, cm;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  delay(100);
  if (cm<20)
  {
   // buzz(buzzer, 2500, 500); // buzz the buzzer on pin 4 at 2500Hz for 500 milliseconds
    
    long delayValue = 100000000;
    digitalWrite(buzzer,HIGH); // write the buzzer pin high to push out the diaphram
   delayMicroseconds(delayValue); // wait for the calculated delay value
   // digitalWrite(buzzer,LOW); // write the buzzer pin low to pull back the diaphram
   // delayMicroseconds(delayValue); // wait againf or the calculated delay value
   // delay(1000); // wait a bit between buzzes
  }
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  digitalWrite(buzzer,LOW);
}

long microsecondsToInches(long microseconds)
{
    return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
    return microseconds / 29 / 2;
}

