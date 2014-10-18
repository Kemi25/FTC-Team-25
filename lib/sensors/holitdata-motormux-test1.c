#pragma config(Sensor, S1,     HDMMUX,              sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: holitdata-motormux-test1.c 112 2012-10-04 17:44:38Z xander $
 */

/**
 * holitdata-motormux.h provides an API for the Holit Data Systems Motor MUX. This program
 * demonstrates how to use that API to control the motors attached to the MUX.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: Removed common.h from list of includes
 *
 * Credits:
 * - Big thanks to Holit Data Systems for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.51 AND HIGHER.
 * Xander Soldaat (xander_at_botbench.com)
 * 14 February 2011
 * version 0.2
 */

#include "drivers/holitdata-motormux.h"

task main () {
  long encA  = 0;
  long encB  = 0;
  long encC  = 0;

  ubyte motorStatus = 0;
  string motorAstatus;
  string motorBstatus;
  string motorCstatus;

  eraseDisplay();

  // Initialise all the internal variables
  HDMMUXinit();

  // Reset the encoders.  This can be done individually or all at once.
  // You should do this at the start of your program.
  HDMMotorEncoderResetAll(HDMMUX);

  // You can specify the type of braking that should be used when the motors
  // are sent the stop command.  The default is to use brake.
  HDMMotorSetBrake(mmotor_S1_1);
  HDMMotorSetFloat(mmotor_S1_2);
  HDMMotorSetFloat(mmotor_S1_3);

  // Specify a target for the motors to run to.  This can be number of
  // rotations, seconds or degrees (encoder count).  Rotations and seconds
  // may be specified in increments of 0.01.
  HDMMotorSetRotationTarget(mmotor_S1_1, 4.50);
  HDMMotorSetTimeTarget(mmotor_S1_2, 2.50);
  HDMMotorSetEncoderTarget(mmotor_S1_3, 1000);

  // Tell the motors to start moving.
  HDMMotor(mmotor_S1_1, 50);
  HDMMotor(mmotor_S1_2, 50);
  HDMMotor(mmotor_S1_3, 50);

  while (true) {
    // Retrieve the motor-MUX's status info and encoder counts
		HDMMUXreadStatus(HDMMUX, motorStatus, encA, encB, encC);

		// Use the HDMMotorBusy() function to see if a motor is busy or idle.
		motorAstatus = HDMMotorBusy(mmotor_S1_1) ? "busy" : "idle";
	  motorBstatus = HDMMotorBusy(mmotor_S1_2) ? "busy" : "idle";
		motorCstatus = HDMMotorBusy(mmotor_S1_3) ? "busy" : "idle";

		// Display the info.
		nxtDisplayTextLine(5, "A: %5d (%s)", encA, motorAstatus);
		nxtDisplayTextLine(6, "B: %5d (%s)", encB, motorBstatus);
		nxtDisplayTextLine(7, "C: %5d (%s)", encC, motorCstatus);
    wait1Msec(5);
  }
}

/*
 * $Id: holitdata-motormux-test1.c 112 2012-10-04 17:44:38Z xander $
 */
