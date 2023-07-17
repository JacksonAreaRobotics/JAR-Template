---
sidebar_position: 2
sidebar_label: Basic Usage
---

# Basic Usage

1. To make a new auton function, you must both write the function in autons.cpp and a declaration of the function in autons.h. The example autons show how this can be done. 
2. In order to select autons from the Brain, you must add each to the pre_auton loop and the autonomous function, both in main.cpp. Again, the example autons show how to do this.
3. The PID gains are tuned to a six motor 360RPM drivetrain. You may wish to tune the PID gains to your robot. The gains are found in autons.cpp in the function default_constants(). Each set of constants is max voltage, then kP, then kI, then kD, then startI. StartI is the maximum error at which the I term begins to wind up. For turning,  this value is best set at 15 degrees.
4. You can use a multitude of functions to control your drivebase. Every function will be prefixed with "chassis." and followed by the function name. If you want to drive to the point (36,36), then call the method "chassis.drive_to_point(36, 36);".