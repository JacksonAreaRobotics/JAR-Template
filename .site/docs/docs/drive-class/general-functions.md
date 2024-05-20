---
sidebar_position: 3
sidebar_label: General Functions
---

# General Functions

JAR Template provides a quick setup for arcade and tank control for tank drive robots, and holonomic control for holonomic robots. This setup is a quick way to check that each drive port is reversed properly and that the robot drives well.

## control_arcade();

import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';

<Tabs
  groupId="arcade"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="example">

```cpp
void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
    if(Controller1.ButtonL1.pressing()){
      Lift.spin(fwd, 100, percent);
    }else if(Controller1.ButtonL2.pressing()){
      Lift.spin(reverse, 100, percent);
    }else{
      Lift.stop(hold);
    }

    //Replace this line with chassis.control_tank(); for tank drive 
    //or chassis.control_holonomic(); for holo drive.
    chassis.control_arcade();

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}
```

</TabItem>


<TabItem value="proto">

```cpp
void Drive::control_arcade();
```

</TabItem>
</Tabs>

In JAR Template arcade, the left joystick controls forward/backward movement, and the right joystick controls turning. 


## control_tank();


<Tabs
  groupId="tank"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="example">

```cpp
void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
    if(Controller1.ButtonL1.pressing()){
      Lift.spin(fwd, 100, percent);
    }else if(Controller1.ButtonL2.pressing()){
      Lift.spin(reverse, 100, percent);
    }else{
      Lift.stop(hold);
    }

    //Replace this line with chassis.control_tank(); for tank drive 
    //or chassis.control_holonomic(); for holo drive.
    chassis.control_tank();

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}
```

</TabItem>


<TabItem value="proto">

```cpp
void Drive::control_tank();
```

</TabItem>
</Tabs>

## control_holonomic();

Holonomic control just means that the drivetrain can move in all directions, like a mecanum or X-Drive.


<Tabs
  groupId="holo"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="example">

```cpp
void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
    if(Controller1.ButtonL1.pressing()){
      Lift.spin(fwd, 100, percent);
    }else if(Controller1.ButtonL2.pressing()){
      Lift.spin(reverse, 100, percent);
    }else{
      Lift.stop(hold);
    }

    //Replace this line with chassis.control_tank(); for tank drive 
    //or chassis.control_holonomic(); for holo drive.
    chassis.control_holonomic();

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}
```

</TabItem>


<TabItem value="proto">

```cpp
void Drive::control_holonomic();
```

</TabItem>
</Tabs>