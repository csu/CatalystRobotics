#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Sensor, S2,     tardis,         sensorSONAR)
#pragma config(Motor,  motorA,          nxtMotorA,     tmotorNormal, openLoop)
#pragma config(Motor,  motorB,          nxtMotorB,     tmotorNormal, openLoop)
#pragma config(Motor,  motorC,          ,              tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorL,        tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorR,        tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorScsL,     tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorScsR,     tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorArmL,     tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorArmR,     tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoContinuousRotation)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#include "JoystickDriver.c"  //le joystick things
//#include "EpicBM.c" //le epic bm
//#include "drivers/HTGYRO-driver.c"
short caseyIsTall = 5; //value which is used to do stuff
int distance_in_cm = 30;   // Create variable 'distance_in_cm' and initialize it to 30(cm).
short alexLikesMenRoof = 120;
short alexLikesMenFloor = 230;

//gryo stuff
/*int Gyro_threshold = 2;      // ignore gyro values less than threshold
float Gyro_offset;           //**offset value may vary depending on sensor & temperature
long Gyro_value;             //current read
long sum;
int degrees;
*/
void turnRight(short s)
{
  motor[motorL] = 50;
  motor[motorR] = -50;
  wait10Msec(s+s*.1);
  motor[motorL] = 0;
  motor[motorR] = 0;
}

void turnLeft(short s)
{
  motor[motorL] = -50;
  motor[motorR] = 50;
  wait10Msec(s+s*.1);
  motor[motorL] = 0;
  motor[motorR] = 0;
}

void moveForward(short s)
{
  motor[motorL] = 50;
  motor[motorR] = 50;
  wait10Msec(s);
  motor[motorL] = 0;
  motor[motorR] = 0;
}

void moveBack(short s)
{
  motor[motorL] = -50;
  motor[motorR] = -50;
  wait10Msec(s);
  motor[motorL] = 0;
  motor[motorR] = 0;
}

void buttbutt(short s)
{
  motor[motorL] = -100;
  motor[motorR] = -100;
  wait10Msec(s);
  motor[motorL] = 0;
  motor[motorR] = 0;
}

void Autonomous() //le autonomous method
// @(^~^)@ O.o >.< T_T -_- DANA'S MONKEY AND OTHER STUFFS
{
  while(SensorValue[tardis] > distance_in_cm)   /* While the Sonar Sensor readings are greater */
  {                                                 /* than the specified, 'distance_in_cm':       */
    motor[motorL] = -75;                     // Motor B is run at a 75 power level
    motor[motorR] = -75;                     // Motor C is run at a 75 power level
  }
  buttbutt(50);

  turnRight(120);

  while(SensorValue[tardis] > distance_in_cm)   /* While the Sonar Sensor readings are greater */
  {                                                 /* than the specified, 'distance_in_cm':       */
    motor[motorL] = -75;                     // Motor B is run at a 75 power level
    motor[motorR] = -75;                     // Motor C is run at a 75 power level
  }
  buttbutt(50);

  turnLeft(30);

  while(SensorValue[tardis] > distance_in_cm)   /* While the Sonar Sensor readings are greater */
  {                                                 /* than the specified, 'distance_in_cm':       */
    motor[motorL] = -75;                     // Motor B is run at a 75 power level
    motor[motorR] = -75;                     // Motor C is run at a 75 power level
  }
  buttbutt(50);

  moveForward(50);
  turnRight(60);
  while(SensorValue[tardis] > distance_in_cm)   /* While the Sonar Sensor readings are greater */
  {                                                 /* than the specified, 'distance_in_cm':       */
    motor[motorL] = -75;                     // Motor B is run at a 75 power level
    motor[motorR] = -75;                     // Motor C is run at a 75 power level
  }
}

void boxTest()
{
  //moveBack(100);
  while(SensorValue[tardis] > distance_in_cm)   /* While the Sonar Sensor readings are greater */
  {                                                 /* than the specified, 'distance_in_cm':       */
    motor[motorL] = -75;                     // Motor B is run at a 75 power level
    motor[motorR] = -75;                     // Motor C is run at a 75 power level
  }                                                 /* than the specified, 'distance_in_cm':       */
  motor[motorL] = 0;
  motor[motorR] = 0;

  wait10Msec(300);
  buttbutt(100);
}

task main()
{
  /*Gyro_offset = HTGYROstartCal(tardis);   //start calibration, but do not trust results
  for (int i = 0 ; i < 20; i++)           //instead read 20 values and generate average offset
  {
    sum = sum + HTGYROreadRot(tardis);
    wait1Msec(10);
  }
  Gyro_offset = sum / 20.0;

  sum = 0;
  */

  //Autonomous();
  boxTest();
}
