#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S2,     irr_right,      sensorI2CCustom)
#pragma config(Sensor, S3,     irr_left,       sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     driveRearRight, tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     driveRearLeft, tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Servo,  srvo_S1_C2_1,    leftEye,              tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    rightEye,             tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#define LSERVO_CENTER 20

#include "../../lib/sensors/drivers/hitechnic-irseeker-v2.h"
#include "../../lib/drivetrain_andymark_defs.h"
#include "../../lib/drivetrain_square.h"
#include "../../lib/dead_reckon.h"
#include "../../lib/data_log.h"
#include "../../lib/ir_utils.h"

task main()
{
   init_path();
   add_segment(96,0,40) //(inches,turn(does first), speed)//22, 36,48
   add_segment(96,90, 40)
   add_segment(96,90, 0)
   add_segment(10,90, 40)
   add_segment(120,90, 40)
   stop_path();
   dead_reckon();

}
