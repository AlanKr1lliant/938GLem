/**
 * 2026 Pushback Tournament
 * Team 938G Coder ARM
 * Pros ProsAuton.cpp
 */

//Include initialized devices and ProsAuton.h.
#include "LemImp.h"
#include "LemAuton.h"

//Define auton utility variables.

//Define auton functions.
void _LateralMovement (float XCoord, float YCoord, int Time, bool Forward=true) {

    chassis.moveToPoint(XCoord, YCoord, Time, {.forwards = Forward, .maxSpeed = 127, .minSpeed = 0, .earlyExitRange = 0});
    chassis.waitUntilDone();

}

void _AngularMovement (float Angle, int Time, bool Direction) {

    AngularDirection augDirection = Direction ? AngularDirection::CW_CLOCKWISE : AngularDirection::CCW_COUNTERCLOCKWISE;    
    chassis.turnToHeading (Angle, Time, {.direction = augDirection, .maxSpeed = 127, .minSpeed = 0, .earlyExitRange = 0});
    chassis.waitUntilDone();
    
}

//Define auton path functions;

void _PathLemT () {
    
    
    chassis.setBrakeMode (pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose (0, 0, 0);

    _LateralMovement (0, 24, 500, true);
    chassis.waitUntilDone();

   //_AngularMovement (180, 5000, true);
   //chassis.waitUntilDone();
    pros::delay(1000);
}

void _PathLemL () {

    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(0, 0, 0, false);

    for (int i=0; i < 1; i++) {

        _LateralMovement (0, 24, 5000, true);
        pros::delay(3000);
        _LateralMovement (0, 0, 5000, false);
    }

}

void _PathLemR () {

    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(0, 0, 0, false);

    for (int i=0; i < 1; i++) {

        _LateralMovement (0, 24, 5000, true);
        pros::delay(1000);
        _AngularMovement (180, 3000, true);
        pros::delay(1000);
        _LateralMovement (0, 0, 5000, false);
        pros::delay(1000);
        _AngularMovement (360, 4000, false);

    }

}

void _PathLemN () {

    chassis.setBrakeMode (pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose (0, 0, 0, false);
    chassis.cancelAllMotions();

}