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

void opcontrol () {
    pros::Motor left_front_wheels (LEFT_FRONT_WHEELS_PORT);
    pros::Motor right_front_wheels (RIGHT_FRONT_WHEELS_PORT);
    pros::Motor left_back_wheels (LEFT_BACK_WHEELS_PORT);
    pros::Motor right_back_wheels (RIGHT_BACK_WHEELS_PORT);
    pros::Controller master (CONTROLLER_MASTER);
    
    while (true) {
        tank_drive();
        //split_arcade_drive();
        //arcade_drive();
    }
}

void tank_drive() {
    left_back_wheels.move(master.get_analog(ANALOG_LEFT_Y));
    right_back_wheels.move(master.get_analog(ANALOG_RIGHT_Y));
    left_front_wheels.move(master.get_analog(ANALOG_LEFT_Y));
right_front_wheels.move(master.get_analog(ANALOG_RIGHT_Y));
	
    pros::delay(20);
}

void split_arcade_drive() {
    int power = master.get_analog(ANALOG_LEFT_Y);
    int turn = master.get_analog(ANALOG_RIGHT_X);
    int left = power + turn;
    int right = power - turn;
    left_back_wheels.move(master.get_analog(left));
    right_back_wheels.move(master.get_analog(right));
    left_front_wheels.move(master.get_analog(left));
    right_front_wheels.move(master.get_analog(right));
   
    pros::delay(20);
}

void arcade_drive() {
    int power = master.get_analog(ANALOG_LEFT_Y);
    int turn = master.get_analog(ANALOG_LEFT_X);
    int left = power + turn;
    int right = power - turn;
    left_back_wheels.move(master.get_analog(left));
    right_back_wheels.move(master.get_analog(right));
    left_front_wheels.move(master.get_analog(left));
    right_front_wheels.move(master.get_analog(right));

    pros::delay(20);
}
