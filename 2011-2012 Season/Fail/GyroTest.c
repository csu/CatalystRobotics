#pragma config(Sensor, S3,     HTIRL,          sensorI2CCustom)
#pragma config(Sensor, S4,     HTGYRO,         sensorNone)

#include "drivers/HTGYRO-driver.h"

float Gyro_offset;
long Gyro_value;
long sum;

tSensors HTGYRO;

void initializeRobot()
{
  Gyro_offset = HTGYROstartCal(HTGYRO);   //start calibration, but do not trust results
  for (int i = 0 ; i < 20; i++)           //instead read 20 values and generate average offset
  {
    sum = sum + HTGYROreadRot(HTGYRO);
    wait1Msec(10);
  }
  Gyro_offset = sum / 20.0;

  return;
}

task main()
{
  initializeRobot();

  while(true)
  {
    Gyro_value = HTGYROreadRot(HTGYRO);
    wait1Msec(10);
  }

}
