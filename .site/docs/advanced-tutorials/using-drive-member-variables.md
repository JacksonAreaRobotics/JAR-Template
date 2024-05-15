---
sidebar_position: 1
sidebar_label: Using Drive Member Variables
---

# Using Drive Member Variables

While coding, it is likely that you will wish to pass different drive constants to the chassis at different times in the run. Here, drive constants just refers to max voltage, kp, ki, kd, etc.

One way to do this is with the overloaded methods defined in src/JAR-Template/drive.cpp. For example, these are the overloaded methods for turning to a given angle:

```cpp
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
  desired_heading = angle;
  PID turnPID(reduce_negative_180_to_180(angle - get_absolute_heading()), turn_kp, turn_ki, turn_kd, turn_starti, turn_settle_error, turn_settle_time, turn_timeout);
  while(turnPID.is_settled() == false){
    float error = reduce_negative_180_to_180(angle - get_absolute_heading());
    float output = turnPID.compute(error);
    output = clamp(output, -turn_max_voltage, turn_max_voltage);
    drive_with_voltage(output, -output);
    task::sleep(10);
  }
  DriveL.stop(hold);
  DriveR.stop(hold);
}
```

In your autons, you can pass just the angle argument, like 

```cpp
chassis.turn_to_angle(90);
```

which is expected to be the most common usage. But imagine that you wanted the turn to be slower, or faster. You can use the overloaded method to specify the turn_max_voltage, from 0 to 12. If you wanted to turn to an angle of 90 degrees, but with a max voltage of 3, you could do it with this code:

```cpp
chassis.turn_to_angle(90, 3);
```

The problem with these overloaded methods is that they're really long. If you want to specify the turn_timeout parameter as 10000ms, you still have to type through all the parameters you want to leave at default, so your code ends up looking like this:

```cpp
chassis.turn_to_angle(90, 10, 1, 200, 10000);
```

This code is hard to read *and* write. We can get around this issue by using member variables. If I want the turn_timeout parameter to be 10000ms, I can do it as shown above. But this code is equivalent:

```cpp
chassis.turn_timeout = 10000;
chassis.turn_to_angle(90);
```
See how that's both easier to read *and* to write?

One major difference between the overloaded method and setting member variables is that the member variables carry over. So if you want to turn to angle 90 with a max voltage of 3, and then to angle 0 with a max voltage of 3, this code works:

```cpp
chassis.turn_max_voltage = 3;
chassis.turn_to_angle(90);
chassis.turn_to_angle(0);
```

If you don't like this behavior, then you can just call default_constants() to reset every parameter. So this code will turn to angle 90 at a voltage of 3, and then to 0 at whatever the default is:

```cpp
chassis.turn_max_voltage = 3;
chassis.turn_to_angle(90);
default_constants();
chassis.turn_to_angle(0);
```

This system of setting the drive class member variables is a pretty readable and on-the-fly way to make your functions do what you want when you want them to.

The left and right drive motor groups are also accessible through the drive class. So if, for example, you wanted to spin the right side of the drive forward at 12 volts, you could do it like this:

```cpp
chassis.DriveR.spin(fwd, 12, volt);
```