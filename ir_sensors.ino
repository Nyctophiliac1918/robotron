#include <SoftwareSerial.h>

//int s1;
int s2,s3;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
//s1=analogRead(A0);
s2=analogRead(A1);
s3=analogRead(A2);
//Serial.println(s1);
Serial.println(s2);
Serial.println(s3);
delay(2000);
}
