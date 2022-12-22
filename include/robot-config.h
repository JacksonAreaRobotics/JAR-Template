using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Motor1;
extern motor Motor2;
extern motor Motor8;
extern motor Motor9;
extern rotation Rotation3;
extern rotation Rotation10;
extern inertial Inertial4;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );