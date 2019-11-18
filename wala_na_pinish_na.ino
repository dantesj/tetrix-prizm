  `#include<PRIZM.h>
PRIZM prizm;
void setup() {
  // put your setup code here, to run once:
prizm.PrizmBegin();
prizm.setMotorInvert(2,1);
prizm.setServoSpeed(1,25);
}

void loop() {
  // put your main code here, to run repeatedly:
prizm.setGreenLED(HIGH);
delay(500);
prizm.setGreenLED(HIGH);
delay(500);
prizm.setGreenLED(LOW);
delay(500);
prizm.setGreenLED(HIGH);
delay(500);
prizm.setGreenLED(LOW);
delay(500);

// Arm
prizm.setServoPosition(1,7);
delay(1500);

//Motors
prizm.setMotorPowers(30,30);
delay(300);
prizm.setMotorPowers(15,30);
delay(1000);
prizm.setMotorPowers(30,30);
delay(700);
prizm.setMotorPowers(30,20);
delay(1000);
prizm.setMotorPowers(30,30);
delay(500);
prizm.setMotorPowers(20,20);
delay(500);
prizm.setMotorPowers(10,10);
delay(400);
prizm.setMotorPowers(0,0);
delay(400);
//Leds
prizm.setGreenLED(HIGH);
delay(1500);
prizm.setRedLED(LOW);
delay(1500);
prizm.setRedLED(HIGH);
delay(1500);
prizm.setGreenLED(LOW);
delay(1500);
// end arm signal
prizm.setServoPosition(1,7);
delay(1500);

prizm.PrizmEnd();

}
