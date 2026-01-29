/**
 * 2026 Pushback Tournament
 * Team 938G Coder ARM
 * Pros ProsAuton.cpp
 */

//Include initialized devices and ProsAuton.h.
#include "LemImp.h"
#include "LemAuton.h"

//Define auton utility variables.
bool intake = false;

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

void _OuttakeL (int Time) {

    TFlywheel.move_velocity(-600);
    BFlywheel.move_velocity(-600);
    pros::delay(Time);
    TFlywheel.brake();
    BFlywheel.brake();

}
void _Intake (int Time) {

    TFlywheel.brake();
    BFlywheel.move_velocity(600);
    pros::delay(Time);
    BFlywheel.brake();

}

//Define auton path functions;

void _PathLemT () {
    
    
    chassis.setBrakeMode (pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose (0, 0, 0);

    _LateralMovement (0, 48, 5000, true);
    chassis.waitUntilDone();

   //_AngularMovement (180, 5000, true);
   //chassis.waitUntilDone();
}

void _PathLemL () {

    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(-48, 0, 0, false);

        _LateralMovement (-48, 48, 1500, true);
        _AngularMovement (270, 500, false);
        _LateralMovement (-24, 48, 1000, false);
        _OuttakeT (1500);
        _LateralMovement (-30, 48, 500, true);
        _LateralMovement (-24, 48, 500, false);
        _LateralMovement (-48, 48, 1000, true);
        _AngularMovement (135, 1000, false);
        _LateralMovement (-24, 24, 1000, true);
        _Intake (2000);
        _AngularMovement(315, 500, true);
        _LateralMovement(-12, 12, 500, false);
        _OuttakeT(3000);

}

void _PathLemR () {

    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(-48, 0, 0, false);

    PneumaticLoad.extend();
    _LateralMovement (-48, -48, 1500, false);
    _AngularMovement(270, 500, false);
    intake = true;
    _LateralMovement(-84, -48, 750, true);
    pros::delay(2500);
    intake = false;
    PneumaticLoad.retract();
    _LateralMovement(-24, -48, 1500, false);
    _OuttakeT(2000);
    _LateralMovement(-36, -48, 500, true);
    _LateralMovement(-24, -48, 500, false);
    _LateralMovement(-48, -48, 750, true);
    _AngularMovement(45, 750, true);
    _LateralMovement(-27, -27, 1000, true);
    intake = true;
    _LateralMovement(-12, -12, 500, true);
    pros::delay(1000);
    intake = false;
    _OuttakeL(1500);

}

void _PathLemN () {

    chassis.setBrakeMode (pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose (0, 0, 0, false);
    chassis.cancelAllMotions();

}

void _PathLemS () {

    chassis.setBrakeMode (pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose (0, 0, 0, false);
    chassis.cancelAllMotions();
    _LateralMovement (0, -12, 5000, false);
    _LateralMovement (0, 40, 7000, true);

}