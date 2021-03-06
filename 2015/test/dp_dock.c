#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C2_1,     rightBack,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     rightFront,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     armMotor,      tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     leftFront,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     leftBack,      tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C1_1,    goalGrabber,          tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    bucketSwod,           tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C1_3,    drawerSlide,          tServoStandard)
#pragma config(Servo,  srvo_S1_C1_4,    grabberMover,         tServoStandard)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"     // Tells ROBOTC to include the driver file for the joystick.

task main()
{
	while (true) {

    	getJoystickSettings(joystick);  // Update Buttons and Joysticks

    	if (joy1Btn(1)) {                  // If Joy1-Button1 is pressed:
    		servo[grabberMover] = 200;              // Turn the servo On continuously
 		} else {                           // If Joy1-Button1 is NOT pressed:
    		servo[grabberMover] = 127;                 // Stop the servo
    	}
	}
}
