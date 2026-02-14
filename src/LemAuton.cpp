/**
 * 2026 Pushback Tournament
 * Team 938G Coder ARM
 * Pros ProsAuton.cpp
 */

//Include initialized devices and ProsAuton.h.
#include "LemImp.h"
#include "LemAuton.h"

//#Define auton utility variables.

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

    TFlywheel.move(127);
    BFlywheel.move(127);
    pros::delay(Time);
    TFlywheel.brake();
    BFlywheel.brake();

}

void _OuttakeL (int Time) {

    TFlywheel.move(-127);
    BFlywheel.move(-127);
    pros::delay(Time);
    TFlywheel.brake();
    BFlywheel.brake();

}
//Define auton path functions;

void _PathLemT () {
    
    
    chassis.setBrakeMode (pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose (0, 0, 0);

    _LateralMovement (0, 48, 5000, true);
    
   // _AngularMovement (180, 5000, true);
   
}

void _PathLemL () {
    /*
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(-48, 15, 0);
    PneumaticLoad.set_value(true);
    _LateralMovement(-48, 48, 1500, true);
    _AngularMovement(270, 750, false);
    BFlywheel.move(127);
    _LateralMovement(-84, 48, 1000, true);
    pros::delay(1000);
    BFlywheel.brake();
    _LateralMovement(-24, 48, 1500, false);
    PneumaticLoad.set_value(false);
    _OuttakeT(3000);
    _LateralMovement(-48, 48, 1000, true);
    _LateralMovement(-24, 48, 1000, false);
    _OuttakeT(1000);
    */
    
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(-48, 16, 90, false);
    BFlywheel.move(127);
    _LateralMovement (-24, 24, 1500, true);
    _AngularMovement(90, 750, true);
    chassis.setPose(-24, 24, 90, false);
    pros::delay(1000);
    BFlywheel.brake();
    _AngularMovement(315, 1500, false);

    //_AngularMovement (315, 1500, true);
    //_AngularMovement (-12, 12, false);
    //_OuttakeT (750);
    //_AngularMovement (45, 1500, true);

    _LateralMovement (-48, 48, 1500, true);
    chassis.setPose(-48, 48, 315, false);
    _AngularMovement (270, 1000, false);
    _LateralMovement (-24, 48, false);
    PneumaticLoad.set_value(true);
    BFlywheel.move(127);
    _LateralMovement (-72, 48, true);
    pros::delay(750);
    BFlywheel.brake();
    _LateralMovement (-24, 48, false);
    _OuttakeT(2000);
    _LateralMovement (-48, 48, true);
    _LateralMovement (-24, 48, false);
}

void _PathLemR () {
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(-48, -10, 0);
    _LateralMovement(-48, -48, 2000, false);
    _AngularMovement(270, 1000, false);
    PneumaticLoad.set_value(true);
    BFlywheel.move(127);
    _LateralMovement(-84, -48, 1500, true);
    pros::delay(1500);
    BFlywheel.brake();
    _LateralMovement(-24, -48, 2000, false);
    PneumaticLoad.set_value(false);
    _OuttakeT(2000);
    _LateralMovement(-48, -48, 1000, true);
    _LateralMovement(-24, -48, 1000, false);
    _OuttakeT(1000);
    
    /*
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(-48, -16, 90, false);
    _AngularMovement(180, 750, true);
    _LateralMovement (-48, -24, 1000, true);
    _AngularMovement(90, 750, false);
    BFlywheel.move(127);
    _LateralMovement (-24, -24, 1000, true);
    BFlywheel.brake();
    _AngularMovement (45, 1000, false);

    //_LateralMovement (-12, -12, 750, true);
    //_OuttakeL (750);

    _LateralMovement (-48, -48, 1750, false);
    _AngularMovement( 270, 1000, false);
    _LateralMovement(-24, -48, 1000, false);
    _OuttakeT (2000);
    PneumaticLoad.set_value(true);
    BFlywheel.move(127);
    _LateralMovement (-72, -48, 1500, true);
    pros::delay(1000);
    BFlywheel.brake();
    _LateralMovement (-24, -48, 1500, false);
    _OuttakeT(2000);
    */
}

void _PathLemN () {

    chassis.setBrakeMode (pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose (-48, 0, 270, false);

    BFlywheel.move(127);
    TFlywheel.move(127);
    _LateralMovement(-36, 0, 1500, false);
    _LateralMovement(-96, 0, 5000, true);
    pros::delay(10000);
    BFlywheel.brake();  
    TFlywheel.brake();

}

void _PathLemS () {

    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(-48, 14, 0, false);

    PneumaticLoad.set_value(true);
    _LateralMovement(-48, 48, 1500, true);
    chassis.setPose(-48, 48, 0, false);
    _AngularMovement(270, 750, false);
    BFlywheel.move(127);
    _LateralMovement(-72, 48, 1500, true);
    pros::delay(1000);
    BFlywheel.brake();
    _LateralMovement(-28, 48, 1500, false);
    chassis.setPose(-30, 48, 270, false);
    _OuttakeT(2000);
    _LateralMovement(-54, 48, 1500, true);
    chassis.setPose(-48, 48, 270, false);   
    _AngularMovement(180, 1000, false);

    
    _LateralMovement(-45, -48, 2500, true);
    chassis.setPose(-48, -48, 180, false);
    _AngularMovement(270, 1000, true);
    BFlywheel.move(127);
    _LateralMovement(-72, -48, 1500, true);
    chassis.setPose(-72, -48, 270, false);
    pros::delay(1000);
    BFlywheel.brake();
    _LateralMovement(-30, -48, 1500, false);
    chassis.setPose(-30, -48, 270, false);
    _OuttakeT(2000);
    
}

void _PathLemA () {

    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(0, 0, 0, false);
    
    _LateralMovement (0, 8, 1000, true);


}