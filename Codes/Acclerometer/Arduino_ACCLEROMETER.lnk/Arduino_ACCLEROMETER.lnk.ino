int scale = 3;
boolean micro_is_5V = true; 
void setup()
{
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
}
void loop()
{
  // Get raw accelerometer data for each axis
  int rawX = analogRead(A0);
  int rawY = analogRead(A1);
  int rawZ = analogRead(A2);
float scaledX, scaledY, scaledZ; // Scaled values for each axis
  if (micro_is_5V) // microcontroller runs off 5V
  {
    scaledX = map(rawX, 0, 675, -scale, scale); // 3.3/5 * 1023 =~ 675
    scaledY = map(rawY, 0, 675, -scale, scale); // 3.3/5 * 1023 =~ 675
    scaledZ = map(rawZ, 0, 675, -scale, scale); // 3.3/5 * 1023 =~ 675
  }
  else // microcontroller runs off 3.3V
  {
    scaledX = map(rawX, 0, 1023, -scale, scale);
    scaledZ = map(rawY, 0, 1023, -scale, scale);
    scaledZ = map(rawZ, 0, 1023, -scale, scale);
  }

  Serial.print("X: "); Serial.println(rawX);

  // Print out scaled X,Y,Z accelerometer readings
  Serial.print("X: "); Serial.print(scaledX); Serial.println(" g");
  delay(200);

  Serial.print("Y: "); Serial.println(rawY);

  // Print out scaled X,Y,Z accelerometer readings
  Serial.print("Y: "); Serial.print(scaledY); Serial.println(" g");
delay(200);
  Serial.print("Z: "); Serial.println(rawZ);

  // Print out scaled X,Y,Z accelerometer readings
  Serial.print("Z: "); Serial.print(scaledZ); Serial.println(" g");
delay(200);
delay(2000);
}
