// Created by Christopher Su
// Catalyst Robotics 2012-2013 Season

#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S2,     gyroSensor,     sensorI2CHiTechnicGyro)
#pragma config(Sensor, S3,     touchMuxer,     sensorHiTechnicTouchMux)
#pragma config(Sensor, S4,     IRseeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     motor12,       tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motor11,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motor21,       tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motor22,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorArm,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma DebuggerWindows("debugStream")

#include "JoystickDriver.c"
#include "../Headers/CSEnumerated.h"
#include "../Headers/CSMethods.h"

void initializeRobot() {
	return;
}

task main() {
  initializeRobot();
  //waitForStart();

	motorForDistance(autonomousWheelPower, 6.4);
	wait10Msec(autonomous10Mdelay);
	encodedTurn(autonomousWheelPower, 0.5);
	wait10Msec(autonomous10Mdelay);
	encodedDiagonal(autonomousWheelPower, 4.3);
	wait10Msec(autonomous10Mdelay);
	encodedTurn(autonomousWheelPower, 0.1);
	wait10Msec(autonomous10Mdelay);
	motorForDistance(-autonomousWheelPower, 0.10);
	motorStrafeForDistance(autonomousWheelPower, 0.25);
	wait10Msec(autonomous10Mdelay);
	/*
	while (currentLightForwardIterations < lightForwardIterations) {
		currentLight = SensorValue(lightSensor);
		writeDebugStreamLine("Sensor: %d", currentLight);
		if (currentLight < lightSensorThreshold) { //-5) || (currentLight > lightSensorThreshold+5)) {
			if (lightStrafeCount % 2 == 1) {
				motorStrafeForDistance(autonomousWheelPower, lightFineAdjust);
				//lightStrafeCount++;
				wait10Msec(lightDelay);
			}
			else if (lightStrafeCount % 2 == 0) {
				motorStrafeForDistance(-autonomousWheelPower, lightFineAdjust);
				//lightStrafeCount++;
				wait10Msec(lightDelay);
			}
		}
		else {
			motorForDistance(autonomousWheelPower, lightFineAdjust);
			//lightStrafeCount = 1;
			lightForwardIterations++;
			wait10Msec(lightDelay);
		}
	}
	*/
	ArmUpDistance(7.2);
	wait10Msec(autonomous10Mdelay);
	while (SensorValue(IRseeker) != irTarget) {
		writeDebugStreamLine("Sensor: %d", SensorValue(IRseeker));
		if (SensorValue(IRseeker) == 0) {
			if (irStrafeCount % 2 == 1) {
				motorStrafeForDistance(-autonomousWheelPower, 0.2*irStrafeCount);
				irStrafeCount++;
				wait10Msec(irSeekingDelay);
			}
			else if (irStrafeCount % 2 == 0) {
				//motorStrafeForDistance(autonomousWheelPower, 0.2*irStrafeCount);
				irStrafeCount++;
				wait10Msec(irSeekingDelay);
			}
			else
				wait10Msec(irSeekingDelay);
		}
		else if (SensorValue(IRseeker) < irTarget) {
			motorStrafeForDistance(-autonomousWheelPower, 0.2);
			irLeftRightCount--;
			wait10Msec(irSeekingDelay);
		}
		else if (SensorValue(IRseeker) > irTarget) {
			motorStrafeForDistance(autonomousWheelPower, 0.2);
			irLeftRightCount++;
			wait10Msec(irSeekingDelay);
		}
		else if (SensorValue(IRseeker) == irTarget) {
			break;
		}
	}
	if (irLeftRightCount >= 0)
		motorStrafeForDistance(autonomousWheelPower, 0.25);
	else if (irLeftRightCount < 0)
		motorStrafeForDistance(-autonomousWheelPower, 0.35);
  ArmUp();
  wait10Msec(autonomous10Mdelay);
  motorForDistance(autonomousWheelPower,1.5);
  wait10Msec(autonomous10Mdelay);
  ArmDownDistance(2);
  wait10Msec(autonomous10Mdelay);
  motorForDistance(-autonomousWheelPower,3);
  wait10Msec(autonomous10Mdelay);
  ArmDown();
}
