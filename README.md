# 2381C Cycle 1 Robot Code
VEX V5
PROS Kernel 3.1.4

# Description
Our robot has 7 motors and the puncher is not implemented as of yet.
There are two autonomous programmed and ready for competition.
The first autonomous goes straight, turns left and goes straight again (straight to parking).
The second autonomous shoots a ball (one time), finds a cap, puts it on the post and then parks.
There will be variations of them both.

# Motors
- LEFT_FRONT_WHEELS_PORT 1
- RIGHT_FRONT_WHEELS_PORT 2
- LEFT_BACK_WHEELS_PORT 3
- RIGHT_BACK_WHEELS_PORT 4
- LEFT_LIFT_PORT 5
- RIGHT_LIFT_PORT 6
- CLAW_PORT 7

# What I Have Learnt
- setting the motor properties in initialize.cpp will be passed down to any motor accessing that port
- pros namespace
- consider using okapi (simple abstractions)
