/**
 * 2026 Pushback Tournament
 * Team 938G Coder ARM
 * Pros ProsAuton.h 
 */

//Include initialized devices and ProsOp.h.
#include "LemImp.h"
#include "LemOp.h"

//Define utility variables.
double LeftY = 0;
double RightX = 0;
double PowerFactor = 1;
double TurnFactor = 1;
bool PneuDescore = false;
bool PneuMatchLoad = false;
//Define drivetrain function.
void DriveMovement() {

    /*
    Arcade style controls with left joystick being power and right joystick being direction.
    Use power and turn factors to influence analog values used to move motor groups correctly.
     */


    int LeftY = MasterCont.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) * PowerFactor;
    int RightX = MasterCont.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) * TurnFactor;
    chassis.arcade (LeftY, RightX);

}

//Define processing function.
void BlockMovement () {
    
    //Intake
    if (MasterCont.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {

        TFlywheel.brake();
        BFlywheel.move_velocity(600);

    }

    //High goal outake.
    else if (MasterCont.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){

        TFlywheel.move_velocity(600);
        BFlywheel.move_velocity(600);   

    }

    //Low goal outake.
    else if (MasterCont.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {

        TFlywheel.move_velocity(-600);
        BFlywheel.move_velocity(-600);

    } else {
        TFlywheel.brake();
        BFlywheel.brake();
    }

}

void PneuMovement () {

        //Descore
    if (MasterCont.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {

        if (PneuDescore == false) {
            
            PneumaticDescore.retract();
            PneuDescore = true;
            pros::delay(250);

        } else {

            PneumaticDescore.extend();
            PneuDescore = false;
            pros::delay(250);

        }

    }
    
   if (MasterCont.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {

        if (PneuMatchLoad== false) {

            PneumaticLoad.retract();
            PneuMatchLoad = true;
            pros::delay(250);

        } else {

            //PneuLoad.retract();
            PneumaticLoad.extend();
            PneuMatchLoad = false;
            pros::delay(250);

        }

    }

}