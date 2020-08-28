#include <Servo.h>
Servo myservo
#define RM1 6
#define RM2 7
#define LM1 9
#define LM2 8
#define LMP 10
#define RMP 5
#define WL 300
#define BL 500
char rea;
int s1,s2,s3,t1,t2,t3;


void move_forward()
{analogWrite(RM1,128);
analogWrite(RM2,0);
analogWrite(LM1,128);
analogWrite(LM2,0);
digitalWrite(RM1,HIGH);
digitalWrite(RM2,LOW);
digitalWrite(LM1,HIGH);
digitalWrite(LM2,LOW);
}
void move_stop()
{analogWrite(RM1,0);
analogWrite(RM2,0);
analogWrite(LM1,0);
analogWrite(LM2,0);
digitalWrite(RM1,LOW);
digitalWrite(RM2,LOW);
digitalWrite(LM1,LOW);
digitalWrite(LM2,LOW);
}
void move_backward()
{analogWrite(RM1,0);
analogWrite(RM2,128);
analogWrite(LM1,0);
analogWrite(LM2,128);
digitalWrite(RM1,LOW);
digitalWrite(RM2,HIGH);
digitalWrite(LM1,LOW);
digitalWrite(LM2,HIGH);
}
void move_right()
{analogWrite(RM1,0);
analogWrite(RM2,0);
analogWrite(LM1,128);
analogWrite(LM2,0);
digitalWrite(RM1,LOW);
digitalWrite(RM2,LOW);
digitalWrite(LM1,HIGH);
digitalWrite(LM2,LOW);
}
void move_left()
{analogWrite(RM1,128);
analogWrite(RM2,0);
analogWrite(LM1,0);
analogWrite(LM2,0);
digitalWrite(RM1,HIGH);
digitalWrite(RM2,LOW);
digitalWrite(LM1,LOW);
digitalWrite(LM2,LOW);
}
void automatic();
{
  while(1){
  s1=analogRead(A0);
  s2=analogRead(A1);
  s3=analogRead(A2);
  if(s1>500 && s2<300 && s3>500)
  move_forward();
  if(s1<300 && s2<300 && s3<300)
  move_forward();
  if(s1<300 && s2>500 && s2>500)
  move_right();
  if(s1>500 && s2>500 && s3<300)
  move_left():
  if(s1>500 && s2<300 && s3<300)
  move_left();
  if(s1<300 && s2<300 && s3>500)
  move_right();
  if(s1>500 && s2>500 && s3>500){
    if(t1<300)
    move_left();
    else if(t3<300)
    move_right();
  }
  t1=s1;
  t2=s2;
  t3=s3;
 
  
  }}
void setup() {
  // put your setup code here, to run once
Serial.begin(9600);
pinMode(LM1,OUTPUT);
pinMode(LM2,OUTPUT);
pinMode(RM1,OUTPUT);
pinMode(RM2,OUTPUT);
pinMode(LMP,OUTPUT);
pinMode(RMP,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial.available)
  {rea=Serial.read;
  if(rea=='F')
  move_forward();
  if(rea=='B')
  move_backward();
  if(rea=='S')
  move_stop();
  if(rea=='R')
  move_right();
  if(rea=='L')
  move_left();
  if(rea=='A')
  }
  }
