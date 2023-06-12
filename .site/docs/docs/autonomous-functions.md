---
sidebar_position: 3
sidebar_label: Autonomous Functions
title: Autonomous Functions
---

JAR Template provides a multitude of ways to control the chassis using PID and odometry.

:::note
Each movement function includes a basic and an advanced prototype and example. Most of the time, the basic prototype will be suitable for your need. But JAR Template movement functions are overloaded, which means that you can provide extra information to the function on the fly, depending on the movement you want to make. And although only a "basic" and an "advanced" function are included here, most of the movement functions are overloaded even more, allowing for more flexibility.
:::

:::info
On units in JAR Template: all functions take angles in degrees, distances in inches, times in milliseconds, and voltages in volts, with a maximum voltage of 12.
:::

## turn_to_angle();

import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';

<Tabs
  groupId="zero_tracker"
  defaultValue="proto1"
  values={[
    { label: 'Basic Prototype',  value: 'proto1', },
    { label: 'Basic Example',  value: 'example1', },
    { label: 'Advanced Prototype',  value: 'proto2', },
    { label: 'Advanced Example',  value: 'example2', },
  ]
}>

<TabItem value="example1">

```cpp
void left_side_auto{
    chassis.drive_distance(10);
    chassis.turn_to_angle(-90);
    Intake.spin(reverse, 100, pct);
    task::sleep(1000);
    Intake.stop(coast);
    chassis.turn_to_angle(0);
    chassis.drive_distance(-10);
}
```

</TabItem>


<TabItem value="proto1">

```cpp
void Drive::turn_to_angle(float angle);
```

</TabItem>

<TabItem value="example2">

```cpp
void left_side_auto{
    chassis.drive_distance(10);
    chassis.turn_to_angle(90, 6, 0.5, 500, 4000, 3, 0, 3, 15);
    Intake.spin(reverse, 100, pct);
    task::sleep(1000);
    Intake.stop(coast);
    chassis.turn_to_angle(0);
    chassis.drive_distance(-10);
}
```

</TabItem>


<TabItem value="proto2">

```cpp
void Drive::turn_to_angle(float angle, float turn_max_voltage, float turn_settle_error, float turn_settle_time, float turn_timeout, float turn_kp, float turn_ki, float turn_kd, float turn_starti);
```

</TabItem>
</Tabs>

:::note
In JAR Template, turns are field-centric, meaning that using ```chassis.turn_to_angle(0);``` will always bring the robot to the same orientation in which it began the autonomous function.
:::

