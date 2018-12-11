#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    pros::Motor left_front_wheels (LEFT_FRONT_WHEELS_PORT);
    pros::Motor right_front_wheels (RIGHT_FRONT_WHEELS_PORT);
    pros::Motor left_back_wheels (LEFT_BACK_WHEELS_PORT);
    pros::Motor right_back_wheels (RIGHT_BACK_WHEELS_PORT);
    pros::Controller master (CONTROLLER_MASTER);

    int drive_forward = 1000;
    int drive_left = 1000;
    int drive_forward_2 = 1000;

    left_back_wheels.move(drive_forward);
    right_back_wheels.move(drive_forward);
    left_front_wheels.move(drive_forward);
    right_front_wheels.move(drive_forward);

    right_back_wheels.move(drive_left);
    right_front_wheels.move(drive_left);

    left_back_wheels.move(drive_forward_2);
    right_back_wheels.move(drive_forward_2);
    left_front_wheels.move(drive_forward_2);
    right_front_wheels.move(drive_forward_2);
}
