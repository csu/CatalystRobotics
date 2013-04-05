// Created by Christopher Su
// Catalyst Robotics 2012-2013 Season

///////////////// Teleop //////////////////////

	/*
	if (Button(CONTROLLER_A, 2) && Button(CONTROLLER_A, 8))
		controllerAMultiplier = -0.5;
	else if (Button(CONTROLLER_A, 8) && !Button(CONTROLLER_A, 2))
		controllerAMultiplier = -1;
	else if (Button(CONTROLLER_A, 2) && !Button(CONTROLLER_A, 8))
		controllerAMultiplier = 0.5;
	else
		controllerAMultiplier = 1;
	*/
/*
	if (Button(CONTROLLER_A, 8))
		controllerAMultiplier = -1;
	else
		controllerAMultiplier = 1;
*/
/*
	if ((Happy(CONTROLLER_A, JOYSTICK_R, AXIS_Y) > 15) && (Happy(CONTROLLER_A, JOYSTICK_R, AXIS_Y) < 100)) {
		motorSpeedFixMultiplier12 = 0.05;
		motorSpeedFixMultiplier22 = 0.05;
	}
	else if ((Happy(CONTROLLER_A, JOYSTICK_R, AXIS_Y) < -15) && (Happy(CONTROLLER_A, JOYSTICK_R, AXIS_Y) > -100)) {
		motorSpeedFixMultiplier12 = 0.05;
		motorSpeedFixMultiplier22 = 0.05;
	}
	else {
		motorSpeedFixMultiplier11 = 1;
		motorSpeedFixMultiplier12 = 1;
		motorSpeedFixMultiplier21 = 1;
		motorSpeedFixMultiplier22 = 1;
	}
*/

/*
	if (Button(CONTROLLER_A, 2))
		holonomicEncodedForward(25, 0.05);
	else if (Button(CONTROLLER_A, 4))
		holonomicEncodedForward(-25, 0.05);
	else if (Button(CONTROLLER_A, 1))
		holonomicEncodedStrafe(-25, 0.05);
	else if (Button(CONTROLLER_A, 3))
		holonomicEncodedStrafe(25, 0.05);
*/

	//writeDebugStreamLine("12: %d, 22: %d", (Happy(CONTROLLER_A, JOYSTICK_L, AXIS_X)*controllerAMultiplier*motorSpeedFixMultiplier12), (Happy(CONTROLLER_A, JOYSTICK_L, AXIS_X)*controllerAMultiplier*motorSpeedFixMultiplier22));

///////////////// Methods //////////////////////

//task simultaneousTwoMotorEncodeOne() {
//	writeDebugStreamLine("Task one started");
//	nMotorEncoder[simultaneousTwoMotorEncodeMotorOne] = 0;
//	while(abs(nMotorEncoder[simultaneousTwoMotorEncodeMotorOne]) < 1260*simultaneousTwoMotorEncodeRevolutions) {
//		motor[simultaneousTwoMotorEncodeMotorOne] = simultaneousTwoMotorEncodePower;
//	}
//	motor[simultaneousTwoMotorEncodeMotorOne] = 0;
//	writeDebugStreamLine("Task one done");
//	StopTask(simultaneousTwoMotorEncodeOne);
//}

//task simultaneousTwoMotorEncodeTwo() {
//	writeDebugStreamLine("Task two started");
//	nMotorEncoder[simultaneousTwoMotorEncodeMotorTwo] = 0;
//	while(abs(nMotorEncoder[simultaneousTwoMotorEncodeMotorTwo]) < 1260*simultaneousTwoMotorEncodeRevolutions) {
//		motor[simultaneousTwoMotorEncodeMotorTwo] = simultaneousTwoMotorEncodePower;
//	}
//	motor[simultaneousTwoMotorEncodeMotorTwo] = 0;
//	writeDebugStreamLine("Task two done");
//	StopTask(simultaneousTwoMotorEncodeTwo);
//}

//void simultaneousTwoMotorEncode(tMotor x, tMotor y, int power, float revs) {
//	writeDebugStreamLine("Starting task launch method");
//	simultaneousTwoMotorEncodeMotorOne = x;
//	simultaneousTwoMotorEncodeMotorTwo = y;
//	simultaneousTwoMotorEncodePower = power;
//	simultaneousTwoMotorEncodeRevolutions = revs;
//	writeDebugStreamLine("Set global variables in task lauch method");
//	StartTask(simultaneousTwoMotorEncodeOne);
//	StartTask(simultaneousTwoMotorEncodeTwo);
//	writeDebugStreamLine("Done");
//}

///////////////// Global Variables //////////////////////
