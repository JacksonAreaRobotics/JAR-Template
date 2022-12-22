#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Motor1 = motor(PORT1, ratio18_1, false);
motor Motor2 = motor(PORT2, ratio18_1, false);
motor Motor8 = motor(PORT8, ratio18_1, false);
motor Motor9 = motor(PORT9, ratio18_1, false);
rotation Rotation3 = rotation(PORT3, false);
rotation Rotation10 = rotation(PORT10, false);
inertial Inertial4 = inertial(PORT4);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}