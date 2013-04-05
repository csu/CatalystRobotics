// Created by Christopher Su
// Catalyst Robotics 2012-2013 Season

#include "../Headers/CSGlobalVariables.h"
#include "../Drivers/HTGYRO-driver.h"

#ifndef METHODS
#define METHODS

void CatsAndCorgis() { getJoystickSettings(joystick); }

int Happy(ControllerMeta starfish = CONTROLLER_A, ControllerJoystick twig, ControllerJoystickAxis axe) {
  int temp = 0;

  switch (starfish) {
    case CONTROLLER_A:
      switch (twig) {
        case JOYSTICK_L:
          switch (axe) {
            case AXIS_X:
              temp = joystick.joy1_x1;
              break;
            case AXIS_Y:
              temp = joystick.joy1_y1;
              break;
          }
          break;
        case JOYSTICK_R:
          switch (axe) {
            case AXIS_X:
              temp = joystick.joy1_x2;
              break;
            case AXIS_Y:
              temp = joystick.joy1_y2;
              break;
          }
          break;
      }
      break;

    case CONTROLLER_B:
      switch (twig) {
        case JOYSTICK_L:
          switch (axe) {
            case AXIS_X:
              temp = joystick.joy2_x1;
              break;
            case AXIS_Y:
              temp = joystick.joy2_y1;
              break;
          }
          break;
        case JOYSTICK_R:
          switch (axe) {
            case AXIS_X:
              temp = joystick.joy2_x2;
              break;
            case AXIS_Y:
              temp = joystick.joy2_y2;
              break;
          }
          break;
      }
      break;
  }

  return temp;
}

bool Button(ControllerMeta starfish = CONTROLLER_A, ControllerButton button)
{
  bool pizzaTemp = false;

  switch (starfish) {
    case CONTROLLER_A:
      pizzaTemp = (bool)(joy1Btn(button));
      break;
    case CONTROLLER_B:
      pizzaTemp = (bool)(joy2Btn(button));
      break;
  }

  return pizzaTemp;
}

ControllerHat Hat(ControllerMeta starfish = CONTROLLER_A) {
  ControllerHat temptemp = HAT_NONE;
  switch (starfish) {
    case CONTROLLER_A:
      temptemp = (ControllerHat)joystick.joy1_TopHat;
      break;
    case CONTROLLER_B:
      temptemp = (ControllerHat)joystick.joy2_TopHat;
      break;
  }
  return temptemp;
}

void MotorF(tMotor motorName, int power=75) { motor[motorName] = power; }
void MotorR(tMotor motorName, int power=75) { motor[motorName] = -1 * power; }
void MotorS(tMotor motorName) { motor[motorName] = 0; }

void EncoderTarget(tMotor motorName, int angle) {
  int originalAngle = 0;
  originalAngle = nMotorEncoder[motorName];
  nMotorEncoderTarget[motorName] = angle + originalAngle;
}

int EncoderValue(tMotor motorName) {
  int encoder = 0;
  encoder = nMotorEncoder[motorName];
  return encoder;
}

void encodedTurn(int powerToMoveAt, float revolutions) {
	nMotorEncoder[motor21] = 0;
	while(abs(nMotorEncoder[motor21]) < 1260*revolutions)
	{
		//writeDebugStreamLine("Motor encoder: %d", nMotorEncoder[motor21]);
	  MotorR(motor11, powerToMoveAt);
	  MotorF(motor12, powerToMoveAt);
	  MotorF(motor21, powerToMoveAt);
	  MotorR(motor22, powerToMoveAt);
	}
	motor[motor11] = 0;
	motor[motor21] = 0;
	motor[motor12] = 0;
	motor[motor22] = 0;
}

void EncoderPower(tMotor motorName, int power) { motor[motorName] = power; }
void EncoderReset(tMotor motorName) { nMotorEncoder[motorName] = 0; }

void spinRight() {
		MotorF(motor11, 75);
		MotorR(motor12, 75);
		MotorR(motor21, 75);
		MotorF(motor22, 75);
}

void spinLeft() {
		MotorR(motor11, 75);
		MotorF(motor12, 75);
		MotorF(motor21, 75);
		MotorR(motor22, 75);
}

void spinRightPower(int powerEntered) {
		MotorF(motor11, powerEntered);
		MotorR(motor12, powerEntered);
		MotorR(motor21, powerEntered);
		MotorF(motor22, powerEntered);
}

void spinLeftPower(int powerEntered) {
		MotorR(motor11, powerEntered);
		MotorF(motor12, powerEntered);
		MotorF(motor21, powerEntered);
		MotorR(motor22, powerEntered);
}

void ServoRotate(TServoIndex servoName, short position) { servo[servoName] = position; }
// short ServoValue(TServoIndex servoName) { return ServoValue[servoName]; }
void ServoRate(TServoIndex servoName, int rate) { servoChangeRate[servoName] = rate; }

void Wait(int time) { wait10Msec(time); }

void touchMultiplexerUpdate() {
	touchMuxerValue = SensorValue[S3];
	touchMuxer1 = (bool)(touchMuxerValue & 0x01);
	touchMuxer2 = (bool)(touchMuxerValue & 0x02);
	touchMuxer3 = (bool)(touchMuxerValue & 0x03);
	touchMuxer4 = (bool)(touchMuxerValue & 0x04);
}

void ArmUp() {
	nMotorEncoder[motorArm] = 0;
	while((nMotorEncoder[motorArm] < 1260*ARM_TO_TOP_REVOLUTIONS) && !touchMuxer2)
	{
		touchMultiplexerUpdate();
		//writeDebugStreamLine("Arm Encoder: %d", nMotorEncoder[motorArm]);
	  motor[motorArm] = 75;
	}
	motor[motorArm] = 0;
}

void ArmDown() {
	nMotorEncoder[motorArm] = 0;
	while((nMotorEncoder[motorArm] > -1260*ARM_TO_TOP_REVOLUTIONS) && !touchMuxer1)
	{
		touchMultiplexerUpdate();
		//writeDebugStreamLine("Arm Encoder: %d", nMotorEncoder[motorArm]);
	  motor[motorArm] = -75;
	}
	motor[motorArm] = 0;
}

void motorForwardForDistance(int powerToMoveAt, float revolutions) {
	nMotorEncoder[motor12] = 0;
	while(nMotorEncoder[motor12] < 1260*revolutions) //It may seem like motor12 refers to motor controller 1, motor 2, but it ACTUALLY refers to motor controller 1, motor 1
	{
		//writeDebugStreamLine("Motor Encoder: %d", nMotorEncoder[motor22]);
	  motor[motor12] = powerToMoveAt;
	  motor[motor22] = powerToMoveAt;
	}
	motor[motor12] = 0;
	motor[motor22] = 0;
}

void motorBackwardForDistance(int powerToMoveAt, float revolutions) {
	nMotorEncoder[motor12] = 0;
	while(nMotorEncoder[motor12] > -1260*revolutions)
	{
		//writeDebugStreamLine("Motor Encoder: %d", nMotorEncoder[motor22]);
	  motor[motor12] = -powerToMoveAt;
	  motor[motor22] = -powerToMoveAt;
	}
	motor[motor12] = 0;
	motor[motor22] = 0;
}

void motorForDistance(int powerToMoveAt, float revolutions) {
	nMotorEncoder[motor12] = 0;
	while(abs(nMotorEncoder[motor12]) < 1260*revolutions)
	{
		//writeDebugStreamLine("Motor encoder: %d", nMotorEncoder[motor12]);
	  motor[motor12] = powerToMoveAt;
	  motor[motor22] = powerToMoveAt;
	}
	motor[motor12] = 0;
	motor[motor22] = 0;
}

void motorStrafeForDistance(int powerToMoveAt, float revolutions) {
	nMotorEncoder[motor21] = 0;
	while(abs(nMotorEncoder[motor21]) < 1260*revolutions)
	{
		//writeDebugStreamLine("Motor encoder: %d", nMotorEncoder[motor21]);
	  motor[motor11] = powerToMoveAt;
	  motor[motor21] = powerToMoveAt;
	}
	motor[motor11] = 0;
	motor[motor21] = 0;
}

void encodedDiagonal(int powerToMoveAt, float revolutions) {
	nMotorEncoder[motor21] = 0;
	while(abs(nMotorEncoder[motor21]) < 1260*revolutions)
	{
		//writeDebugStreamLine("Motor encoder: %d", nMotorEncoder[motor21]);
	  motor[motor11] = powerToMoveAt;
	  motor[motor21] = powerToMoveAt;
	  motor[motor12] = powerToMoveAt;
	  motor[motor22] = powerToMoveAt;
	}
	motor[motor11] = 0;
	motor[motor21] = 0;
	motor[motor12] = 0;
	motor[motor22] = 0;
}

void specifyTwoMotorsForDistance(tMotor specifiedMotor, tMotor specifiedMotorTwo, int powerToMoveAt, float revolutions) {
	nMotorEncoder[specifiedMotor] = 0;
	while(abs(nMotorEncoder[specifiedMotor]) < 1260*revolutions)
	{
		//writeDebugStreamLine("Motor Encoder: %d", nMotorEncoder[motor22]);
	  motor[specifiedMotor] = powerToMoveAt;
	  motor[specifiedMotorTwo] = powerToMoveAt;
	}
	motor[specifiedMotor] = 0;
	motor[specifiedMotorTwo] = 0;
}

void ArmDownDistance(float revolutions) {
	nMotorEncoder[motorArm] = 0;
	while(nMotorEncoder[motorArm] > -1260*revolutions && !touchMuxer1)
	{
		touchMultiplexerUpdate();
		//writeDebugStreamLine("Arm Encoder: %d", nMotorEncoder[motorArm]);
	  motor[motorArm] = -75;
	}
	motor[motorArm] = 0;
}

void ArmUpDistance(float revolutions) {
	nMotorEncoder[motorArm] = 0;
	while(nMotorEncoder[motorArm] < 1260*revolutions && !touchMuxer2)
	{
		touchMultiplexerUpdate();
		//writeDebugStreamLine("Arm Encoder: %d", nMotorEncoder[motorArm]);
	  motor[motorArm] = 100;
	}
	motor[motorArm] = 0;
}

void gyroCompensate() {
	while (!((currHeading > 358) && (currHeading < 2))) {
		if ((currHeading > 180) && (currHeading < 358)) {
			//encodedTurn(25, 0.02);
			spinLeftPower(20);
			//wait10Msec(10);
		}
		else if ((currHeading > 2) && (currHeading < 181)) {
			//encodedTurn(-25, 0.02);
			spinRightPower(20);
			//wait10Msec(10);
		}
		else
			break;
	}
}

void gyroTurn(int destination) {
	while (!((currHeading > (destination-2)) && (currHeading < (destination+2)))) {
		if ((currHeading > ((360-destination)/2)) && (currHeading < (destination-2))) {
			//encodedTurn(25, 0.02);
			spinLeftPower(20);
			//wait10Msec(10);
		}
		else if ((currHeading > (destination+2)) && (currHeading < (((360-destination)/2)+1))) {
			//encodedTurn(-25, 0.02);
			spinRightPower(20);
			//wait10Msec(10);
		}
		else
			break;
	}
}

#endif
