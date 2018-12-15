#define LEFT_FRONT_WHEELS_PORT 11
#define RIGHT_FRONT_WHEELS_PORT 12
#define LEFT_BACK_WHEELS_PORT 20
#define RIGHT_BACK_WHEELS_PORT 19
#define LEFT_LIFT_PORT 13
#define RIGHT_LIFT_PORT 14
#define CLAW_PORT 2

#define REVERSED true
#define NOT_REVERSED false

pros::Motor left_front_wheels (LEFT_FRONT_WHEELS_PORT);                                                                     
pros::Motor right_front_wheels (RIGHT_FRONT_WHEELS_PORT);
pros::Motor left_back_wheels (LEFT_BACK_WHEELS_PORT);
pros::Motor right_back_wheels (RIGHT_BACK_WHEELS_PORT);
pros::Motor lift_left_motor (LEFT_LIFT_PORT); // The arm motor has the 200 rpm gearset
pros::Motor lift_right_motor (RIGHT_LIFT_PORT); // The arm motor has the 200 rpm gearset
pros::Motor claw_motor (CLAW_PORT); // The arm motor has the 200 rpm gearset
pros::Controller master (CONTROLLER_MASTER);
extern pros::Motor left_front_wheels;
extern pros::Motor right_front_wheels;
extern pros::Motor left_back_wheels;
extern pros::Motor right_back_wheels;
extern pros::Motor lift_left_motor;
extern pros::Motor lift_right_motor;
extern pros::Motor claw_motor;
extern pros::Controller master;
