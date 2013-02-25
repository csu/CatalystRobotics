#ifndef GLOBALVARS
#define GLOBALVARS

tMotor simultaneousTwoMotorEncodeMotorOne = motor12;
tMotor simultaneousTwoMotorEncodeMotorTwo = motor22;
int simultaneousTwoMotorEncodePower = 75;
float simultaneousTwoMotorEncodeRevolutions = 1;
float armToTopRevolutions = 17;
/* int controllerAMultiplier = 1;
float motorSpeedFixMultiplier11 = 1;
float motorSpeedFixMultiplier12 = 1;
float motorSpeedFixMultiplier21 = 1;
float motorSpeedFixMultiplier22 = 1;
*/
int touchMuxerValue;
bool touchMuxer1, touchMuxer2, touchMuxer3, touchMuxer4;
int autonomousIRseekerTarget = 4;

#endif
