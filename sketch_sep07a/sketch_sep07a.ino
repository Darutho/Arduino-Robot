const int a=0;
int reading;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(a,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  reading=analogRead(a);
  Serial.println(reading);
}
