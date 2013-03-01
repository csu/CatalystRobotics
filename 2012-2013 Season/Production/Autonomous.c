#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     lightSensor,    sensorLightActive)
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

void initializeRobot() { return; }

task main() {
  initializeRobot();
  //waitForStart();

	motorForDistance(autonomousWheelPower, 6);
	wait10Msec(autonomous10Mdelay);
	encodedTurn(autonomousWheelPower, 0.5);
	wait10Msec(autonomous10Mdelay);
	encodedDiagonal(autonomousWheelPower, 4.35);
	wait10Msec(autonomous10Mdelay);
	encodedTurn(autonomousWheelPower, 0.1);
	wait10Msec(autonomous10Mdelay);
	//motorForDistance(autonomousWheelPower, 0.25);
	//motorStrafeForDistance(autonomousWheelPower, 0.2);
	wait10Msec(autonomous10Mdelay);
	ArmUpDistance(7.2);
	wait10Msec(autonomous10Mdelay);
	while (SensorValue(IRseeker) != 6) {
		writeDebugStreamLine("Sensor: %d", SensorValue(IRseeker));
		if (SensorValue(IRseeker) == 0) {
			if (irStrafeCount % 2 == 1) {
				motorStrafeForDistance(-autonomousWheelPower, 0.2*irStrafeCount);
				irStrafeCount++;
				wait10Msec(irSeekingDelay);
			}
			else if (irStrafeCount % 2 == 0) {
				motorStrafeForDistance(autonomousWheelPower, 0.2*irStrafeCount);
				irStrafeCount++;
				wait10Msec(irSeekingDelay);
			}
			else
				wait10Msec(irSeekingDelay);
		}
		else if (SensorValue(IRseeker) < 6) {
			motorStrafeForDistance(-autonomousWheelPower, 0.2);
			wait10Msec(irSeekingDelay);
		}
		else if (SensorValue(IRseeker) > 6) {
			motorStrafeForDistance(autonomousWheelPower, 0.2);
			wait10Msec(irSeekingDelay);
		}
		else if (SensorValue(IRseeker) == 6) {
			break;
		}
	}
  ArmUp();
  wait10Msec(autonomous10Mdelay);
  motorForDistance(autonomousWheelPower,1);
  wait10Msec(autonomous10Mdelay);
  ArmDownDistance(2);
  wait10Msec(autonomous10Mdelay);
  motorForDistance(-autonomousWheelPower,3);
  wait10Msec(autonomous10Mdelay);
  ArmDown();
}
