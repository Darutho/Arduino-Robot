const int a=0;
int reading=0;
bool flag = true;

const int motorPin1  = 8;  // Pin 14 of L293
const int motorPin2  = 9;  // Pin 10 of L293
//Motor B
const int motorPin3  = 10; // Pin  7 of L293
const int motorPin4  = 11;  // Pin  2 of L293

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(a,INPUT);

   pinMode(motorPin1, OUTPUT);
   pinMode(motorPin2, OUTPUT);
   pinMode(motorPin3, OUTPUT);
   pinMode(motorPin4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  reading=analogRead(a);
  Serial.println(reading);

    if(reading<600)
    {
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, LOW);
    }
    else if(flag)
    {
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, LOW);
      delay(1500);
      flag = false;
    }
    else if(!flag)
    {
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, HIGH);
      delay(1500);
      flag = true;
    }
}
