#include "vex.h"

//Variables to Calulate Deltas in Encoder Values
float prevL = 0;
float prevR = 0; 
float prevB = 0;

//Variables for Position
float prevOrientationRad = 0;
float prevGlobalX = 0; 
float prevGlobalY = 0; 
float absOrientationRad = 0; 
float absOrientationDeg = 0; 

//Used as a Reference for Global X and Y
float localX = 0;
float localY = 0;

//Deltas in Wheels
float deltaL = 0; 
float deltaR = 0;
float deltaB = 0; 

//Absolute Positions
float absGlobalX = 0; 
float absGlobalY = 0; 

//Encoder Values
float currentL = 0;
float currentR = 0;
float currentB = 0;

float reduceAngle0to360( float angleDeg ) { //Takes an input angle in degrees and converts it to a positive angle value below 360.
  while(!(angleDeg >= 0 && angleDeg < 360)) {
    if( angleDeg < 0 ) { angleDeg += 360; }
    if(angleDeg >= 360) { angleDeg -= 360; }
  }
  return(angleDeg);
}

float reduceAngleMinus180to180( float angleDeg ) { //Takes an input angle in degrees and converts it to an angle between -180 and 180.
  while(!(angleDeg >= -180 && angleDeg < 180)) {
    if( angleDeg < -180 ) { angleDeg += 360; }
    if(angleDeg >= 180) { angleDeg -= 360; }
  }
  return(angleDeg);
}

void setDriveVoltage(float leftVolts, float rightVolts) {
  DriveL.spin(fwd, leftVolts, volt);
  DriveR.spin(fwd, rightVolts, volt);
}

void setDriveVelocity(float leftVelo, float rightVelo) {
  DriveL.spin(fwd, leftVelo, pct);
  DriveR.spin(fwd, rightVelo, pct);
}

void driveHold( void ) {
  DriveL.stop(brakeType::hold);
  DriveR.stop(brakeType::hold);
}

int positionTrack() { //Background thread used to position track full time.
  switch(sensor_setup){  
 case 0:
 WPISkillsAuto();
  break;
 case 1:
  WPISkillsAuto();
  break;
 case 2:
  leftAuto();
  break;
 case 3:
  sixDiscLeftAuto();
  break;
 case 4:
  rightAuto();
  break;
 case 5:
  WPAuto();
  break;
 }
  while(1){
    currentR = (TrackerR.rotation(rotationUnits::deg))*(rWheelRatio); 
    currentB = -(TrackerB.rotation(rotationUnits::deg))*(bWheelRatio);

    deltaR = currentR - prevR;
    deltaB = currentB - prevB;
    
    prevR = currentR;
    prevB = currentB; 

    absOrientationDeg = Gyro.rotation(deg)*360.0/357.0; 

    absOrientationRad = absOrientationDeg/(180/pi);

    float deltaA = absOrientationRad-prevOrientationRad; //Change in angle.

    //Calulates coordinates relative to the chord of the robot's arc.
    if (deltaA == 0) { //Prevents divide by zero error.
        localX = deltaB;
        localY = deltaR;
    } else {
        localX = (2*sin(deltaA/2))*((deltaB/deltaA)+bLength); 
        localY = (2*sin(deltaA/2))*((deltaR/deltaA)-rWidth);
    }

    float localPolarAngle = 0;
    float localPolarLength = 0;

    //Caluclates polar coordinates.
    if (localX == 0 && localY == 0){ //Prevents two zeros from being passed to atan2.
        localPolarAngle = 0;
        localPolarLength = 0;
    } else {
        localPolarAngle = atan2(localY, localX); 
        localPolarLength = sqrt(pow(localX, 2) + pow(localY, 2)); 
    }

    //Converts polar coordinates to global coordinates.
    float globalPolarLength = localPolarLength; 
    float globalPolarAngle = localPolarAngle - prevOrientationRad - (deltaA/2);

    float globalX = globalPolarLength*cos(globalPolarAngle); 
    float globalY = globalPolarLength*sin(globalPolarAngle); 

    //Calulates absolute position and orientation.
    absGlobalX = prevGlobalX + globalX; 
    absGlobalY = prevGlobalY + globalY; 

    prevGlobalX = absGlobalX;
    prevGlobalY = absGlobalY;

    //Sets up the previous orientation for deltas.
    prevOrientationRad = absOrientationRad;
  }
}

void driveReset(float X, float Y, float OrientationDeg) { //Tells the robot its position on the field at the beginning of a match.
  prevB=0;
  prevL=0;
  prevR=0;
  currentB = 0;
  currentL = 0;
  currentR = 0;
  EncoderB.resetRotation();
  EncoderR.resetRotation();
  absGlobalX=X;
  absGlobalY=Y;
  prevGlobalX=X;
  prevGlobalY=Y;
  prevOrientationRad=OrientationDeg*pi/180;
  absOrientationDeg=OrientationDeg;
  Gyro.setRotation(OrientationDeg*357.0/360.0,deg);
}