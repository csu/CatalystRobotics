// Created by Christopher Su
// Catalyst Robotics 2012-2013 Season

#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     IRsensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,          nxtMotorA,     tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          nxtMotorB,     tmotorNXT, openLoop)
#pragma config(Motor,  motorC,          nxtMotorB,     tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motor11,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motor12,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motor21,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorArm,      tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
#include "../Headers/CSEnumerated.h"
#include "../Headers/CSGlobalVariables.h"
#include "../Headers/CSMethods.h"

void initializeRobot() { return; }

task main() {
  initializeRobot();
  for (int i=0; ; i++) {
  	CatsAndCorgis();
  	MotorF(motorArm, 150);
  }
}
