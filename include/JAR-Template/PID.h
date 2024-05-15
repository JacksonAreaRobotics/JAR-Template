#pragma once
#include "vex.h"

/**
 * General-use PID class for drivetrains. It includes both
 * control calculation and settling calculation. The default
 * update period is 10ms or 100Hz.
 */

class PID
{
public:
  float error = 0;
  float kp = 0;
  float ki = 0;
  float kd = 0;
  float starti = 0;
  float settle_error = 0;
  float settle_time = 0;
  float timeout = 0;
  float accumulated_error = 0;
  float previous_error = 0;
  float output = 0;
  float time_spent_settled = 0;
  float time_spent_running = 0;
  float update_period = 10;

  PID(float error, float kp, float ki, float kd, float starti);

  PID(float error, float kp, float ki, float kd, float starti, float settle_error, float settle_time, float timeout);

  PID(float error, float kp, float ki, float kd, float starti, float settle_error, float settle_time, float timeout, float update_period);

  float compute(float error);

  bool is_settled();
};