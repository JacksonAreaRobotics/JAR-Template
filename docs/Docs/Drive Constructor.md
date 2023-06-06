---
title: Drive Constructor
layout: default
nav_order: 1
parent: Docs
---
This is the drive constructor with prototype and example

<Tabs
  groupId="examples1"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="example">

```cpp
void autonomous() {
  chassis.reset_gyro(); 
  chassis.reset_drive_sensor(); 
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD); 

  chassis.set_drive_pid(24, 110, true);
  chassis.wait_drive();
}
```

</TabItem>


<TabItem value="proto">

```cpp
void set_drive_pid(double target, int speed, bool slew_on = false, bool toggle_heading = true);
```

</TabItem>
</Tabs>
