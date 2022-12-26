#include "vex.h"

//ZERO TRACKER:
Drive::Drive(motor_group DriveL, motor_group DriveR, inertial Gyro, float wheel_diameter, float wheel_ratio, float gyro_scale, int NULL_DriveLF, int NULL_DriveRF, int NULL_DriveLB, int NULL_DriveRB, int NULL_ForwardTracker, int NULL_SidewaysTracker, int NULL_tracker_diameter, int NULL_ForwardTracker_center_distance, int NULL_SidewaysTracker_center_distance) :
  wheel_diameter(wheel_diameter),
  wheel_ratio(wheel_ratio),
  gyro_scale(gyro_scale),
  DriveL(DriveL),
  DriveR(DriveR),
  Gyro(Gyro)
{
  drive_in_to_deg_ratio = wheel_ratio/360.0*M_PI*wheel_diameter;
  drive_setup = ZERO_TRACKER;
};

//TANK ONE ENCODER:
Drive::Drive(motor_group DriveL, motor_group DriveR, inertial Gyro, float wheel_diameter, float wheel_ratio, float gyro_scale, int NULL_DriveLF, int NULL_DriveRF, int NULL_DriveLB, int NULL_DriveRB, encoder E_ForwardTracker, int NULL_SidewaysTracker, float tracker_diameter, float ForwardTracker_center_distance, int NULL_SidewaysTracker_center_distance) :
  wheel_diameter(wheel_diameter),
  wheel_ratio(wheel_ratio),
  gyro_scale(gyro_scale),
  tracker_diameter(tracker_diameter),
  ForwardTracker_center_distance(ForwardTracker_center_distance),
  DriveL(DriveL),
  DriveR(DriveR),
  Gyro(Gyro),
  E_ForwardTracker(E_ForwardTracker)
{
  drive_in_to_deg_ratio = wheel_ratio/360.0*M_PI*wheel_diameter;
  tracker_in_to_deg_ratio = M_PI/360.0*tracker_diameter;
  drive_setup = TANK_ONE_ENCODER;
};

//TANK ONE ROTATION:
Drive::Drive(motor_group DriveL, motor_group DriveR, inertial Gyro, float wheel_diameter, float wheel_ratio, float gyro_scale, int NULL_DriveLF, int NULL_DriveRF, int NULL_DriveLB, int NULL_DriveRB, rotation R_ForwardTracker, int NULL_SidewaysTracker, float tracker_diameter, float ForwardTracker_center_distance, int NULL_SidewaysTracker_center_distance) :
  wheel_diameter(wheel_diameter),
  wheel_ratio(wheel_ratio),
  gyro_scale(gyro_scale),
  tracker_diameter(tracker_diameter),
  ForwardTracker_center_distance(ForwardTracker_center_distance),
  DriveL(DriveL),
  DriveR(DriveR),
  Gyro(Gyro),
  R_ForwardTracker(R_ForwardTracker)
{
  drive_in_to_deg_ratio = wheel_ratio/360.0*M_PI*wheel_diameter;
  tracker_in_to_deg_ratio = M_PI/360.0*tracker_diameter;
  drive_setup = TANK_ONE_ROTATION;
};

//TANK TWO ENCODER:
Drive::Drive(motor_group DriveL, motor_group DriveR, inertial Gyro, float wheel_diameter, float wheel_ratio, float gyro_scale, int NULL_DriveLF, int NULL_DriveRF, int NULL_DriveLB, int NULL_DriveRB, encoder E_ForwardTracker, encoder E_SidewaysTracker, float tracker_diameter, float ForwardTracker_center_distance, float SidewaysTracker_center_distance) :
  wheel_diameter(wheel_diameter),
  wheel_ratio(wheel_ratio),
  gyro_scale(gyro_scale),
  tracker_diameter(tracker_diameter),
  ForwardTracker_center_distance(ForwardTracker_center_distance),
  SidewaysTracker_center_distance(SidewaysTracker_center_distance),
  DriveL(DriveL),
  DriveR(DriveR),
  Gyro(Gyro),
  E_ForwardTracker(E_ForwardTracker),
  E_SidewaysTracker(E_SidewaysTracker)
{
  drive_in_to_deg_ratio = wheel_ratio/360.0*M_PI*wheel_diameter;
  tracker_in_to_deg_ratio = M_PI/360.0*tracker_diameter;
  drive_setup = TANK_TWO_ENCODER;
};

//TANK TWO ROTATION:
Drive::Drive(motor_group DriveL, motor_group DriveR, inertial Gyro, float wheel_diameter, float wheel_ratio, float gyro_scale, int NULL_DriveLF, int NULL_DriveRF, int NULL_DriveLB, int NULL_DriveRB, rotation R_ForwardTracker, rotation R_SidewaysTracker, float tracker_diameter, float ForwardTracker_center_distance, float SidewaysTracker_center_distance) :
  wheel_diameter(wheel_diameter),
  wheel_ratio(wheel_ratio),
  gyro_scale(gyro_scale),
  tracker_diameter(tracker_diameter),
  ForwardTracker_center_distance(ForwardTracker_center_distance),
  SidewaysTracker_center_distance(SidewaysTracker_center_distance),
  DriveL(DriveL),
  DriveR(DriveR),
  Gyro(Gyro),
  R_ForwardTracker(R_ForwardTracker),
  R_SidewaysTracker(R_SidewaysTracker)
{
  drive_in_to_deg_ratio = wheel_ratio/360.0*M_PI*wheel_diameter;
  tracker_in_to_deg_ratio = M_PI/360.0*tracker_diameter;
  drive_setup = TANK_TWO_ROTATION;
};

//HOLONOMIC TWO ENCODER:
Drive::Drive(motor_group DriveL, motor_group DriveR, inertial Gyro, float wheel_diameter, float wheel_ratio, float gyro_scale, motor DriveLF, motor DriveRF, motor DriveLB, motor DriveRB, encoder E_ForwardTracker, encoder E_SidewaysTracker, float tracker_diameter, float ForwardTracker_center_distance, float SidewaysTracker_center_distance) :
  wheel_diameter(wheel_diameter),
  wheel_ratio(wheel_ratio),
  gyro_scale(gyro_scale),
  tracker_diameter(tracker_diameter),
  ForwardTracker_center_distance(ForwardTracker_center_distance),
  SidewaysTracker_center_distance(SidewaysTracker_center_distance),
  DriveL(DriveL),
  DriveR(DriveR),
  Gyro(Gyro),
  DriveLF(DriveLF),
  DriveRF(DriveRF),
  DriveLB(DriveLB),
  DriveRB(DriveRB),
  E_ForwardTracker(E_ForwardTracker),
  E_SidewaysTracker(E_SidewaysTracker)
{
  drive_in_to_deg_ratio = wheel_ratio/360.0*M_PI*wheel_diameter;
  tracker_in_to_deg_ratio = M_PI/360.0*tracker_diameter;
  drive_setup = HOLONOMIC_TWO_ENCODER;
};

//HOLONOMIC TWO ROTATION:
Drive::Drive(motor_group DriveL, motor_group DriveR, inertial Gyro, float wheel_diameter, float wheel_ratio, float gyro_scale, motor DriveLF, motor DriveRF, motor DriveLB, motor DriveRB, rotation R_ForwardTracker, rotation R_SidewaysTracker, float tracker_diameter, float ForwardTracker_center_distance, float SidewaysTracker_center_distance) :
  wheel_diameter(wheel_diameter),
  wheel_ratio(wheel_ratio),
  gyro_scale(gyro_scale),
  tracker_diameter(tracker_diameter),
  ForwardTracker_center_distance(ForwardTracker_center_distance),
  SidewaysTracker_center_distance(SidewaysTracker_center_distance),
  DriveL(DriveL),
  DriveR(DriveR),
  Gyro(Gyro),
  DriveLF(DriveLF),
  DriveRF(DriveRF),
  DriveLB(DriveLB),
  DriveRB(DriveRB),
  R_ForwardTracker(R_ForwardTracker),
  R_SidewaysTracker(R_SidewaysTracker)
{
  drive_in_to_deg_ratio = wheel_ratio/360.0*M_PI*wheel_diameter;
  tracker_in_to_deg_ratio = M_PI/360.0*tracker_diameter;
  drive_setup = HOLONOMIC_TWO_ROTATION;
};

void Drive::drive_with_voltage(float leftVoltage, float rightVoltage){
  DriveL.spin(fwd, leftVoltage, volt);
  DriveR.spin(fwd, rightVoltage,volt);
}

void Drive::set_turn_constants(float turn_max_voltage, float turn_kp, float turn_ki, float turn_kd, float turn_starti){
  this->turn_max_voltage = turn_max_voltage;
  this->turn_kp = turn_kp;
  this->turn_ki = turn_ki;
  this->turn_kd = turn_kd;
  this->turn_starti = turn_starti;
} 

void Drive::set_drive_constants(float drive_max_voltage, float drive_kp, float drive_ki, float drive_kd, float drive_starti){
  this->drive_max_voltage = drive_max_voltage;
  this->drive_kp = drive_kp;
  this->drive_ki = drive_ki;
  this->drive_kd = drive_kd;
  this->drive_starti = drive_starti;
} 

void Drive::set_heading_constants(float heading_max_voltage, float heading_kp, float heading_ki, float heading_kd, float heading_starti){
  this->heading_max_voltage = heading_max_voltage;
  this->heading_kp = heading_kp;
  this->heading_ki = heading_ki;
  this->heading_kd = heading_kd;
  this->heading_starti = heading_starti;
}

void Drive::set_swing_constants(float swing_max_voltage, float swing_kp, float swing_ki, float swing_kd, float swing_starti){
  this->swing_max_voltage = swing_max_voltage;
  this->swing_kp = swing_kp;
  this->swing_ki = swing_ki;
  this->swing_kd = swing_kd;
  this->swing_starti = swing_starti;
} 

void Drive::set_turn_exit_conditions(float turn_settle_error, float turn_settle_time, float turn_timeout){
  this->turn_settle_error = turn_settle_error;
  this->turn_settle_time = turn_settle_time;
  this->turn_timeout = turn_timeout;
}

void Drive::set_drive_exit_conditions(float drive_settle_error, float drive_settle_time, float drive_timeout){
  this->drive_settle_error = drive_settle_error;
  this->drive_settle_time = drive_settle_time;
  this->drive_timeout = drive_timeout;
}

void Drive::set_swing_exit_conditions(float swing_settle_error, float swing_settle_time, float swing_timeout){
  this->swing_settle_error = swing_settle_error;
  this->swing_settle_time = swing_settle_time;
  this->swing_timeout = swing_timeout;
}

float Drive::get_absolute_heading(){ 
  return( reduce_0_to_360( Gyro.rotation()*360.0/gyro_scale ) ); 
}

float Drive::get_left_position_in(){
  return( DriveL.position(deg)*drive_in_to_deg_ratio );
}

float Drive::get_right_position_in(){
  return( DriveL.position(deg)*drive_in_to_deg_ratio );
}

void Drive::turn_to_angle(float angle){
  turn_to_angle(angle, turn_max_voltage, turn_settle_error, turn_settle_time, turn_timeout, turn_kp, turn_ki, turn_kd, turn_starti);
}

void Drive::turn_to_angle(float angle, float turn_max_voltage){
  turn_to_angle(angle, turn_max_voltage, turn_settle_error, turn_settle_time, turn_timeout, turn_kp, turn_ki, turn_kd, turn_starti);
}

void Drive::turn_to_angle(float angle, float turn_max_voltage, float turn_settle_error, float turn_settle_time, float turn_timeout){
  turn_to_angle(angle, turn_max_voltage, turn_settle_error, turn_settle_time, turn_timeout, turn_kp, turn_ki, turn_kd, turn_starti);
}

void Drive::turn_to_angle(float angle, float turn_max_voltage, float turn_settle_error, float turn_settle_time, float turn_timeout, float turn_kp, float turn_ki, float turn_kd, float turn_starti){
  PID turnPID(reduce_negative_180_to_180(angle - get_absolute_heading()), turn_kp, turn_ki, turn_kd, turn_starti, turn_settle_error, turn_settle_time, turn_timeout);
  while(turnPID.settled == false){
    float error = reduce_negative_180_to_180(angle - get_absolute_heading());
    float output = turnPID.compute(error);
    output = clamp(output, -turn_max_voltage, turn_max_voltage);
    drive_with_voltage(output, -output);
    task::sleep(10);
  }
  DriveL.stop(hold);
  DriveR.stop(hold);
}

void Drive::drive_distance(float distance){
  drive_distance(distance, get_absolute_heading(), drive_max_voltage, heading_max_voltage, drive_settle_error, drive_settle_time, drive_timeout, drive_kp, drive_ki, drive_kd, drive_starti, heading_kp, heading_ki, heading_kd, heading_starti);
}

void Drive::drive_distance(float distance, float heading){
  drive_distance(distance, heading, drive_max_voltage, heading_max_voltage, drive_settle_error, drive_settle_time, drive_timeout, drive_kp, drive_ki, drive_kd, drive_starti, heading_kp, heading_ki, heading_kd, heading_starti);
}

void Drive::drive_distance(float distance, float heading, float drive_max_voltage, float heading_max_voltage){
  drive_distance(distance, heading, drive_max_voltage, heading_max_voltage, drive_settle_error, drive_settle_time, drive_timeout, drive_kp, drive_ki, drive_kd, drive_starti, heading_kp, heading_ki, heading_kd, heading_starti);
}

void Drive::drive_distance(float distance, float heading, float drive_max_voltage, float heading_max_voltage, float drive_settle_error, float drive_settle_time){
  drive_distance(distance, heading, drive_max_voltage, heading_max_voltage, drive_settle_error, drive_settle_time, drive_timeout, drive_kp, drive_ki, drive_kd, drive_starti, heading_kp, heading_ki, heading_kd, heading_starti);
}

void Drive::drive_distance(float distance, float heading, float drive_max_voltage, float heading_max_voltage, float drive_settle_error, float drive_settle_time, float drive_timeout, float drive_kp, float drive_ki, float drive_kd, float drive_starti, float heading_kp, float heading_ki, float heading_kd, float heading_starti){
  PID drivePID(distance, drive_kp, drive_ki, drive_kd, drive_starti, drive_settle_error, drive_settle_time, drive_timeout);
  PID headingPID(reduce_negative_180_to_180(heading - get_absolute_heading()), heading_kp, heading_ki, heading_kd, heading_starti);
  float start_average_position = (get_left_position_in()+get_right_position_in())/2.0;
  float average_position = start_average_position;
  while(drivePID.settled == false){
    average_position = (get_left_position_in()+get_right_position_in())/2.0;
    float drive_error = distance+start_average_position-average_position;
    float heading_error = reduce_negative_180_to_180(heading - get_absolute_heading());
    float drive_output = drivePID.compute(drive_error);
    float heading_output = headingPID.compute(heading_error);

    drive_output = clamp(drive_output, -drive_max_voltage, drive_max_voltage);
    heading_output = clamp(heading_output, -heading_max_voltage, heading_max_voltage);

    drive_with_voltage(drive_output+heading_output, drive_output-heading_output);
    task::sleep(10);
  }
}

void Drive::left_swing_to_angle(float angle){
  left_swing_to_angle(angle, swing_max_voltage, swing_settle_error, swing_settle_time, swing_timeout, swing_kp, swing_ki, swing_kd, swing_starti);
}

void Drive::left_swing_to_angle(float angle, float swing_max_voltage, float swing_settle_error, float swing_settle_time, float swing_timeout, float swing_kp, float swing_ki, float swing_kd, float swing_starti){
  PID swingPID(reduce_negative_180_to_180(angle - get_absolute_heading()), swing_kp, swing_ki, swing_kd, swing_starti, swing_settle_error, swing_settle_time, swing_timeout);
  while(swingPID.settled == false){
    float error = reduce_negative_180_to_180(angle - get_absolute_heading());
    float output = swingPID.compute(error);
    output = clamp(output, -turn_max_voltage, turn_max_voltage);
    DriveL.spin(fwd, output, volt);
    DriveR.stop(hold);
    task::sleep(10);
  }
  DriveL.stop(hold);
  DriveR.stop(hold);
}

void Drive::right_swing_to_angle(float angle){
  right_swing_to_angle(angle, swing_max_voltage, swing_settle_error, swing_settle_time, swing_timeout, swing_kp, swing_ki, swing_kd, swing_starti);
}

void Drive::right_swing_to_angle(float angle, float swing_max_voltage, float swing_settle_error, float swing_settle_time, float swing_timeout, float swing_kp, float swing_ki, float swing_kd, float swing_starti){
  PID swingPID(reduce_negative_180_to_180(angle - get_absolute_heading()), swing_kp, swing_ki, swing_kd, swing_starti, swing_settle_error, swing_settle_time, swing_timeout);
  while(swingPID.settled == false){
    float error = reduce_negative_180_to_180(angle - get_absolute_heading());
    float output = swingPID.compute(error);
    output = clamp(output, -turn_max_voltage, turn_max_voltage);
    DriveR.spin(reverse, output, volt);
    DriveL.stop(hold);
    task::sleep(10);
  }
  DriveL.stop(hold);
  DriveR.stop(hold);
}