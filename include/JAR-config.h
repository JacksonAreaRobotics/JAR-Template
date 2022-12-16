using namespace vex;

extern brain Brain;

extern motor_group DriveL;
extern motor_group DriveR;

extern int sensorsetup;

extern float input_to_output;

extern float wheel_diameter;

extern float center_to_right_wheel_distance;
extern float center_to_left_wheel_distance;
extern float center_to_back_wheel_distance;

extern float right_wheel_size;
extern float left_wheel_size;
extern float back_wheel_size;

extern float drive_max_voltage;

extern float heading_max_voltage;

extern float turn_max_voltage;

extern float drive_kp;
extern float drive_ki;
extern float drive_kd;
extern float drive_start_i;

extern float heading_kp;
extern float heading_ki;
extern float heading_kd;
extern float heading_start_i;

extern float turn_kp;
extern float turn_ki;
extern float turn_kd;
extern float turn_start_i;

extern float turn_error_margin_deg;
extern float turn_settling_time_ms;

//Do the same for default error margins and settling times for the drive.

extern float drive_error_margin_in;
extern float drive_settling_time_ms;