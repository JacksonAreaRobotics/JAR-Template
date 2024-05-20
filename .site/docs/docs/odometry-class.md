---
sidebar_position: 3
sidebar_label: Odometry Class
title: Odometry Class
---

General-use odometry class with X_position, Y_position, and orientation_deg being the relevant outputs. This works for one-tracker and two-tracker systems, and requires a gyro to get input angle.

### set_physical_distances

Setter method for tracker center distances. 
The forward tracker center distance is the horizontal distance from the center of the robot to the center of the wheel the sensor is measuring. The sideways tracker center distance is the vertical distance from the center of the robot to the center of the sideways wheel being measured. If there's really no sideways wheel we set the center distance to 0 and pretend the wheel never spins, which is equivalent to a no-drift robot.

|Parameters |
|-------------|--------|
|ForwardTracker_center_distance |A horizontal distance to the wheel center in inches.|
|SidewaysTracker_center_distance |A vertical distance to the wheel center in inches.|


import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';

<Tabs
  groupId="setphysicaldistances"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="example">

```cpp
odom.set_physical_distances(-2.5, 5.5);
```

</TabItem>


<TabItem value="proto">

```cpp
void Odom::set_physical_distances(float ForwardTracker_center_distance, float SidewaysTracker_center_distance);
```

</TabItem>
</Tabs>



### set_position

Resets the position, including tracking wheels. 
Position is field-centric, and orientation is such that 0 degrees is in the positive Y direction. Orientation can be provided with some flexibility, including less than 0 and greater than 360. Tracking wheels must be reset to prevent a jump when the odometry function starts incrementing.

|Parameters |
|-------------|--------|
|X_position | Field-centric x position of the robot.|
|Y_position | Field-centric y position of the robot.|
|orientation_deg | Field-centered, clockwise-positive, orientation.|
|ForwardTracker_position | Current position of the sensor in inches.|
|SidewaysTracker_position | Current position of the sensor in inches.|


<Tabs
  groupId="setposition"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="example">

```cpp
odom.set_position(0, 0, 0, 5.5, 4);
```

</TabItem>


<TabItem value="proto">

```cpp
void Odom::set_position(float X_position, float Y_position, float orientation_deg, float ForwardTracker_position, float SidewaysTracker_position);
```

</TabItem>
</Tabs>

### update_position

Does the odometry math to update position.
Uses the Pilons arc method outline here: https://wiki.purduesigbots.com/software/odometry. All the deltas are done by getting member variables and comparing them to the input. Ultimately this all works to update the public member variable X_position. This function needs to be run at 200Hz or so for best results.

|Parameters |
|-------------|--------|
|ForwardTracker_position |Current position of the sensor in inches.|
|SidewaysTracker_position |Current position of the sensor in inches.|
|orientation_deg |Field-centered, clockwise-positive, orientation.|


<Tabs
  groupId="updateposition"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="example">

```cpp
odom.update_position(5.6, 4.1, 1.1);
```

</TabItem>


<TabItem value="proto">

```cpp
void Odom::update_position(float ForwardTracker_position, float SidewaysTracker_position, float orientation_deg);
```

</TabItem>
</Tabs>