#define trigPinl 12
#define echoPinl 13
#define trigPinr 5
#define echoPinr 6
#define buzz 2

const int motorPin1  = 8;  // Pin 14 of L293
const int motorPin2  = 9;  // Pin 10 of L293
//Motor B
const int motorPin3  = 10; // Pin  7 of L293
const int motorPin4  = 11;  // Pin  2 of L293

int c;
const int sensorPin = 7;    //IR sensor
const int sensorPin1 = 4;    //IR Diagonal
const int sensorPin2 = 3;    //IR Diagonal

int value = 0,start,finish;

String temp="";

String s = "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkk";

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
    delay(1530);
    ffront();
    fstop();
}

void bright(int d)
{
    //mback();
    //fstop();
    mback();
    fstop();
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(1530);
    //fback();
    //fstop();
    //mback();
    //fstop();
    //rectify();
    //fstop();
    //mfront();
    fstop();
}

void rleft()
{
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(1530);
    ffront();
    fstop();
}

void bleft(int d)
{
    //mback();
    //fstop();
    mback();
    fstop();
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(15230);
    //fback();
    //fstop();
    //mback();
    //fstop();
    //rectify();
    //fstop();
    //mfront();
    fstop();
}

void mback()
{
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(3020);
    fstop();
}

void mback(int d)
{
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(d/3+1160);
    fstop();
}

void fback()
{
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(2500);
    fstop();
}

void mfront()
{
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(3020);
    fstop();
}

void mfront(int d)
{
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(d+1150);
    fstop();
}

void ffront()
{
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(3000);
    fstop();
}

bool sfront()
{
  int value = digitalRead(sensorPin);
  //Serial.println(value);

  if(value==0)
  return true;
  else 
  return false;
}

bool sdial()
{
  int value = digitalRead(sensorPin1);

  if(value==0)
  return true;
  else 
  return false;
}


bool sdiar()
{
  int value = digitalRead(sensorPin2);

  if(value==0)
  return true;
  else 
  return false;
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

  Serial.println("L " + distance);

  if (distance <= 17){
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

  Serial.println("R " + distance);
  
  if (distance <= 17){
    return false;
  }
  else {
    return true;
  }
}

/*
void rectifyb()
{
  //bool flag = true;
  long d1, t1;
  long d, t;
    while(t!=t1)
    {

    bool flag = true;
      
    digitalWrite(trigPinl, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinl, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinl, LOW);
    d = pulseIn(echoPinl, HIGH);
    t = (d/2) / 29.1;

   
   digitalWrite(trigPinr, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPinr, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPinr, LOW);
   d1 = pulseIn(echoPinr, HIGH);
    t1 = (d1/2) / 29.1;
  
    Serial.println(t);
    Serial.println(t1);

    

      
      if(t<t1)
      {
       digitalWrite(motorPin1, LOW);
       digitalWrite(motorPin2, HIGH);
       digitalWrite(motorPin3, LOW);
       digitalWrite(motorPin4, LOW);
       delay(120);
        fstop();
      }
      else if(t>t1)
      {
       //make the left motor on for some specific delay() ...
       digitalWrite(motorPin1, LOW);
       digitalWrite(motorPin2, LOW);
       digitalWrite(motorPin3, HIGH);
       digitalWrite(motorPin4, LOW);
       delay(120);
        fstop();
     }

     //put end condition here ...
     /*if(sleft() && sfront() && sright() && sdial() && sdiar())         //end condition here ...
     {
      s=t;
      s+='3';
      fstop();
      break;
     }


     while((t==t1 )&& flag)
     {
      if(sleft() && sfront() && sright() && sdial() && sdiar())         //end condition here ...
      {
        s=t;
        s+='3';
        fstop();
        flag = false;
      }
      if(sdiar())
      {
        digitalWrite(motorPin1, LOW);
       digitalWrite(motorPin2, HIGH);
       digitalWrite(motorPin3, LOW);
       digitalWrite(motorPin4, HIGH);
       delay(120);
        fstop();
      }
      else if(sdial())
      {
        digitalWrite(motorPin1, HIGH);
       digitalWrite(motorPin2, LOW);
       digitalWrite(motorPin3, HIGH);
       digitalWrite(motorPin4, LOW);
       delay(120);
        fstop();
      }
      else if(!sdial() && !sdiar())
      {
        flag = false;
      }
     }
     
    }
}
*/

/*
void rectify()
{
  //bool flag = true;
  long d1, t1;
  long d, t;
    while(t!=t1)
    {

    bool flag = true;
      
    digitalWrite(trigPinl, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinl, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinl, LOW);
    d = pulseIn(echoPinl, HIGH);
    t = (d/2) / 29.1;

   
   digitalWrite(trigPinr, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPinr, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPinr, LOW);
   d1 = pulseIn(echoPinr, HIGH);
    t1 = (d1/2) / 29.1;
  
    Serial.println(t);
    Serial.println(t1);

    

      
      if(t>t1&&!sright())
      {
       digitalWrite(motorPin1, HIGH);
       digitalWrite(motorPin2, LOW);
       digitalWrite(motorPin3, HIGH);
       digitalWrite(motorPin4, LOW);
       delay(120);
        fstop();
      }
      else if(t<t1&&!sleft())
      {
       //make the left motor on for some specific delay() ...
       digitalWrite(motorPin1, LOW);
       digitalWrite(motorPin2, HIGH);
       digitalWrite(motorPin3, LOW);
       digitalWrite(motorPin4, HIGH);
       delay(120);
        fstop();
     }

     //put end condition here ...

      if(sdial())
      {
       digitalWrite(motorPin1, HIGH);
       digitalWrite(motorPin2, LOW);
       digitalWrite(motorPin3, LOW);
       digitalWrite(motorPin4, LOW);
       delay(120);
        fstop();
      }
      else if(sdiar())
      {
       digitalWrite(motorPin1, LOW);
       digitalWrite(motorPin2, LOW);
       digitalWrite(motorPin3, LOW);
       digitalWrite(motorPin4, HIGH);
       delay(120);
        fstop();
      }
      else if(!sdial() && !sdiar())
      {
        flag = false;
      }
     }
     
    }
}
*/

int rectify()
{
  start=millis();
  //bool flag = true;
  long d1, t1;
  long d, t;
    while(t!=t1)
    {

    bool flag = true;
      
    digitalWrite(trigPinl, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinl, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinl, LOW);
    d = pulseIn(echoPinl, HIGH);
    t = (d/2) / 29.1;

   
   digitalWrite(trigPinr, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPinr, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPinr, LOW);
   d1 = pulseIn(echoPinr, HIGH);
    t1 = (d1/2) / 29.1;
  
    Serial.println(t);
    Serial.println(t1);

    

      
      if(t>t1)
      {
       digitalWrite(motorPin1, HIGH);
       digitalWrite(motorPin2, LOW);
       digitalWrite(motorPin3, HIGH);
       digitalWrite(motorPin4, LOW);
       delay(120);
        fstop();
      }
      else if(t<t1)
      {
       //make the left motor on for some specific delay() ...
       digitalWrite(motorPin1, LOW);
       digitalWrite(motorPin2, HIGH);
       digitalWrite(motorPin3, LOW);
       digitalWrite(motorPin4, HIGH);
       delay(120);
        fstop();
     }

     //put end condition here ...
     if(sleft() && sfront() && sright() && sdial() && sdiar())         //end condition here ...
     {
      s=t;
      s+='3';
      fstop();
      break;
     }


     while((t==t1 )&& flag)
     {
      if(sleft() && sfront() && sright() && sdial() && sdiar())         //end condition here ...
      {
        s=t;
        s+='3';
        fstop();
        flag = false;
      }
      else if(sdial() && !sright())
      {
       digitalWrite(motorPin1, HIGH);
       digitalWrite(motorPin2, LOW);
       digitalWrite(motorPin3, LOW);
       digitalWrite(motorPin4, LOW);
       delay(120);
        fstop();
      }
      else if(sdiar() && !sleft())
      {
       digitalWrite(motorPin1, LOW);
       digitalWrite(motorPin2, LOW);
       digitalWrite(motorPin3, LOW);
       digitalWrite(motorPin4, HIGH);
       delay(120);
        fstop();
      }
      else if(!sdial() && !sdiar())
      {
        flag = false;
      }
     }
     
    }
    finish = millis();
    return 0;
}

/*
void backtrack(String s)
{
    int i=s.length()-1;
  while(i>=0)
  {
    if(s[i]=='3')
    {
      mback();
      fstop();
    }
    else if(s[i]=='4')
    {
      bright();
      fstop();
    }
    else if(s[i]=='2')
    {
      bleft();
      fstop();
    }
    else
      Serial.println("BG");
    i--;
  }

  fstop();
  
}     */

void traverse(String t,int c)
{
  //FOR GOAL CONDITION

  Serial.println(t);
  
  bool hit=false;
  if(sleft() && sfront() && sright() && sdial() && sdiar())         //end condition here ...
  {
   s=t;
   s+='3';
   fstop();
   tone(buzz,2000);
   delay(1000);
   noTone(buzz);
   //hit=true;
   //back(ch);
   //mback();
   return;
  }
  
  if(t.length()>=s.length())      //preventing redundant cases ...
  {
   //back(ch);
   return;
  }
  
  if(sright())                   //checking for left using sonar sensor
  {
    fstop();
    rleft();
    fstop();
    //if(!sleft())
    //c=rectify();
    fstop();
    traverse(t+"4",0);
    fstop();
    bright(0);
    fstop();
  }
  if(sfront())                 //checking for right using the IR sensor
  {
    fstop();
    mfront();
    fstop();
    traverse(t+"3",0);
    fstop();
    mback();
    fstop();
  }
  
  if(sleft())                //checking for right using the sonar sensor
  {
    fstop();
    rright();
    fstop();
    //if(!sright())
    //c=rectify();
    fstop();
    traverse(t+"2",0);
    fstop();
    bleft(0);
    fstop();
  }

}

int follow(String s)
{
  int i=0;
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

  return 1;
}

void setup() 
{
  Serial.begin(9600);
  pinMode(sensorPin,INPUT);
  pinMode(sensorPin1,INPUT);
  pinMode(sensorPin2,INPUT);

  pinMode(trigPinl, OUTPUT);
  pinMode(echoPinl, INPUT);
  
  pinMode(trigPinr, OUTPUT);
  pinMode(echoPinr, INPUT);

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(buzz,OUTPUT);
  
  //rleft();
  //mback();
  //bright();

  traverse(temp,0);

  
  //rectify();
  //mfront();
  //mfront();
  //mfront();

  //rleft();*/
  fstop();

  follow(s);

  //backtrack(s);
}

void loop() 
{
  //int i=0;
  //s="343423"   
  //char ch;
  //s=traverse(s,temp,ch);
  
  //Serial.println(s);
  
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
  //fstop();
  //delay(2000);
  //backtrack(s);
  
}
