#include <Servo.h>


Servo contservo;  // create servo object to control a servo
Servo limitservo;

// twelve servo objects can be created on most boards


int pos = 0;    // variable to store the servo position
int run = 1;

void setup() {

  contservo.attach(9);  // attaches the servo on pin 9 to the servo object
  limitservo.attach(10);

}

void contservocode() {
  int spins = 0;
  while(spins <= 3){
    contservo.write(180);
    delay(3000);
    contservo.write(-180);
    delay(3000);
    spins += 1;
  }
  contservo.write(90);
}

void testcontcode() {
  int turns = 0;
  while(turns <= 10){
    contservo.write(180);
    delay(1000);
    turns += 1;
  }
  contservo.write(90);
}

void contservostart(){
  contservo.write(180);
  delay(5000);
}

void contservostop(){
  contservo.write(90);
  delay(2500);
}

void connected(){
  int rounds = 0;
  contservostart();
  while(rounds <= 5){
    for (int degree = 0; degree <= 190; degree += 11.25) {
      limitservo.write(degree);
      delay(1000);
    }
    limitservo.write(0);
    contservostop();
    rounds ++;
  }
}

void limitservocode() {
  int times = 0;
  while(times <=3){
    for (int angle = 0; angle <= 180; angle += 11.25) {
      limitservo.write(angle);
      delay(1000);
    }
    limitservo.write(0);
    delay(1500);
    times += 1;
  }
}

void loop () {

  // contservocode();
  // limitservocode();
  connected();
}

