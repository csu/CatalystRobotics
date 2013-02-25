#pragma config(Sensor, S2,     HTSMUX,              sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: hitechnic-gyro-SMUX-test1.c 123 2012-11-02 16:35:15Z xander $
 */

/**
 * hitechnic-gyro.h provides an API for the HiTechnic Gyroscopic Sensor.  This program
 * demonstrates how to use that API in combination with the Sensor MUX.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: Now uses HTSMUX driver which has been split from common.h\n
 *        HTSMUX initialisation and scanning functions have been removed\n
 *
 * Credits:
 * - Big thanks to HiTechnic for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.54 AND HIGHER.
 * Xander Soldaat (xander_at_botbench.com)
 * 20 February 2011
 * version 0.2
 */

#include "drivers/hitechnic-sensormux.h"
#include "drivers/hitechnic-gyro.h"

// The sensor is connected to the first port
// of the SMUX which is connected to the NXT port S1.
// To access that sensor, we must use msensor_S1_1.  If the sensor
// were connected to 3rd port of the SMUX connected to the NXT port S4,
// we would use msensor_S4_3

// Give the sensor a nice easy to use name
const tMUXSensor HTGYRO = msensor_S1_1;

task main () {

  nxtDisplayCenteredTextLine(0, "HiTechnic");
  nxtDisplayCenteredBigTextLine(1, "GYRO");
  nxtDisplayCenteredTextLine(3, "SMUX Test");
  nxtDisplayCenteredTextLine(5, "Connect SMUX to");
  nxtDisplayCenteredTextLine(6, "S1 and sensor to");
  nxtDisplayCenteredTextLine(7, "SMUX Port 1");

  wait1Msec(2000);
  eraseDisplay();
  time1[T1] = 0;
  while(true) {
    if (time1[T1] > 1000) {
      eraseDisplay();
      nxtDisplayTextLine(1, "Resetting");
      nxtDisplayTextLine(1, "heading");
      wait1Msec(500);

      // Start the calibration and display the offset
      nxtDisplayTextLine(2, "Offset: %4d", HTGYROstartCal(HTGYRO));
      PlaySound(soundBlip);
      while(bSoundActive) EndTimeSlice();
      time1[T1] = 0;
    }

    while(nNxtButtonPressed != kEnterButton) {
      eraseDisplay();

      nxtDisplayTextLine(1, "Reading");
      // Read the current calibration offset and display it
      nxtDisplayTextLine(2, "Offset: %4d", HTGYROreadCal(HTGYRO));

      nxtDisplayClearTextLine(4);
      // Read the current rotational speed and display it
      nxtDisplayTextLine(4, "Gyro:   %4d", HTGYROreadRot(HTGYRO));
      nxtDisplayTextLine(6, "Press enter");
      nxtDisplayTextLine(7, "to recalibrate");
      wait1Msec(100);
    }
  }
}

/*
 * $Id: hitechnic-gyro-SMUX-test1.c 123 2012-11-02 16:35:15Z xander $
 */
