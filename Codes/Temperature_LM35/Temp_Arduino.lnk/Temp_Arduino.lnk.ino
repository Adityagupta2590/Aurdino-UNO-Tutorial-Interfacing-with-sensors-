

//using LM35 low cost '3' pin ic
int val;
int tempPin = 1;//coneted to data pin of sensor for taking data
void setup()
{
Serial.begin(9600);
}
void loop()
{
val = analogRead(tempPin);// taking readings
float mv = ( val/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;

Serial.print("TEMPRATURE = ");
Serial.print(cel);
Serial.print("*C");
Serial.println();
delay(1000);

/* uncomment this to get temperature in farenhite 
Serial.print("TEMPRATURE = ");
Serial.print(farh);
Serial.print("*F");
Serial.println();
*/
}

