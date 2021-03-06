#include "main.h"
#ifndef global
#include "global.h"
#endif

pros::Motor left_front_wheels (LEFT_FRONT_WHEELS_PORT);
pros::Motor right_front_wheels (RIGHT_FRONT_WHEELS_PORT,true);
pros::Motor left_back_wheels (LEFT_BACK_WHEELS_PORT);
pros::Motor right_back_wheels (RIGHT_BACK_WHEELS_PORT,true);
pros::Motor lift_left_motor (LEFT_LIFT_PORT, MOTOR_GEARSET_18); // The arm motor has the 200 rpm gearset
pros::Motor lift_right_motor (RIGHT_LIFT_PORT, MOTOR_GEARSET_18, true); // The arm motor has the 200 rpm gearset
pros::Motor claw_motor (CLAW_PORT, MOTOR_GEARSET_18); // The arm motor has the 200 rpm gearset
pros::Controller master (CONTROLLER_MASTER);
