#include "main.h"

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "Press again to pay respects.");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello 2381C!");

	pros::lcd::register_btn1_cb(on_center_button);
/*
    pros::Motor left_front_wheels_initializer (LEFT_FRONT_WHEELS_PORT);
    pros::Motor right_front_wheels_initializer (RIGHT_FRONT_WHEELS_PORT, true);
    pros::Motor left_back_wheels_initializer (LEFT_BACK_WHEELS_PORT);
    pros::Motor right_back_wheels_initializer (RIGHT_BACK_WHEELS_PORT, true);
    pros::Motor lift_left_motor_initializer (LEFT_LIFT_PORT, MOTOR_GEARSET_18); // The arm motor has the 200 rpm gearset
    pros::Motor lift_right_motor_initializer (RIGHT_LIFT_PORT, MOTOR_GEARSET_18, true); // The arm motor has the 200 rpm gearset
    pros::Motor claw_motor_initializer (CLAW_PORT, MOTOR_GEARSET_18); // The arm motor has the 200 rpm gearset
    pros::Controller master_initializer (CONTROLLER_MASTER);
*/
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
