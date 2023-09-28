#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
limit LimitSwitchH = limit(Brain.ThreeWirePort.H);
motor MotorGroup9MotorA = motor(PORT9, ratio36_1, false);
motor MotorGroup9MotorB = motor(PORT16, ratio36_1, true);
motor_group MotorGroup9 = motor_group(MotorGroup9MotorA, MotorGroup9MotorB);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}