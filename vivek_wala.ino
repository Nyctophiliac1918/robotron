#include <SoftwareSerial.h>
#include <Servo.h>
#define RM1 8
#define RM2 9
#define LM1 11
#define LM2 10
#define LMP 4
#define RMP 5
#define WL 500
#define BL 300
Servo myservo;
SoftwareSerial Bluetooth(0,1);
char rea;
int lef,cen,rig,t1,t2,t3;
int pos = 0; 


void move_forward()
{analogWrite(RMP,60);
analogWrite(LMP,50);
digitalWrite(RM1,HIGH);
digitalWrite(RM2,LOW);
digitalWrite(LM1,HIGH);
digitalWrite(LM2,LOW);
}
void move_stop()
{
digitalWrite(RM1,LOW);
digitalWrite(RM2,LOW);
digitalWrite(LM1,LOW);
digitalWrite(LM2,LOW);
}
void move_backward()
{analogWrite(RMP,60);
analogWrite(LMP,50);
digitalWrite(RM1,LOW);
digitalWrite(RM2,HIGH);
digitalWrite(LM1,LOW);
digitalWrite(LM2,HIGH);
}
void move_right()
{analogWrite(RM1,49);
analogWrite(LMP,40);
digitalWrite(RM1,LOW);
digitalWrite(RM2,HIGH);
digitalWrite(LM1,HIGH);
digitalWrite(LM2,LOW);
}
void move_left()
{analogWrite(RMP,49);
analogWrite(LMP,40);
digitalWrite(RM1,HIGH);
digitalWrite(RM2,LOW);
digitalWrite(LM1,LOW);
digitalWrite(LM2,HIGH);
}
void automatic()
{
  while(1){
  lef=analogRead(A0);
  cen=analogRead(A1);
  rig=analogRead(A2);
  if(lef<BL && cen>WL && rig<BL)
  move_forward1();
  if(lef>WL && cen>WL && rig>WL)
  {move_forward1();}
  if(lef<BL && cen<BL && rig>WL)
  move_right1();
  if(lef>WL && cen<BL && rig<BL)
  move_left1();
  if(lef>WL && cen>WL && rig<BL)
  move_left1();
  if(lef<BL && cen>WL && rig>WL)
  move_right1();
  if(lef<BL && cen<BL && rig<BL){
    if(t1>WL)
    move_left1();
    else if(t3>WL)
    move_right1();
  }
  t1=lef;
  t2=cen;
  t3=rig;
  }}
  void move_forward1()
{analogWrite(RMP,38);
analogWrite(LMP,32);
digitalWrite(RM1,HIGH);
digitalWrite(RM2,LOW);
digitalWrite(LM1,HIGH);
digitalWrite(LM2,LOW);
}
void move_backward1()
{analogWrite(RMP,38);
analogWrite(LMP,32);
digitalWrite(RM1,LOW);
digitalWrite(RM2,HIGH);
digitalWrite(LM1,LOW);
digitalWrite(LM2,HIGH);
}
void move_right1()
{analogWrite(RM1,32);
analogWrite(LMP,25);
digitalWrite(RM1,LOW);
digitalWrite(RM2,HIGH);
digitalWrite(LM1,HIGH);
digitalWrite(LM2,LOW);
}
void move_left1()
{analogWrite(RMP,32);
analogWrite(LMP,25);
digitalWrite(RM1,HIGH);
digitalWrite(RM2,LOW);
digitalWrite(LM1,LOW);
digitalWrite(LM2,HIGH);
}

void setup() {
  // put your setup code here, to run once
Bluetooth.begin(9600);
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
  if(Bluetooth.available())
  {//Serial.println('d');
    rea=Bluetooth.read();
  if(rea=='F')
  {move_forward();
  Serial.println('f');}
  if(rea=='B')
  {move_backward();
  Serial.println('b');}
  if(rea=='S')
  {move_stop();
  //Serial.println('s');
  }
  if(rea=='R')
  {move_right();
  Serial.println('r');}
  if(rea=='L')
  {move_left();
  Serial.println('l');}
  if(rea=='W')
  {automatic();
  Serial.println('a');}
  if(rea=='w')
  move_stop();
  }}
