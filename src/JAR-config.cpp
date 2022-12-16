#include "vex.h"

using namespace vex;

//Add your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).

motor_group DriveL = motor_group( );
motor_group DriveR = motor_group( );

//Pick your sensor setup, using INTERNAL_ENCODERS, ONE_ENCODER_ODOM, TWO_ENCODER_ODOM, or THREE_ENCODER_ODOM. 

int sensorsetup = TWO_ENCODER_ODOM;

//Fill in information about the chassis and sensor setup. If you are not using a sensor, skip and move to the next one.

float input_to_output = 1.333333; //Make this a decimal, not a fraction.

float wheel_diameter = 4.125;

//Fill in physical distances for trackers, measured in inches from the tracking center (typically the center of the chassis).
//If you are using only a left or only a right tracking wheel, leave the other's settings as 0.

float center_to_right_wheel_distance = 0;
float center_to_left_wheel_distance = 0;
float center_to_back_wheel_distance = 0;

float right_wheel_size = 2.75;
float left_wheel_size = 2.75;
float back_wheel_size = 2.75;

//Fill in default drive max voltage and turn max voltage. Drive max shouldn't be 12 volts because then the robot won't be able to properly correct its heading.

float drive_max_voltage = 10;

float heading_max_voltage = 8;

float turn_max_voltage = 12;

//Fill in the default PID constants for driving, heading correction, and turning. Don't worry, these can be changed in each function call.
//Right now, they are tuned fairly well for a 360 RPM drive on 3.25" wheels.
//Start_i is how small the error must become before the i term begins to integrate.

float drive_kp = 2;
float drive_ki = 0;
float drive_kd = 10;
float drive_start_i = 0;

float heading_kp = 1;
float heading_ki = 0;
float heading_kd = 3;
float heading_start_i = 0;

float turn_kp = .4;
float turn_ki = .05;
float turn_kd = 1.5;
float turn_start_i = 15;

//Fill in default error margins and settling times. 
//An error margin of 1 degree means that the robot can be one degree off and still be considered settled.
//A settling time of 200 ms means that the robot must be settled for half a second to move on.

float turn_error_margin_deg = 1;
float turn_settling_time_ms = 200;

//Do the same for default error margins and settling times for the drive.

float drive_error_margin_in = 1;
float drive_settling_time_ms = 200;