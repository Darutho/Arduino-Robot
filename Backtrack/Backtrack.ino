#define trigPinl 12
#define echoPinl 13
#define trigPinr 5
#define echoPinr 6

const int motorPin1  = 8;  // Pin 14 of L293
const int motorPin2  = 9;  // Pin 10 of L293
//Motor B
const int motorPin3  = 10; // Pin  7 of L293
const int motorPin4  = 11;  // Pin  2 of L293

const int sensorPin = 7;    //IR sensor
int value = 0;

String temp="";

//String s = "kkkkkkkkkkkkkkkkkkkkkkkkkkkk";


  int i=0;
  String s="343423";

void fstop()
{
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    //delay(5000);
}

void rright()
{
    //right --> left && back --> front
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(1500);
    mback();
}

void bright()
{
    //right --> left && front --> back
    mfront();
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(1500);
}

void rleft()
{
    //left --> right && back --> front
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(1500);
    mback();
}

void bleft()
{
    //left --> right && front --> back
    mfront();
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(1500);
}

void mfront()
{
    //mback()
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(1500);
}

void mback()
{
    //mfront()
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(1500);
}

bool sfront()
{
  int value = analogRead(sensorPin);
  Serial.println(value);

  if(value==0)
  return false;
  else true;
}

bool sleft()
{
  long duration, distance;
  digitalWrite(trigPinl, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinl, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinl, LOW);
  duration = pulseIn(echoPinl, HIGH);
  distance = (duration/2) / 29.1;

  if (distance <= 13){
    return false;
  }
  else {
    return true;
  }
}

bool sright()//Set diff pin nmber
{
  long duration, distance;
  digitalWrite(trigPinr, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinr, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinr, LOW);
  duration = pulseIn(echoPinr, HIGH);
  distance = (duration/2) / 29.1;

  if (distance <= 13){
    return false;
  }
  else {
    return true;
  }
}

void backtrack(String s)
{
    int i=s.length()-1;
  while(i>=0)
  {
    if(s[i]=='3')
      mfront();
    else if(s[i]=='4')
      bright();
    else if(s[i]=='2')
      bleft();
    else
      Serial.println("BG");
    i--;
  }

  fstop();
  
}      

void setup() 
{
  Serial.begin(9600);
  pinMode(sensorPin,INPUT);

  pinMode(trigPinl, OUTPUT);
  pinMode(echoPinl, INPUT);
  
  pinMode(trigPinr, OUTPUT);
  pinMode(echoPinr, INPUT);

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  rleft();
  //mback();
  bright();

  fstop();

  /*int i=0;
  s="343423";   
  
  while(s[i])
  {
    if(s[i]=='3')
      mback();
    else if(s[i]=='4')
      rleft();
    else if(s[i]=='2')
      rright();
    else
      Serial.println("BG");
    i++;
  }

  //delay(100);
  backtrack(s);
  */

  rleft();
  mback();
  
  rleft();
  mback();
  
  rleft();
  mback();
  
  rleft();
  mback();

  fstop();
}

void loop() 
{
  /*
  int i=0;
  s="343423";   
  
  while(s[i])
  {
    if(s[i]=='3')
      mfront();
    else if(s[i]=='4')
      rleft();
    else if(s[i]=='2')
      rright();
    else
      Serial.println("BG");
    i++;
  }

  delay(2000);
  backtrack(s);
  */
}
