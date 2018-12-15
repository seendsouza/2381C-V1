#include "main.h"
#include "global.h"
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

    int drive_forward = 2800; //drive distance
    int drive_left = 300;
    int drive_forward_2 = 1000;

    left_back_wheels.move_relative(drive_forward, 100); //drive forward 100 tick at 100 rpm
    right_back_wheels.move_relative(drive_forward, 100);
    left_front_wheels.move_relative(drive_forward, 100);
    right_front_wheels.move_relative(drive_forward, 100);

    while (right_front_wheels.get_position()-drive_forward > 5 && left_front_wheels.get_position()-drive_forward > 5 ) {
        pros::delay(2);
    }

    left_back_wheels.tare_position(); // set motor position to zero
    right_back_wheels.tare_position();
    left_front_wheels.tare_position();
    right_front_wheels.tare_position();

    right_front_wheels.move_relative(drive_left, 100); //turn left
    right_back_wheels.move_relative(drive_left, 100);
    left_back_wheels.move_relative(-drive_left, 100);
    left_front_wheels.move_relative(-drive_left, 100);

    while (right_front_wheels.get_position()-drive_left > 5 && left_front_wheels.get_position() + drive_left > 5 ) {
        pros::delay(2);
    }

    left_back_wheels.tare_position();
    right_back_wheels.tare_position();
    left_front_wheels.tare_position();
    right_front_wheels.tare_position();

    left_back_wheels.move_relative(drive_forward, 100); //drive forward 100 tick at 100 rpm
    right_back_wheels.move_relative(drive_forward, 100);
    left_front_wheels.move_relative(drive_forward, 100);
    right_front_wheels.move_relative(drive_forward, 100);

    while (right_front_wheels.get_position()-drive_forward_2 > 5 && left_front_wheels.get_position()-drive_forward_2 > 5 ) {
        pros::delay(2);
    }
}
