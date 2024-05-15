#include "vex.h"

/**
 * Converts an angle to an equivalent one in the range [0, 360).
 * 
 * @param angle The angle to be reduced in degrees.
 * @return Reduced angle.
 */

float reduce_0_to_360(float angle) {
  while(!(angle >= 0 && angle < 360)) {
    if( angle < 0 ) { angle += 360; }
    if(angle >= 360) { angle -= 360; }
  }
  return(angle);
}

/**
 * Converts an angle to an equivalent one in the range [-180, 180).
 * 
 * @param angle The angle to be reduced in degrees.
 * @return Reduced angle.
 */

float reduce_negative_180_to_180(float angle) {
  while(!(angle >= -180 && angle < 180)) {
    if( angle < -180 ) { angle += 360; }
    if(angle >= 180) { angle -= 360; }
  }
  return(angle);
}

/**
 * Converts an angle to an equivalent one in the range [-90, 90).
 * If the angle has no equivalent, then the angle halfway around
 * the circle is returned.
 * 
 * @param angle The angle to be reduced in degrees.
 * @return Reduced angle.
 */

float reduce_negative_90_to_90(float angle) {
  while(!(angle >= -90 && angle < 90)) {
    if( angle < -90 ) { angle += 180; }
    if(angle >= 90) { angle -= 180; }
  }
  return(angle);
}

/**
 * Converts an angle in degrees to radians.
 * 
 * @param angle The angle in degrees.
 * @return Angle in radians.
 */

float to_rad(float angle_deg){
  return(angle_deg/(180.0/M_PI));
}

/**
 * Converts an angle in radians to degrees.
 * 
 * @param angle The angle in radians.
 * @return Angle in degrees.
 */

float to_deg(float angle_rad){
  return(angle_rad*(180.0/M_PI));
}

/**
 * "Clamps" a number between a min and max.
 * Does no error checking and assumes min is less
 * than or equal to max.
 * 
 * @param input The number to be clamped.
 * @param min Minimum edge of the clamp.
 * @param max Maximum edge of the clamp.
 * @return Clamped number.
 */

float clamp(float input, float min, float max){
  if( input > max ){ return(max); }
  if(input < min){ return(min); }
  return(input);
}

/**
 * Checks if an input number corresponds to a reversed drive port.
 * 
 * @param input The number to be checked.
 * @return Whether the input is negative.
 */

bool is_reversed(double input){
  if(input<0) return(true);
  return(false);
}

/**
 * Scales a joystick to drive voltage scale.
 * Values get multiplied by 12 because motors can
 * output a max of 12 volts.
 * 
 * @param percent The input joystick reading.
 * @return The equivalent value in volts.
 */

float to_volt(float percent){
  return(percent*12.0/100.0);
}

/**
 * Converts an input port to a triport.
 * Does error checking to prevent invalid values from being
 * passed to the triport array.
 * 
 * @param port Input integer port.
 * @return Port-1, to convert it to a triport.
 */

int to_port(int port){
  if(port > 8 || port < 0){
    return(0);
  }
  return(port-1);
}

/**
 * Deadband function for joystick control.
 * If the joystick value is small, we should just consider it 0.
 * 
 * @param input The input joystick value.
 * @param width Minimum value to not get zeroed out.
 * @return The deadbanded value.
 */

float deadband(float input, float width){
  if (fabs(input)<width){
    return(0);
  }
  return(input);
}