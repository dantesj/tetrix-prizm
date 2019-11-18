
  
#include <PRIZM.h> // include the PRIZM library in the sketch
PRIZM prizm;      // initiate a PRIZM object "prizm" so we can use its functions


bool ClawsClosed = false;

void setup() {

prizm.PrizmBegin();           // initiate the PRIZM controller
prizm.setServoSpeed(2,40);     // set servo 1 speed to 25%
prizm.setServoPosition(5,80);     // set the servo positiin to 80 degrees for the claws to open
prizm.setMotorInvert(2,1);     //set the wheels to go at the same direction
}

void loop() {  //repeat in a loop

if (prizm.readSonicSensorCM(3) < 3 && ClawsClosed ==false){  // 3cm far from the robot claws closed
  closeClaws();
  ClawsClosed = true;
}
FollowLine();
}



void FollowLine(){
 if (prizm.readLineSensor(2) ==HIGH){ //sees the line 
  prizm.setMotorPowers(15,25);  // the goes to left
  prizm.setRedLED(HIGH);  // red ligth goes on
 }
 
 if (prizm.readLineSensor(2) ==LOW) { // doesnt sees the line
 prizm.setMotorPowers(25,15); //goes to right
 prizm.setRedLED(LOW);} // red light goes off

}

void closeClaws(){
 prizm.setServoPosition(5,20); //the claw closes
}
