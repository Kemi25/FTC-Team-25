#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S3,     irr_left,       sensorI2CCustom)
#pragma config(Sensor, S4,     irr_right,      sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C2_1,     driveRearRight, tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     driveFrontRight, tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     shoulder,      tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     motorG,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C4_1,     driveFrontLeft, tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     driveRearLeft, tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Servo,  srvo_S1_C1_1,    finger,               tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    brush,                tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C1_3,    arm,                  tServoStandard)
#pragma config(Servo,  srvo_S1_C1_4,    dock,              tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_1,    centergoal,      tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    leftEye,              tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    rightEye,             tServoStandard)
#pragma config(Servo,  srvo_S2_C1_4,    servo10,              tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo11,              tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo12,              tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
//used teleop from actual dustpan teleop

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

#define SERVO_ARM_EXTENDED          90
#define SERVO_ARM_RETRACTED         150
#define SERVO_ARM_EXTENDED_HALF     120
#define SERVO_ARM_LIFT
#define SERVO_ARM_FORWARD_DOCK
#define SERVO_ARM_BACKWARD_DOCK
#define SERVO_ARM_STOP
#define SERVO_UP_FINGER
#define SERVO_DOWN_FINGER
#define SERVO_IN_CENTERGOAL
#define SERVO_OUT_CENTERGOAL
#define SERVO_SHOULDER

static int drive_multiplier = 1;

typedef enum brush_state_ {
    BRUSH_OFF,
    BRUSH_FORWARD,
    BRUSH_BACKWARD,
} brush_state_t;

typedef enum shoulder_state_ {
    SHOULDER_UP,
    SHOULDER_DOWN,
    SHOULDER_STOP,
} shoulder_state_t;

typedef enum arm_state_ {
    ARM_EXTENDED,
    ARM_RETRACTED,
    ARM_EXTENDED_HALF,
} arm_state_t;

typedef enum centergoal_state_ {
		IN_CENTERGOAL,
		OUT_CENTERGOAL,
} centergoal_state_t;

typedef enum dock_state {
		ARM_FORWARD_DOCK,
		ARM_BACKWARD_DOCK,
} dock_state_t;

typedef enum finger_state {
		UP_FINGER,
		DOWN_FINGER,
} finger_state_t;

typedef enum joystick_event_ {
    RIGHT_TRIGGER_UP = 6,
    RIGHT_TRIGGER_DOWN = 8,
    LEFT_TRIGGER_UP = 5,
    LEFT_TRIGGER_DOWN = 7,
    BUTTON_ONE = 1,
    BUTTON_TWO = 2,
    BUTTON_THREE = 3,
    BUTTON_FOUR = 4,
    BUTTON_SIX = 6,
    BUTTON_EIGHT = 8,
} joystick_event_t;

brush_state_t brush_state;
shoulder_state_t shoulder_state;
arm_state_t arm_state;
centergoal_state_t centergoal_state;
dock_state_t dock_state;
finger_state_t finger_state;

bool debounce; //What does this do?

task debounceTask() //What does this do?
{
    debounce = true; //What does this do?
    wait1Msec(500); //What does this do?
    debounce = false; //What does this do?
}

void all_stop()
{
    motor[driveFrontLeft] = 0;
    motor[driveRearLeft] = 0;
    motor[driveFrontRight] = 0;
    motor[driveRearRight] = 0;
}

void brush_enter_state(brush_state_t state)
{
    brush_state = state;

    switch (state) {
    case BRUSH_OFF:
        servo[brush] = 127;
        break;
    case BRUSH_FORWARD:
        servo[brush] = 5;
        break;
    case BRUSH_BACKWARD:
        servo[brush] = 250;
        break;
    }
}

void arm_enter_state(arm_state_t state)
{
    arm_state = state;

    switch (state) {
    case ARM_EXTENDED:
        servo[arm] = SERVO_ARM_EXTENDED;
        break;
    case ARM_EXTENDED_HALF:
        servo[arm] = SERVO_ARM_EXTENDED_HALF;
        break;
    case ARM_RETRACTED:
        servo[arm] = SERVO_ARM_RETRACTED;
        break;
    }
}

void shoulder_enter_state(shoulder_state_t state)
{
    shoulder_state = state;

    switch (state) {
    case SHOULDER_DOWN:
        motor[shoulder] = -20;
        break;
    case SHOULDER_UP:
        motor[shoulder] = 20;
        break;
    case SHOULDER_STOP:
        motor[shoulder] = 0;
        break;
 }
        //centergoal, dock, finger
}
void centergoal_enter_state(centergoal_state_t state) { //need to work on values

		centergoal_state = state;

		switch (state) {
		case IN_CENTERGOAL:
		     servo[centergoal] = 1; //change value
		     break;
		case OUT_CENTERGOAL:
		     servo[centergoal] = 1; //change value
		     break;
    }
}
void dock_enter_state (dock_state_t state) //need to work on values
{
		dock_state = state;

		switch (state) {
		case ARM_FORWARD_DOCK:
		     servo[dock] = 1; //change value
		     break;
		case ARM_BACKWARD_DOCK:
		     servo[dock] = 1; // change value
		     break;
    }

void finger_enter_state (dock_state_t state) //need to work on values
{
		finger_state = state;

		switch (state) {
		case UP_FINGER:
				servo[finger] = 1; //change value
				break;
		case DOWN_FINGER:
				servo[finger] = 1; //change value
				break;
	  }
   }
}


void initializeRobot()
{
    nMotorEncoder[shoulder] = 0;

    shoulder_enter_state(SHOULDER_STOP);
    brush_enter_state(BRUSH_OFF);
    arm_enter_state(ARM_RETRACTED);
    centergoal_enter_state (IN_CENTERGOAL);
    dock_enter_state (ARM_BACKWARD_DOCK);
    finger_enter_state (DOWN_FINGER);

    all_stop();

    return;
}

void handle_joy2_rtu()
{
    switch (brush_state) {
    case BRUSH_FORWARD:
        brush_enter_state(BRUSH_OFF);
        break;
    case BRUSH_BACKWARD:
        brush_enter_state(BRUSH_FORWARD);
        break;
    case BRUSH_OFF:
        brush_enter_state(BRUSH_FORWARD);
        break;
    }
}

void handle_joy2_rtd()
{
    switch (brush_state) {
    case BRUSH_FORWARD:
        brush_enter_state(BRUSH_BACKWARD);
        break;
    case BRUSH_BACKWARD:
        brush_enter_state(BRUSH_OFF);
        break;
    case BRUSH_OFF:
        brush_enter_state(BRUSH_BACKWARD);
        break;
    }
}

		void handle_joy2_ltu()
{
    switch (shoulder_state) {
    case SHOULDER_DOWN:
        shoulder_enter_state(SHOULDER_UP);
        break;
    case SHOULDER_UP:
        shoulder_enter_state(SHOULDER_STOP);
        break;
    case SHOULDER_STOP:
        shoulder_enter_state(SHOULDER_UP);
        break;
    }
}

void handle_joy2_ltd()
{
    switch (shoulder_state) {
    case SHOULDER_DOWN:
        shoulder_enter_state(SHOULDER_STOP);
        break;
    case SHOULDER_UP:
        shoulder_enter_state(SHOULDER_DOWN);
        break;
    case SHOULDER_STOP:
        shoulder_enter_state(SHOULDER_DOWN);
        break;
    }
}

void handle_joy2_btn2()
{
    switch (arm_state) {
    case ARM_EXTENDED:
        arm_enter_state(ARM_RETRACTED);
        break;
    case ARM_RETRACTED:
        break;
    case ARM_EXTENDED_HALF:
        arm_enter_state(ARM_RETRACTED);
        break;
    }
}

void handle_joy2_btn3()
{
    switch (arm_state) {
    case ARM_EXTENDED:
        arm_enter_state(ARM_EXTENDED_HALF);
        break;
    case ARM_RETRACTED:
        arm_enter_state(ARM_EXTENDED_HALF);
        break;
    case ARM_EXTENDED_HALF:
        break;
    }
}

 void handle_joy2_btn4()
{
    switch (arm_state) {
    case ARM_EXTENDED:
        break;
    case ARM_RETRACTED:
        arm_enter_state(ARM_EXTENDED);
        break;
    case ARM_EXTENDED_HALF:
        arm_enter_state(ARM_EXTENDED);
        break;
    }
}

void handle_joy2_event(joystick_event_t event)
{
    switch (event) {
    case BUTTON_TWO:
        handle_joy2_btn2();
        break;
    case BUTTON_THREE:
        handle_joy2_btn3();
        break;
    case BUTTON_FOUR:
        handle_joy2_btn4();
        break;
    case LEFT_TRIGGER_UP:
        handle_joy2_ltu();
        break;
    case LEFT_TRIGGER_DOWN:
        handle_joy2_ltd();
        break;
    case RIGHT_TRIGGER_UP:
        handle_joy2_rtu();
        break;
    case RIGHT_TRIGGER_DOWN:
        handle_joy2_rtd();
        break;
		switch (event) {
		case BUTTON_TWO:
				handle_joy2_rtd();
				break;
	//	case BUTTON_SIX:
			//	handle_joy2_btn6();
			//	break;
		//case BUTTON_EIGHT:
			//	handle_joy2_btn8();
			//	break;
	}
}

    startTask(debounceTask);
}

task main()
{
    short right_y;
    short left_y;

    debounce = false;

    initializeRobot();

    waitForStart();   // wait for start of tele-op phase

    // StartTask(endGameTimer);

    while (true) {

        getJoystickSettings(joystick);

        if (!debounce) {
 	        if (joy2Btn(Btn2)) {
	            handle_joy2_event(BUTTON_TWO);
	        } else if (joy2Btn(Btn3)) {
	            handle_joy2_event(BUTTON_THREE);
	        } else if (joy2Btn(Btn4)) {
	            handle_joy2_event(BUTTON_FOUR);
	        } else if (joy2Btn(Btn5)) {
	            handle_joy2_event(LEFT_TRIGGER_UP);
	        } else if (joy2Btn(Btn6)) {
	            handle_joy2_event(RIGHT_TRIGGER_UP);
	        } else if (joy2Btn(Btn7)) {
	            handle_joy2_event(LEFT_TRIGGER_DOWN);
	        } else if (joy2Btn(Btn8)) {
	            handle_joy2_event(RIGHT_TRIGGER_DOWN);
            }
       }

       right_y = joystick.joy1_y1;
       left_y = joystick.joy1_y2;


        if (abs(right_y) > 20) {
	    	motor[driveFrontRight] = drive_multiplier * left_y;
	    	motor[driveRearRight] = drive_multiplier * left_y;
		}
		else {
		    motor[driveFrontRight] = 0;
		    motor[driveRearRight] = 0;
		}

        if (abs(left_y) > 20) {
		    motor[driveFrontLeft] = drive_multiplier * right_y;
		    motor[driveRearLeft] = drive_multiplier * right_y;
		}
		else
		{
		    motor[driveFrontLeft] = 0;
		    motor[driveRearLeft] = 0;
		}
  }
}
