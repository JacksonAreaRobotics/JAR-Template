---
sidebar_position: 2
sidebar_label: Motion Functions
---

# Motion Functions

JAR Template provides a multitude of ways to control the chassis using PID and odometry.

:::note
Each movement function includes a basic and an advanced prototype and example. Most of the time, the basic prototype will be suitable for your need. But JAR Template movement functions are overloaded, which means that you can provide extra information to the function on the fly, depending on the movement you want to make. And although only a "basic" and an "advanced" function are included here, most of the movement functions are overloaded even more, allowing for more flexibility.
:::

:::info
On units in JAR Template: all functions take angles in degrees, distances in inches, times in milliseconds, and voltages in volts, with a maximum voltage of 12.
:::

## Non-Odometry Functions

### turn_to_angle();

import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';

<Tabs
  groupId="turn"
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
    chassis.turn_to_angle(-90, 6, 0.5, 500, 4000, 3, 0, 3, 15);
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
In JAR Template, turns are *field-centric*, meaning that using ```chassis.turn_to_angle(0);``` will always bring the robot to the same orientation in which it began the autonomous function.
:::

### drive_distance();

<Tabs
groupId="drive"
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
void Drive::drive_distance(float distance);
```

</TabItem>

<TabItem value="example2">

```cpp
void left_side_auto{
    chassis.drive_distance(10, 5, 3, 3, 2, 500, 4000, 1, 0, 3, 0, 3, 0, 5, 0);
    chassis.turn_to_angle(-90);
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
void Drive::drive_distance(float distance, float heading, float drive_max_voltage, float heading_max_voltage, float drive_settle_error, float drive_settle_time, float drive_timeout, float drive_kp, float drive_ki, float drive_kd, float drive_starti, float heading_kp, float heading_ki, float heading_kd, float heading_starti);
```

</TabItem>
</Tabs>



### left_swing_to_angle();

<Tabs
groupId="leftswing"
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
    chassis.left_swing_to_angle(90);
    Intake.spin(reverse, 100, pct);
    task::sleep(1000);
    Intake.stop(coast);
    chassis.left_swing_to_angle(0);
    chassis.drive_distance(-10);
}
```

</TabItem>


<TabItem value="proto1">

```cpp
void Drive::left_swing_to_angle(float angle);
```

</TabItem>

<TabItem value="example2">

```cpp
void left_side_auto{
    chassis.drive_distance(10);
    chassis.left_swing_to_angle(90, 8, 2, 0, 1000, 2, 0, 7, 0);
    Intake.spin(reverse, 100, pct);
    task::sleep(1000);
    Intake.stop(coast);
    chassis.left_swing_to_angle(0);
    chassis.drive_distance(-10);
}
```

</TabItem>


<TabItem value="proto2">

```cpp
void Drive::left_swing_to_angle(float angle, float swing_max_voltage, float swing_settle_error, float swing_settle_time, float swing_timeout, float swing_kp, float swing_ki, float swing_kd, float swing_starti);
```

</TabItem>
</Tabs>


### right_swing_to_angle();

<Tabs
groupId="rightswing"
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
    chassis.right_swing_to_angle(90);
    Intake.spin(reverse, 100, pct);
    task::sleep(1000);
    Intake.stop(coast);
    chassis.right_swing_to_angle(0);
    chassis.drive_distance(-10);
    }
```

</TabItem>


<TabItem value="proto1">

```cpp
void Drive::right_swing_to_angle(float angle);
```

</TabItem>

<TabItem value="example2">

```cpp
void left_side_auto{
    chassis.drive_distance(10);
    chassis.right_swing_to_angle(90, 8, 2, 0, 1000, 2, 0, 7, 0);
    Intake.spin(reverse, 100, pct);
    task::sleep(1000);
    Intake.stop(coast);
    chassis.right_swing_to_angle(0);
    chassis.drive_distance(-10);
}
```

</TabItem>


<TabItem value="proto2">

```cpp
void Drive::right_swing_to_angle(float angle, float swing_max_voltage, float swing_settle_error, float swing_settle_time, float swing_timeout, float swing_kp, float swing_ki, float swing_kd, float swing_starti);
```

</TabItem>
</Tabs>

## Odometry Functions

### drive_to_point();

<Tabs
groupId="drivepoint"
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
    chassis.set_coordinates(0, 0, 0);
    chassis.drive_to_point(6, 18);
    chassis.turn_to_angle(-10);
    Intake.spin(reverse, 100, percent);
    task::sleep(1000);
    Intake.stop(coast);
    chassis.drive_to_point(0, 0);
}
```

</TabItem>


<TabItem value="proto1">

```cpp
void Drive::drive_to_point(float X_position, float Y_position);

```

</TabItem>

<TabItem value="example2">

```cpp
void left_side_auto{
    chassis.set_coordinates(0, 0, 0);
    chassis.drive_to_point(6, 18, 5, 3, 4, 400, 5000, 1, 0, 3, 0, 2, 0, 7, 0);
    chassis.turn_to_angle(-10);
    Intake.spin(reverse, 100, percent);
    task::sleep(1000);
    Intake.stop(coast);
    chassis.drive_to_point(0, 0);
}
```

</TabItem>


<TabItem value="proto2">

```cpp
void Drive::drive_to_point(float X_position, float Y_position, float drive_max_voltage, float heading_max_voltage, float drive_settle_error, float drive_settle_time, float drive_timeout, float drive_kp, float drive_ki, float drive_kd, float drive_starti, float heading_kp, float heading_ki, float heading_kd, float heading_starti);
```

</TabItem>
</Tabs>

### turn_to_point();

<Tabs
groupId="turnpoint"
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
    chassis.set_coordinates(0, 0, 0);
    chassis.drive_to_point(6, 18);
    chassis.turn_to_point(20, 30);
    Intake.spin(reverse, 100, percent);
    task::sleep(1000);
    Intake.stop(coast);
    chassis.drive_to_point(0, 0);
}
```

</TabItem>


<TabItem value="proto1">

```cpp
void Drive::turn_to_point(float X_position, float Y_position);

```

</TabItem>

<TabItem value="example2">

```cpp
void left_side_auto{
    chassis.set_coordinates(0, 0, 0);
    chassis.drive_to_point(6, 18);
    chassis.turn_to_point(20, 30, 5, 12, 1, 200, 3000, 1, 0, 3, 0);
    Intake.spin(reverse, 100, percent);
    task::sleep(1000);
    Intake.stop(coast);
    chassis.drive_to_point(0, 0);
}
```

</TabItem>


<TabItem value="proto2">

```cpp
void Drive::turn_to_point(float X_position, float Y_position, float extra_angle_deg, float turn_max_voltage, float turn_settle_error, float turn_settle_time, float turn_timeout, float turn_kp, float turn_ki, float turn_kd, float turn_starti);
```

</TabItem>
</Tabs>

:::note
```float extra_angle_deg``` is used to specify some deviation from the front of the robot and the desired point. Specifically, the controller will make the robot overshoot by that amount of degrees. So an ```extra_angle_deg``` value of 90 will make the robot turn its left side toward the desired point.
:::


### holonomic_drive_to_point();

<Tabs
groupId="holodrive"
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
    chassis.set_coordinates(0, 0, 0);
    chassis.holonomic_drive_to_point(6, 18);
    chassis.turn_to_point(20, 30);
    Intake.spin(reverse, 100, percent);
    task::sleep(1000);
    Intake.stop(coast);
    chassis.holonomic_drive_to_point(0, 0);
}
```

</TabItem>


<TabItem value="proto1">

```cpp
void Drive::holonomic_drive_to_point(float X_position, float Y_position);

```

</TabItem>

<TabItem value="example2">

```cpp
void left_side_auto{
    chassis.set_coordinates(0, 0, 0);
    chassis.holonomic_drive_to_point(6, 18, 20, 6, 6, 2, 200, 3000, 1, 0, 3, 0, 2, 0, 7, 0);
    Intake.spin(reverse, 100, percent);
    task::sleep(1000);
    Intake.stop(coast);
    chassis.holonomic_drive_to_point(0, 0);
}
```

</TabItem>


<TabItem value="proto2">

```cpp
void Drive::holonomic_drive_to_point(float X_position, float Y_position, float angle, float drive_max_voltage, float heading_max_voltage, float drive_settle_error, float drive_settle_time, float drive_timeout, float drive_kp, float drive_ki, float drive_kd, float drive_starti, float heading_kp, float heading_ki, float heading_kd, float heading_starti);
```

</TabItem>
</Tabs>

:::note
When the value of ```angle``` is specified, the controller will attempt to drive the robot to the desired point and turn it to the desired angle simultaneously. When it is left unspecified, the robot will maintain its orientation throughout the movement.
:::