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
    pros::delay(150);

}

void _AngularMovement (float Angle, int Time, bool Direction) {

    AngularDirection augDirection = Direction ? AngularDirection::CW_CLOCKWISE : AngularDirection::CCW_COUNTERCLOCKWISE;    
    chassis.turnToHeading (Angle, Time, {.direction = augDirection, .maxSpeed = 127, .minSpeed = 0, .earlyExitRange = 0});
    chassis.waitUntilDone();
    pros::delay(150);
    
}

void _OuttakeT (int Time) {

    TFlywheel.move_velocity(600);
    BFlywheel.move_velocity(600);
    pros::delay(Time);
    TFlywheel.brake();
    BFlywheel.brake();

}

//Define auton path functions;

void _PathLemT () {
    
    
    chassis.setBrakeMode (pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose (0, 0, 0);

    //_LateralMovement (0, 48, 5000, true);
    //chassis.waitUntilDone();

   _AngularMovement (180, 5000, true);
   chassis.waitUntilDone();
}

void _PathLemL () {

    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(0, 0, 0, false);

        _LateralMovement (0, 24, 5000, true);
        _AngularMovement(90, 5000, true);
        _LateralMovement (24, 24, 5000, true);
        _AngularMovement(180, 5000, true);
        _LateralMovement (24, 0, 5000, true);
        _AngularMovement(270, 5000, true);
        _LateralMovement (0, 0, 5000, true);
        _AngularMovement(360, 5000, true);

}

void _PathLemR () {

    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(0, 0, 0, false);

    _LateralMovement (0, 48, 3000, true);
    _AngularMovement (90, 2000, true);
    _LateralMovement (-24, 48, 2500, false);
    _OuttakeT (2500);
}

void _PathLemN () {

    chassis.setBrakeMode (pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose (0, 0, 0, false);
    chassis.cancelAllMotions();

}