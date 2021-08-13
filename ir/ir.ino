const int sensorPin = A0;
int value = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(sensorPin);
  Serial.println(value);
}
