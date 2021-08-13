#define trigPinl 12
#define echoPinl 13
#define trigPinr 5
#define echoPinr 6

const int motorPin1  = 8;  // Pin 14 of L293
const int motorPin2  = 9;  // Pin 10 of L293
//Motor B
const int motorPin3  = 10; // Pin  7 of L293
const int motorPin4  = 11;  // Pin  2 of L293

char ch;
const int sensorPin = 7;    //IR sensor
int value = 0;

String temp="";

String s = "kkkkkkkkkkkkkkkkkkkkkkkkkkkk";

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
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(1500);
    mfront();
}

void bright()
{
    mback();
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(1500);
}

void rleft()
{
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(1500);
    mfront();
}

void bleft()
{
    mback();
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(1500);
}

void mback()
{
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(1500);
}

void mfront()
{
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
  return true;
  else false;
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

  Serial.println(distance);

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

  Serial.println(distance);
  
  if (distance <= 13){
    return false;
  }
  else {
    return true;
  }
}

/*void back(char ch)
{
  if(ch=='3')
  {
    mback();
  }
  else if(ch=='4')
  {
    bright();
  }
  else if(ch=='2')
  {
    bleft();
  }
  else
  {
    Serial.println("BG");
  }
  return;
}*/

void backtrack(String s)
{
    int i=s.length()-1;
  while(i>=0)
  {
    if(s[i]=='3')
      mback();
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

void traverse(String t,char ch)
{
  //FOR GOAL CONDITION

  Serial.println(t);
  
  bool hit=false;
  if(t.length()==3)         //end condition here ...
  {
   s=t;
   //hit=true;
   //back(ch);
   return;
  }
  
  if(t.length()>=s.length())      //preventing redundant cases ...
  {
   //back(ch);
   return;
  }
  
  if(sleft())                   //checking for left using sonar sensor
  {
    rleft();
    traverse(t+"4",'4');
    bright();
  }

  if(sfront())                 //checking for right using the IR sensor
  {
    mfront();
    traverse(t+"3",'3');
    mback();
  }
  
  if(sright())                //checking for right using the sonar sensor
  {
    rright();
    traverse(t+"2",'2');
    bleft();
  }
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

  //rleft();
  //mback();
  //bright();

  traverse(temp,ch);

  Serial.println(s);

  backtrack(s);
}

void loop() 
{
  //int i=0;
  //s="343423"   
  //char ch;
  //s=traverse(s,temp,ch);

  //Serial.println("Sorry");
  
  /*while(s[i])
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
  }*/

  //delay(2000);
  //backtrack(s);
  
}
