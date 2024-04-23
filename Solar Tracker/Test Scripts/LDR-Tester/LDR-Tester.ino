#define LDRpin A0
#include <Servo.h>
int LDRValue = 0;

Servo limitservo;
Servo contservo;

void setup()
{
  Serial.begin(9600);
  limitservo.attach(10);
  contservo.attach(9);
}

void limitservonegwalk(){
  LDRValue = analogRead(LDRpin);
  for (int degree = 180; degree <= 180; degree -= 11.25){
    limitservo.write(degree);
    delay(1000);
  }
  limitservo.write(180);
  delay(10);
}

void limitservoposwalk(){
  LDRValue = analogRead(LDRpin);
  for (int angle = 0; angle <= 180; angle += 11.25){
    limitservo.write(angle);
    delay(1000);
  }
  limitservo.write(0);
  delay(10);
}

void loop()
{
  LDRValue = analogRead(LDRpin);
  Serial.println(LDRValue);
  delay(2);

  if(LDRValue <= 200){
    contservo.write(90);
    contservo.write(180);
    for (int angle = 0; angle <= 180; angle += 11.25){
      limitservo.write(angle);
      delay(100);
    }
    limitservo.write(0);
    delay(10);
  }
  if(LDRValue >= 200){
    contservo.write(90);
    contservo.write(-180);
    for (int degree = 180; degree >= 0; degree -= 11.25){
      limitservo.write(degree);
      delay(100);
    }
    limitservo.write(180);
    delay(10);
  }
}