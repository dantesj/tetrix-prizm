/* Example Sketch demonstrating how to control two TETRIX TorqueNADO DC motors using a SONY PS4 gaming controller.
 * Motor Channel 1 is controlled by PS4 Left Joystick Y axis
 * Motor Channel 2 is controlled by PS4 Right Joystick Y axis
 * Hardware: TETRIX PRIZM, TeleOp module and SONY PS4 gaming controller.
 * Date: 09/26/2018
 * Author: PWU
 */



#include <TELEOP.h>   // TETRIX TeleOp module Library
#include <PRIZM.h>    // TETRIX PRIZM Library

PRIZM prizm;          // Create an instance within the PRIZM Library class named prizm
PS4 ps4;              // ps4 controller connect to the robot

int PowerM1;          // Channel 1 Motor Power 
int PowerM2;          // Channel 2 Motor Power


void setup() {

  prizm.PrizmBegin();            // Intializes the PRIZM controller and waits here for press of green start button
  ps4.setDeadZone (LEFT,10);     // Sets a Left Joystick Dead Zone axis range of +/- 10 about center stick
  ps4.setDeadZone(RIGHT,10);     // Sets a Right Joystick Dead Zone axis range of +/- 10 about center stick
  prizm.setServoSpeed(1,5);     // sets the servo to port 5
  prizm.setServoPosition(5,90);    //set the servo position to 90 degrees for the claw 
   prizm.setServoPosition(2,90);   // set the servo position to 90 degrees for the flag
  prizm.setMotorInvert(2,1);    // sets the motor to invert
  Serial.begin(115200);
}

void loop() {
  ps4.getPS4();  
   if (prizm.readSonicSensorCM(3) < 5 ) {  // sets to port 3 and it sense thing within 5cm   
    ps4.setRumble(SLOW); // the rumble goes slow 
   } 
   else 
    if (prizm.readSonicSensorCM(3) < 15 ) { // sets to port 3 and it sense thing within 15cm  
      ps4.setRumble(FAST); // rumble goes fast
    }
   else {
      ps4.setRumble(STOP); // rumble stops
   }
   
  if(ps4.Connected){                            // If PS4 controller has been succesfully connected, control motors
      PowerM1 = ps4.Motor(LY);                  // Power (speed) and direction of Motor 1 is set by position of Left Y-axis Joystick
      PowerM2 = ps4.Motor(RY);                  // Power (speed) and direction of Motor 2 is set by position of Right Y-axis Joystick
      prizm.setMotorPowers(PowerM1, PowerM2);   // set motor output power levels for PRIZM DC motor channels 1 and 2
    
  } 
  
  else{                                      
      prizm.setMotorPowers(0,0);   // the motors slow stop
  }
     
  if (ps4.Button(R2) == true ){  // if the R2 is clicked 
        CloseServoArms();    // the claw closes
  }
  if (ps4.Button(L2) == true){  // if the L2 is clicked 
        OpenServoArms();        // the claw opens
     }
  if (ps4.Button(DOWN) == true ) {  // if the down botton is clicked 
       HiMyDude();   // the flag servo moves
  }
 
}

void CloseServoArms(){
prizm.setServoPosition(5,45);  // sets servo position to 45 degrees
}
void  OpenServoArms(){
prizm.setServoPosition(5,90);   // sets servo position to 90 degrees
}
void HiMyDude(){
prizm.setServoPosition(2,60);  // sets servo position to 60 degrees
}
