///the program shows interfacing of motor driving ic L239D with UNO
// the pin no. 5 and 6 is connected to two controlling pin (input 3 and 4) of motor driving ic
const int motv = 5;
const int motg = 6;

void setup() {
  pinMode(motv, OUTPUT);
  pinMode(motg, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    ////////move motor in clockwise direction
    digitalWrite(motv, HIGH);
    digitalWrite(motg, LOW);
  delay(10000);
  digitalWrite(motv, LOW);
  delay(3000);  
  ////////move motor in anti-clockwise direction
    digitalWrite(motv, LOW);
    digitalWrite(motg, HIGH);
//    tone(buzzer, 1000, 200);
  delay(10000);
}


