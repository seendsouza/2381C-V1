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

void opcontrol() {
	while (true) {
        int left = controller_get_analog(CONTROLLER_MASTER, ANALOG_LEFT_Y);
        int right = controller_get_analog(CONTROLLER_MASTER, ANALOG_RIGHT_Y);
        right *= -1 // Reversing the right motor
        motor_move(LEFT_FRONT_WHEELS_PORT, left)
        motor_move(LEFT_BACK_WHEELS_PORT, left)
        motor_move(RIGHT_FRONT_WHEELS_PORT, right)
        motor_move(RIGHT_BACK_WHEELS_PORT, right)
		delay(2);
	}
}
