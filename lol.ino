/*  PRIZM Controller example program
 *  This program sets the speed of servo 1 to 25%.
 *  Servo 1 is then rotated back and forth between 0 and 180 degree range.
 *  author PWU on 08/05/2016
*/

#include <PRIZM.h>    // include the PRIZM library in the sketch
PRIZM prizm;          // instantiate a PRIZM object “prizm” so we can use its functions

void setup() {

  prizm.PrizmBegin();         // initialize the PRIZM controller
  prizm.setServoSpeed(1,5);  // set servo 1 speed to 25%
  prizm.setMotorInvert(2,1);
  prizm.setServoPosition(5,90);
}

void loop() {     // repeat in a loop
 if(prizm.readSonicSensorCM(3) > 10){
   prizm.setMotorPowers(125,125); 
   prizm.setServoPosition(5,45);
     delay(2000);}
 if
  (prizm.readLineSensor(2)==HIGH){
    prizm.setMotorPowers(30,20);
    prizm.setRedLED(HIGH);}
    
 if
  (prizm.readLineSensor(2) ==LOW){
        prizm.setMotorPowers(20,30);
        prizm.setRedLED(LOW);}
      
    else{
      prizm.setMotorPowers(2,2);
    }
    
    }
  
