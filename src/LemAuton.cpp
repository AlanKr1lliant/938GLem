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
    chassis.waitUntilDone();

   //_AngularMovement (180, 5000, true);
   //chassis.waitUntilDone();
}

void _PathLemL () {

    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(-48, 16, 90, false);
    _AngularMovement(180, 750, true);
    _LateralMovement (-48, 24, 1000, true);
    _AngularMovement(90, 750, false);
    BFlywheel.move(127);
    _LateralMovement (-24, 24, 1000, true);
    BFlywheel.brake();
    _AngularMovement (135, 1000, true);

    //_AngularMovement (315, 1500, true);
    //_AngularMovement (-12, 12, false);
    //_OuttakeT (750);
    //_AngularMovement (45, 1500, true);

    _LateralMovement (-48, 48, 1750, false);
    _AngularMovement( 270, 1000, false);
    _LateralMovement(-24, 48, 1000, false);
    _OuttakeT (2000);
    PneumaticLoad.set_value(true);
    BFlywheel.move(127);
    _LateralMovement (-72, 48, 1500, true);
    pros::delay(1000);
    BFlywheel.brake();
    _LateralMovement (-24, 48, 1500, false);
    _OuttakeT(2000);


}

void _PathLemR () {

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

}

void _PathLemN () {

    chassis.setBrakeMode (pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose (0, 0, 0, false);
    chassis.cancelAllMotions();

}

void _PathLemS () {

    chassis.setBrakeMode (pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose (-48, 0, 0, false);

     chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(-48, -16, 90, false);
    _AngularMovement(180, 750, true);
    _LateralMovement (-48, -24, 1000, true);
    _AngularMovement(90, 750, false);
    BFlywheel.move_velocity(600);
    _LateralMovement (-24, -24, 1000, true);
    BFlywheel.brake();
    _AngularMovement (45, 1000, false);

    _LateralMovement (-12, -12, 750, true);
    _OuttakeL (750);

    _LateralMovement (-48, -48, 1750, false);
    _AngularMovement( 270, 1000, false);
    _LateralMovement(-24, -48, 1000, false);
    _OuttakeT (2000);
    PneumaticLoad.set_value(true);
    BFlywheel.move_velocity(600);
    _LateralMovement (-72, -48, 1500, true);
    pros::delay(1000);
    BFlywheel.brake();
    _LateralMovement (-24, -48, 1500, false);
    _OuttakeT(2000);

    _LateralMovement (-48, -48, 1500, true);
    _LateralMovement (-48, 24, 1000, true);
    _AngularMovement(90, 750, false);
    BFlywheel.move(127);
    _LateralMovement (-24, 24, 1000, true);
    BFlywheel.brake();
    _AngularMovement (135, 1000, true);

    _AngularMovement (315, 1500, true);
    _AngularMovement (-12, 12, false);
    _OuttakeT (750);
    _AngularMovement (45, 1500, true);

    _LateralMovement (-48, 48, 1750, false);
    _AngularMovement( 270, 1000, false);
    _LateralMovement(-24, 48, 1000, false);
    _OuttakeT (2000);
    PneumaticLoad.set_value(true);
    BFlywheel.move(127);
    _LateralMovement (-72, 48, 1500, true);
    pros::delay(1000);
    BFlywheel.brake();
    _LateralMovement (-24, 48, 1500, false);
    _OuttakeT(2000);
    _LateralMovement (-48, 48, 1000, true);

    _AngularMovement (180, 1000, true);
    _LateralMovement(-48, 24, 1500);
    _AngularMovement (270, 1000, true);
    _LateralMovement (-60, 24, 750, true);
    _AngularMovement(180, 750, false);
    _LateralMovement (-60, -12, 2000, true);



}

void _PathLemA () {

    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(0, 0, 0, false);
    
    _LateralMovement (0, 4, 1000, true);


}