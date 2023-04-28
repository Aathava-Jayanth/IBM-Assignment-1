int ultrasonics = 0;

int pirsensor = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(4, INPUT);
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  pirsensor = digitalRead(4);
  ultrasonics = 0.01723 * readUltrasonicDistance(7, 6);
  Serial.println(pirsensor);
  delay(300);
  Serial.println(ultrasonics);
  delay(300);
  if (pirsensor == 1) {
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }
  if (ultrasonics <= 100) {
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(9, LOW);
  }

  ultrasonics;
}