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
