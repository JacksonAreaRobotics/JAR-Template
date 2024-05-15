#include "vex.h"

/**
 * PID constructor with P, I, D, and starti.
 * Starti keeps the I term at 0 until error is less than starti.
 * 
 * @param error Difference in desired and current position.
 * @param kp Proportional constant.
 * @param ki Integral constant.
 * @param kd Derivative constant.
 * @param starti Maximum error to start integrating.
 */

PID::PID(float error, float kp, float ki, float kd, float starti) :
  error(error),
  kp(kp),
  ki(ki),
  kd(kd),
  starti(starti)
{};

/**
 * PID constructor with settling inputs.
 * The settling system works like this: The robot is settled
 * when error is less than settle_error for a duration of settle_time,
 * or if the function has gone on for longer than timeout. Otherwise
 * it is not settled. Starti keeps the I term at 0 until error is less 
 * than starti.
 * 
 * @param error Difference in desired and current position.
 * @param kp Proportional constant.
 * @param ki Integral constant.
 * @param kd Derivative constant.
 * @param starti Maximum error to start integrating.
 * @param settle_error Maximum error to be considered settled.
 * @param settle_time Minimum time to be considered settled.
 * @param timeout Time after which to give up and move on.
 */

PID::PID(float error, float kp, float ki, float kd, float starti, 
float settle_error, float settle_time, float timeout) :
  error(error),
  kp(kp),
  ki(ki),
  kd(kd),
  starti(starti),
  settle_error(settle_error),
  settle_time(settle_time),
  timeout(timeout)
{};

/**
 * PID constructor with custom update period.
 * The default update period is 10ms, but if you want to run
 * a faster or slower loop, you need to let the settler know.
 * 
 * @param error Difference in desired and current position.
 * @param kp Proportional constant.
 * @param ki Integral constant.
 * @param kd Derivative constant.
 * @param starti Maximum error to start integrating.
 * @param settle_error Maximum error to be considered settled.
 * @param settle_time Minimum time to be considered settled.
 * @param timeout Time after which to give up and move on.
 * @param update_period Loop delay time in ms.
 */

PID::PID(float error, float kp, float ki, float kd, float starti, 
float settle_error, float settle_time, float timeout, float update_period) :
  error(error),
  kp(kp),
  ki(ki),
  kd(kd),
  starti(starti),
  settle_error(settle_error),
  settle_time(settle_time),
  timeout(timeout),
  update_period(update_period)
{};

/**
 * Computes the output power based on the error.
 * Typical PID calculation with some optimizations: When the robot crosses
 * error=0, the i-term gets reset to 0. And, of course, the robot only
 * accumulates i-term when error is less than starti. Read about these at
 * https://georgegillard.com/resources/documents.
 * 
 * @param error Difference in desired and current position.
 * @return Output power.
 */

float PID::compute(float error){
  if (fabs(error) < starti){
    accumulated_error+=error;
  }
  // Checks if the error has crossed 0, and if it has, it eliminates the integral term.
  if ((error>0 && previous_error<0)||(error<0 && previous_error>0)){ 
    accumulated_error = 0; 
  }

  output = kp*error + ki*accumulated_error + kd*(error-previous_error);

  previous_error=error;

  if(fabs(error)<settle_error){
    time_spent_settled+=10;
  } else {
    time_spent_settled = 0;
  }

  time_spent_running+=10;

  return output;
}

/**
 * Computes whether or not the movement has settled.
 * The robot is considered settled when error is less than settle_error 
 * for a duration of settle_time, or if the function has gone on for 
 * longer than timeout. Otherwise it is not settled.
 * 
 * @return Whether the movement is settled.
 */

bool PID::is_settled(){
  if (time_spent_running>timeout && timeout != 0){
    return(true);
  } // If timeout does equal 0, the move will never actually time out. Setting timeout to 0 is the 
    // equivalent of setting it to infinity.
  if (time_spent_settled>settle_time){
    return(true);
  }
  return(false);
}