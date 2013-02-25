#include "../Headers/CSGlobalVariables.h"

#ifndef METHODS
#define METHODS

void CatsAndCorgis() { getJoystickSettings(joystick); }

int Happy(ControllerMeta starfish = CONTROLLER_A, ControllerJoystick twig, ControllerJoystickAxis axe) {
  // ex. Happy(CONTROLLER_A, JOYSTICK_L, AXIS_Y);
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

void EncoderPower(tMotor motorName, int power) { motor[motorName] = power; }
void EncoderReset(tMotor motorName) { nMotorEncoder[motorName] = 0; }

void spinRight() {
		MotorF(motor11, 50);
		MotorR(motor12, 50);
		MotorR(motor21, 50);
		MotorF(motor22, 50);
}

void spinLeft() {
		MotorR(motor11, 50);
		MotorF(motor12, 50);
		MotorF(motor21, 50);
		MotorR(motor22, 50);
}

void ServoRotate(TServoIndex servoName, short position) { servo[servoName] = position; }
// short ServoValue(TServoIndex servoName) { return ServoValue[servoName]; }
void ServoRate(TServoIndex servoName, int rate) { servoChangeRate[servoName] = rate; }

void Wait(int time) { wait10Msec(time); }

void touchMultiplexerUpdate() {
	touchMuxerValue = SensorValue[S3];
	touchMuxer1 = (touchMuxerValue & 0x01);
	touchMuxer2 = (touchMuxerValue & 0x02);
	touchMuxer3 = (touchMuxerValue & 0x03);
	touchMuxer4 = (touchMuxerValue & 0x04);
}

void ArmUp() {
	nMotorEncoder[motorArm] = 0;
	while((nMotorEncoder[motorArm] < 1260*armToTopRevolutions) && !touchMuxer2)
	{
		touchMultiplexerUpdate();
		//writeDebugStreamLine("Arm Encoder: %d", nMotorEncoder[motorArm]);
	  motor[motorArm] = 75;
	}
	motor[motorArm] = 0;
}

void ArmDown() {
	nMotorEncoder[motorArm] = 0;
	while((nMotorEncoder[motorArm] > -1260*armToTopRevolutions) && !touchMuxer1)
	{
		touchMultiplexerUpdate();
		//writeDebugStreamLine("Arm Encoder: %d", nMotorEncoder[motorArm]);
	  motor[motorArm] = -75;
	}
	motor[motorArm] = 0;
}

void motorForwardForDistance(int powerToMoveAt, float revolutions) {
	nMotorEncoder[motor12] = 0;
	nMotorEncoder[motor22] = 0;
	while(nMotorEncoder[motor22] < 1260*revolutions)
	{
		//writeDebugStreamLine("Motor Encoder: %d", nMotorEncoder[motor22]);
	  motor[motor12] = powerToMoveAt;
	  motor[motor22] = powerToMoveAt;
	}
	motor[motor12] = 0;
	motor[motor22] = 0;
}

void motorBackwardForDistance(int powerToMoveAt, float revolutions) {
	nMotorEncoder[motor22] = 0;
	while(nMotorEncoder[motor22] > -1260*revolutions)
	{
		//writeDebugStreamLine("Motor Encoder: %d", nMotorEncoder[motor22]);
	  motor[motor12] = -powerToMoveAt;
	  motor[motor22] = -powerToMoveAt;
	}
	motor[motor12] = 0;
	motor[motor22] = 0;
}

void motorForDistance(int powerToMoveAt, float revolutions) {
	nMotorEncoder[motor22] = 0;
	while(abs(nMotorEncoder[motor22]) < 1260*revolutions)
	{
		//writeDebugStreamLine("Motor Encoder: %d", nMotorEncoder[motor22]);
	  motor[motor12] = powerToMoveAt;
	  motor[motor22] = powerToMoveAt;
	}
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
		writeDebugStreamLine("Arm Encoder: %d", nMotorEncoder[motorArm]);
	  motor[motorArm] = -75;
	}
	motor[motorArm] = 0;
}

void ArmUpDistance(float revolutions) {
	nMotorEncoder[motorArm] = 0;
	while(nMotorEncoder[motorArm] < 1260*revolutions && !touchMuxer2)
	{
		touchMultiplexerUpdate();
		writeDebugStreamLine("Arm Encoder: %d", nMotorEncoder[motorArm]);
	  motor[motorArm] = 100;
	}
	motor[motorArm] = 0;
}

void holonomicEncodedStrafe(float power, float revolutions) {
	nMotorEncoder[motor11] = 0;
	while(abs(nMotorEncoder[motor11]) < 1260*revolutions)
	{
		//writeDebugStreamLine("Arm Encoder: %d", nMotorEncoder[motorArm]);
		MotorF(motor12, power);
		MotorF(motor22, power);
		MotorF(motor11, power);
		MotorF(motor21, power);
	}
	MotorS(motor12);
	MotorS(motor22);
	MotorS(motor11);
	MotorS(motor21);
}

void holonomicEncodedForward(float power, float revolutions) {
	nMotorEncoder[motor11] = 0;
	while(abs(nMotorEncoder[motor11]) < 1260*revolutions)
	{
		//writeDebugStreamLine("motor11 Encoder: %d", nMotorEncoder[motor11]);
		//writeDebugStreamLine("Arm Encoder: %d", nMotorEncoder[motorArm]);
		MotorF(motor12, power);
		MotorF(motor22, power);
		MotorF(motor11, -power);
		MotorF(motor21, -power);
	}
	MotorS(motor12);
	MotorS(motor22);
	MotorS(motor11);
	MotorS(motor21);
}

void holonomicEncodedSpinLeft(float power, float revolutions) {
	nMotorEncoder[motor11] = 0;
	while(abs(nMotorEncoder[motor11]) < 1260*revolutions)
	{
		//writeDebugStreamLine("motor11 Encoder: %d", nMotorEncoder[motor11]);
		//writeDebugStreamLine("Arm Encoder: %d", nMotorEncoder[motorArm]);
		MotorF(motor11, power);
		MotorR(motor12, power);
		MotorR(motor21, power);
		MotorF(motor22, power);
	}
	MotorS(motor12);
	MotorS(motor22);
	MotorS(motor11);
	MotorS(motor21);
}

void holonomicEncodedSpinRight(float power, float revolutions) {
	nMotorEncoder[motor11] = 0;
	while(abs(nMotorEncoder[motor11]) < 1260*revolutions)
	{
		//writeDebugStreamLine("motor11 Encoder: %d", nMotorEncoder[motor11]);
		//writeDebugStreamLine("Arm Encoder: %d", nMotorEncoder[motorArm]);
		MotorR(motor11, power);
		MotorF(motor12, power);
		MotorF(motor21, power);
		MotorR(motor22, power);
	}
	MotorS(motor12);
	MotorS(motor22);
	MotorS(motor11);
	MotorS(motor21);
}

task simultaneousTwoMotorEncodeOne() {
	writeDebugStreamLine("Task one started");
	nMotorEncoder[simultaneousTwoMotorEncodeMotorOne] = 0;
	while(abs(nMotorEncoder[simultaneousTwoMotorEncodeMotorOne]) < 1260*simultaneousTwoMotorEncodeRevolutions) {
		motor[simultaneousTwoMotorEncodeMotorOne] = simultaneousTwoMotorEncodePower;
	}
	motor[simultaneousTwoMotorEncodeMotorOne] = 0;
	writeDebugStreamLine("Task one done");
	StopTask(simultaneousTwoMotorEncodeOne);
}

task simultaneousTwoMotorEncodeTwo() {
	writeDebugStreamLine("Task two started");
	nMotorEncoder[simultaneousTwoMotorEncodeMotorTwo] = 0;
	while(abs(nMotorEncoder[simultaneousTwoMotorEncodeMotorTwo]) < 1260*simultaneousTwoMotorEncodeRevolutions) {
		motor[simultaneousTwoMotorEncodeMotorTwo] = simultaneousTwoMotorEncodePower;
	}
	motor[simultaneousTwoMotorEncodeMotorTwo] = 0;
	writeDebugStreamLine("Task two done");
	StopTask(simultaneousTwoMotorEncodeTwo);
}

void simultaneousTwoMotorEncode(tMotor x, tMotor y, int power, float revs) {
	writeDebugStreamLine("Starting task launch method");
	simultaneousTwoMotorEncodeMotorOne = x;
	simultaneousTwoMotorEncodeMotorTwo = y;
	simultaneousTwoMotorEncodePower = power;
	simultaneousTwoMotorEncodeRevolutions = revs;
	writeDebugStreamLine("Set global variables in task lauch method");
	StartTask(simultaneousTwoMotorEncodeOne);
	StartTask(simultaneousTwoMotorEncodeTwo);
	writeDebugStreamLine("Done");
}

#endif
