// Created by Christopher Su
// Catalyst Robotics 2012-2013 Season

void gyroInitialize() {
  GyroOffset = HTGYROstartCal(gyroSensor);   //start calibration, but do not trust results
  for (int i = 0 ; i < 20; i++)           //instead read 10 values and generate average offset
  {
    GyroSum = GyroSum + HTGYROreadRot(gyroSensor);
    wait1Msec(20);
  }
  GyroOffset = GyroSum / 20.0;
}

void gyroSumUpdate() {
	GyroSum = GyroSum + (HTGYROreadRot(gyroSensor) - GyroOffset);
}

task updateGyroTask() {
	gyroSumUpdate();
}

void gyroCompensate() {
	//GyroCurrentValue = HTGYROreadRot(gyroSensor) - GyroOffset;
	//gyroSumUpdate();
	while ((GyroSum > 10) || (GyroSum < -10)) {
		if (GyroSum > 10) {
			encodedTurn(autonomousWheelPower, 0.1);
			//gyroSumUpdate();
		}
		else if (GyroSum < -10) {
			encodedTurn(-autonomousWheelPower, 0.1);
			//gyroSumUpdate();
		}
	}
}
