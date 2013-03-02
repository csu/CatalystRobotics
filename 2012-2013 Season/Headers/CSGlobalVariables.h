#ifndef GLOBALVARS
#define GLOBALVARS

#define CONTROLLER_A_UPDATE_DELAY 0
#define CONTROLLER_B_UPDATE_DELAY 0
#define MOTOR_UPDATE_DELAY 0
#define SENSOR_UPDATE_DELAY 0

#define JOYSTICK_UPPER_THRESHOLD 15
#define JOYSTICK_LOWER_THRESHOLD -15

#define ARM_TO_TOP_REVOLUTIONS 17
#define ARM_TO_MIDDLE_REVOLUTIONS 8 //guessed, hasn't been tested yet

//autonomous, kept in GlobalVariables so that the Methods header may be use them
int autonomous10Mdelay = 10;
int autonomousWheelPower = 100;
//infrared seeker
int irSeekingDelay = 50;
int irStrafeCount = 1;
int irTarget = 5;
int irLeftRightCount = 0;
int irDecision = 0;
//gyro sensor
float currHeading;
float delTime = 0;
float prevHeading = 0;
float curRate = 0;
// light sensor
int lightForwardIterations = 3;
int currentLight;
int lightSensorThreshold = 35;
int lightStrafeCount = 1;
int lightDelay = 10;
int currentLightForwardIterations = 0;
float lightFineAdjust = 0.025;

//replaced by JOYSTICK_UPPER_THRESHOLD and JOYSTICK_LOWER_THRESHOLD
//int joystickUpperThreshold = 15;
//int joystickLowerThreshold = -15;

//tMotor simultaneousTwoMotorEncodeMotorOne = motor12;
//tMotor simultaneousTwoMotorEncodeMotorTwo = motor22;
//int simultaneousTwoMotorEncodePower = 75;
//float simultaneousTwoMotorEncodeRevolutions = 1;
//float armToTopRevolutions = 17; //replaced by ARM_TO_TOP_REVOLUTIONS
int touchMuxerValue;
bool touchMuxer1, touchMuxer2, touchMuxer3, touchMuxer4; //short or bool?
//int autonomousIRseekerTarget = 4;
//int controllerAMultiplier = 1;
//float motorSpeedFixMultiplier11 = 1;
//float motorSpeedFixMultiplier12 = 1;
//float motorSpeedFixMultiplier21 = 1;
//float motorSpeedFixMultiplier22 = 1;

#endif
