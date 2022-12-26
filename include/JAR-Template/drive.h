#pragma once
#include "vex.h"

class Drive
{
private:
  float wheel_diameter;
  float wheel_ratio;
  float gyro_scale;
  float drive_in_to_deg_ratio;
  float tracker_diameter;
  float tracker_in_to_deg_ratio;
  float ForwardTracker_center_distance;
  float SidewaysTracker_center_distance;

public:
  enum drive_setup {ZERO_TRACKER, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, HOLONOMIC_TWO_ROTATION}; 
  drive_setup drive_setup;
  motor_group DriveL;
  motor_group DriveR;
  inertial Gyro;
  motor DriveLF = motor(PORT1);
  motor DriveRF = motor(PORT1);
  motor DriveLB = motor(PORT1);
  motor DriveRB = motor(PORT1);
  rotation R_ForwardTracker = rotation(PORT1);
  rotation R_SidewaysTracker = rotation(PORT1);
  encoder E_ForwardTracker = encoder(Brain.ThreeWirePort.A);
  encoder E_SidewaysTracker = encoder(Brain.ThreeWirePort.A);

  float turn_max_voltage;
  float turn_kp;
  float turn_ki;
  float turn_kd;
  float turn_starti;

  float turn_settle_error;
  float turn_settle_time;
  float turn_timeout;

  float drive_max_voltage;
  float drive_kp;
  float drive_ki;
  float drive_kd;
  float drive_starti;

  float drive_settle_error;
  float drive_settle_time;
  float drive_timeout;

  float heading_max_voltage;
  float heading_kp;
  float heading_ki;
  float heading_kd;
  float heading_starti;

  float swing_max_voltage;
  float swing_kp;
  float swing_ki;
  float swing_kd;
  float swing_starti;

  float swing_settle_error;
  float swing_settle_time;
  float swing_timeout;

  //ZERO TRACKER:
  Drive(motor_group DriveL, motor_group DriveR, inertial Gyro, float wheel_diameter, float wheel_ratio, float gyro_scale, int NULL_DriveLF, int NULL_DriveRF, int NULL_DriveLB, int NULL_DriveRB, int NULL_ForwardTracker, int NULL_SidewaysTracker, int NULL_tracker_diameter, int NULL_ForwardTracker_center_distance, int NULL_SidewaysTracker_center_distance);
  //TANK ONE ENCODER:
  Drive(motor_group DriveL, motor_group DriveR, inertial Gyro, float wheel_diameter, float wheel_ratio, float gyro_scale, int NULL_DriveLF, int NULL_DriveRF, int NULL_DriveLB, int NULL_DriveRB, encoder E_ForwardTracker, int NULL_SidewaysTracker, float tracker_diameter, float ForwardTracker_center_distance, int NULL_SidewaysTracker_center_distance);
  //TANK ONE ROTATION:
  Drive(motor_group DriveL, motor_group DriveR, inertial Gyro, float wheel_diameter, float wheel_ratio, float gyro_scale, int NULL_DriveLF, int NULL_DriveRF, int NULL_DriveLB, int NULL_DriveRB, rotation R_ForwardTracker, int NULL_SidewaysTracker, float tracker_diameter, float ForwardTracker_center_distance, int NULL_SidewaysTracker_center_distance);
  //TANK TWO ENCODER:
  Drive(motor_group DriveL, motor_group DriveR, inertial Gyro, float wheel_diameter, float wheel_ratio, float gyro_scale, int NULL_DriveLF, int NULL_DriveRF, int NULL_DriveLB, int NULL_DriveRB, encoder E_ForwardTracker, encoder E_SidewaysTracker, float tracker_diameter, float ForwardTracker_center_distance, float SidewaysTracker_center_distance);
  //TANK TWO ROTATION:
  Drive(motor_group DriveL, motor_group DriveR, inertial Gyro, float wheel_diameter, float wheel_ratio, float gyro_scale, int NULL_DriveLF, int NULL_DriveRF, int NULL_DriveLB, int NULL_DriveRB, rotation R_ForwardTracker, rotation R_SidewaysTracker, float tracker_diameter, float ForwardTracker_center_distance, float SidewaysTracker_center_distance);
  //HOLONOMIC TWO ENCODER:
  Drive(motor_group DriveL, motor_group DriveR, inertial Gyro, float wheel_diameter, float wheel_ratio, float gyro_scale, motor DriveLF, motor DriveRF, motor DriveLB, motor DriveRB, encoder E_ForwardTracker, encoder E_SidewaysTracker, float tracker_diameter, float ForwardTracker_center_distance, float SidewaysTracker_center_distance);
  //HOLOMONIC TWO ROTATION:
  Drive(motor_group DriveL, motor_group DriveR, inertial Gyro, float wheel_diameter, float wheel_ratio, float gyro_scale, motor DriveLF, motor DriveRF, motor DriveLB, motor DriveRB, rotation R_ForwardTracker, rotation R_SidewaysTracker, float tracker_diameter, float ForwardTracker_center_distance, float SidewaysTracker_center_distance); 

  void drive_with_voltage(float leftVoltage, float rightVoltage);

  float get_absolute_heading();

  float get_left_position_in();

  float get_right_position_in();

  void set_turn_constants(float turn_max_voltage, float turn_kp, float turn_ki, float turn_kd, float turn_starti); 
  void set_drive_constants(float drive_max_voltage, float drive_kp, float drive_ki, float drive_kd, float drive_starti);
  void set_heading_constants(float heading_max_voltage, float heading_kp, float heading_ki, float heading_kd, float heading_starti);
  void set_swing_constants(float swing_max_voltage, float swing_kp, float swing_ki, float swing_kd, float swing_starti);

  void set_turn_exit_conditions(float turn_settle_error, float turn_settle_time, float turn_timeout);
  void set_drive_exit_conditions(float drive_settle_error, float drive_settle_time, float drive_timeout);
  void set_swing_exit_conditions(float swing_settle_error, float swing_settle_time, float swing_timeout);

  void turn_to_angle(float angle);
  void turn_to_angle(float angle, float turn_max_voltage);
  void turn_to_angle(float angle, float turn_max_voltage, float turn_settle_error, float turn_settle_time, float turn_timeout);
  void turn_to_angle(float angle, float turn_max_voltage, float turn_settle_error, float turn_settle_time, float turn_timeout, float turn_kp, float turn_ki, float turn_kd, float turn_starti);

  void drive_distance(float distance);
  void drive_distance(float distance, float heading);
  void drive_distance(float distance, float heading, float drive_max_voltage, float heading_max_voltage);
  void drive_distance(float distance, float heading, float drive_max_voltage, float heading_max_voltage, float drive_settle_error, float drive_settle_time);
  void drive_distance(float distance, float heading, float drive_max_voltage, float heading_max_voltage, float drive_settle_error, float drive_settle_time, float drive_timeout, float drive_kp, float drive_ki, float drive_kd, float drive_starti, float heading_kp, float heading_ki, float heading_kd, float heading_starti);

  void left_swing_to_angle(float angle);
  void left_swing_to_angle(float angle, float swing_max_voltage, float swing_settle_error, float swing_settle_time, float swing_timeout, float swing_kp, float swing_ki, float swing_kd, float swing_starti);
  void right_swing_to_angle(float angle);
  void right_swing_to_angle(float angle, float swing_max_voltage, float swing_settle_error, float swing_settle_time, float swing_timeout, float swing_kp, float swing_ki, float swing_kd, float swing_starti);
};