#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
inertial Gyro = inertial(PORT8);
motor L1 = motor(PORT6, ratio18_1, false);
motor L2 = motor(PORT4, ratio18_1, true);
motor L3 = motor(PORT3, ratio18_1, true);
motor R1 = motor(PORT7, ratio18_1, true);
motor R2 = motor(PORT5, ratio18_1, false);
motor R3 = motor(PORT2, ratio18_1, false);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}