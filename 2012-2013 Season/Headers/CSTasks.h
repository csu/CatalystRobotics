#include "../Headers/CSMethods.h"

#ifndef TASKS
#define TASKS

task multiplexerThreadUpdate() {
  while (true) {
		touchMultiplexerUpdate();
    wait1Msec(5);
  }
}

task getHeading () {
  HTGYROstartCal(GYRO);
  PlaySound(soundBeepBeep);
  while (true) {
    time1[T1] = 0;
    curRate = HTGYROreadRot(GYRO);
    if (abs(curRate) > 3) {
      prevHeading = currHeading;
      currHeading = prevHeading + curRate * delTime;
      if (currHeading > 360) currHeading -= 360;
      else if (currHeading < 0) currHeading += 360;
    }
    wait1Msec(5);
    delTime = ((float)time1[T1]) / 1000;
    //delTime /= 1000;
	}
}

#endif
