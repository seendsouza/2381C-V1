#include "main.h"
#ifndef global
#include "global.h"
#endif

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

void tank_drive() {
        left_back_wheels.move(master.get_analog(ANALOG_LEFT_Y));
        right_back_wheels.move(master.get_analog(ANALOG_RIGHT_Y));
        left_front_wheels.move(master.get_analog(ANALOG_LEFT_Y));
        right_front_wheels.move(master.get_analog(ANALOG_RIGHT_Y));
}

void split_arcade_drive() {
    int power = master.get_analog(ANALOG_LEFT_Y);
    int turn = master.get_analog(ANALOG_RIGHT_X);
    int left = power + turn;
    int right = power - turn;
    left_back_wheels.move(left);
    right_back_wheels.move(right);
    left_front_wheels.move(left);
    right_front_wheels.move(right);

    pros::delay(20);
}

void arcade_drive() {
    int power = master.get_analog(ANALOG_LEFT_Y);
    int turn = master.get_analog(ANALOG_LEFT_X);
    int left = power + turn;
    int right = power - turn;
    left_back_wheels.move(left);
    right_back_wheels.move(right);
    left_front_wheels.move(left);
    right_front_wheels.move(right);

    pros::delay(20);
}

void opcontrol () {

    while (true) {
        tank_drive();

        if (master.get_digital(DIGITAL_A)) {
           autonomous(); 
        }

        if (master.get_digital(DIGITAL_R1)) {
            lift_left_motor.move_velocity(160);
            lift_right_motor.move_velocity(160);
        } else if (master.get_digital(DIGITAL_R2)) {
            lift_left_motor.move_velocity(-160);
            lift_right_motor.move_velocity(-160);
        } else {
            lift_left_motor.move_velocity(0);
            lift_right_motor.move_velocity(0);
        }

        if (master.get_digital(DIGITAL_L1)) {
            claw_motor.move_velocity(200);
        } else if (master.get_digital(DIGITAL_L2)) {
            claw_motor.move_velocity(-200);
        } else {
            claw_motor.move_velocity(0);
        }

        pros::delay(20);
    }
}

