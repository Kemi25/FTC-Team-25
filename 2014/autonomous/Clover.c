#pragma config(StandardModel, "teddy")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * Left side block ramp
 */

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "../library/auto_defs.h"
#include "../library/sensors/drivers/hitechnic-sensormux.h"
#include "../library/sensors/drivers/hitechnic-irseeker-v2.h"
#include "../library/sensors/drivers/hitechnic-compass.h"
#include "../library/sensors/drivers/hitechnic-protoboard.h"
#include "../library/DrivetrainSquare.c"
#include "../library/dead_reckon.h"

const tMUXSensor IRSeeker = msensor_S2_4;

#include "../library/light_strip.h"
#include "../library/rnrr_start.h"

void initializeRobot()
{
	servo[blockDump] = BLOCK_SERVO_RETRACTED;

    lightStripInit(0x1F);
    displayRestingPulse();
}

void dumpBlock()
{
    servoChangeRate[blockDump] = 10;
    servo[blockDump] = BLOCK_SERVO_EXTENDED;
    wait1Msec(1500);

    servoChangeRate[blockDump] = 10;

    for (int i = 0; i < 5; i++) {
        servo[blockDump] = BLOCK_SERVO_EXTENDED - 20;
        wait1Msec(100);
        servo[blockDump] = BLOCK_SERVO_EXTENDED;
    }

    servoChangeRate[blockDump] = 5;
    servo[blockDump] = BLOCK_SERVO_RETRACTED;
}

task main()
{
    int basketNumber;
    bool done = false;

    initializeRobot();

    RNRR_waitForStart(); // Wait for the beginning of autonomous phase.

    init_path();
    add_segment(-28, 0, 100);
    add_segment(-13, -45, 100);
    stop_path();
    dead_reckon();

    dumpBlock();

    init_path();
    add_segment(-6, 0, 100);
    stop_path();
    dead_reckon();

    while (true)
    {}
}
