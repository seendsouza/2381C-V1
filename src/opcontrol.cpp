#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

#define LEFT_FRONT_WHEELS_PORT 1
#define RIGHT_FRONT_WHEELS_PORT 2
#define LEFT_BACK_WHEELS_PORT 3
#define RIGHT_BACK_WHEELS_PORT 4

/* Drive Types:
 * 0 is Tank Drive
 * 1 is Split Arcade Drive
 * 2 is Arcade Drive
 */

int drive_type = 0;

void opcontrol () {
    while (true) {
        if (drive_type == 0){
            tank_drive()
        } else if (drive_type == 1) {
            split_arcade_drive()
        }
    }
}

void tank_drive() {
    int left = controller_get_analog(CONTROLLER_MASTER, ANALOG_LEFT_Y);
    int right = controller_get_analog(CONTROLLER_MASTER, ANALOG_RIGHT_Y);
    
    right *= -1 // Reversing the right motor
    
    motor_move(LEFT_FRONT_WHEELS_PORT, left);
    motor_move(LEFT_BACK_WHEELS_PORT, left);
    motor_move(RIGHT_FRONT_WHEELS_PORT, right);
    motor_move(RIGHT_BACK_WHEELS_PORT, right);
	
    delay(2);
}

void split_arcade_drive() {
    int power = controller_get_analog(CONTROLLER_MASTER, ANALOG_LEFT_Y);
    int turn = controller_get_analog(CONTROLLER_MASTER, ANALOG_RIGHT_X);
    int left = power + turn;
    int right = power - turn;
    
    right *= -1 // Reversing the right motor
    
    motor_move(LEFT_FRONT_WHEELS_PORT, left);
    motor_move(LEFT_BACK_WHEELS_PORT, left);
    motor_move(RIGHT_FRONT_WHEELS_PORT, right);
    motor_move(RIGHT_BACK_WHEELS_PORT, right);
   
    delay(2)
}
