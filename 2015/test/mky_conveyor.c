#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S3, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S4, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorArm,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorConveyor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     backRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     frontRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_1,     backLeft,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_2,     frontLeft,      tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S4_C1_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S4_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S4_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S4_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S4_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S4_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	motor[motorConveyor] = 30;
	wait1Msec(500);
}
