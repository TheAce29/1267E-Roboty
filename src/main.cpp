/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
int lor = 0;
int timet;
int vmin;
int vsec;
void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  wait(0.5,sec);
  isense.calibrate();
  wait(2,sec);
  isense.setHeading(5,degrees); //bias
  wait(1,sec);
  int lorc = 4;
  while (1){
    bool bval = button.value();
    if (bval == 0){
      lor = lor + 1;
      if (lor > 3){
        lor = 0;
      }
      wait(500,msec);
    }
    if (lorc != lor){
      lorc = lor;
      Con1.Screen.clearScreen();
      Con1.Screen.setCursor(0,0);
      Brain.Screen.clearScreen();
      Brain.Screen.setCursor(1,1);
      Brain.Screen.setFont(mono30);
      if (lor == 0){
        Con1.Screen.print("NONE");
        Brain.Screen.print("NONE");
      }
      else if (lor == 1){
        Con1.Screen.print("Shooting");
        Brain.Screen.print("Shooting");      
      }
      else if (lor == 2){
        Con1.Screen.print("Blocking");
        Brain.Screen.print("Blocking");      
      }
      else if (lor == 3){
        Con1.Screen.print("Skills");
        Brain.Screen.print("Skills");      
      }
    }
  }


  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  wait(30,msec);
  //lor = 1;
  if (lor == 0){
    lor = 0;
  }
  else if (lor == 1){
    shootingauton();
  }
  else if (lor == 2){
    blockingauton();
  }
  else if (lor == 3){
    skillsauton();
  }
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  timer timey;
  timey.clear();
  Brain.Screen.clearScreen();
  bool toggle = false;
  bool tog = false;
  bool armthing = false;
  int vmin = 1;
  int vsec = 30;
  if (lor == 3){
    int vsec = 0;
  }
  else {
    int vsec = 30;
  }
  wait(20,msec);
  while (1) {
    drawLogo();
    
    //This code is for movement (forward/backward,left/right/shift)
    double ch1=Con1.Axis1.position();
    double ch2=Con1.Axis2.position();
    double ch3=Con1.Axis3.position();
    double ch4=Con1.Axis4.position();
    if (ch4 > 0){
      ch4 = 1.2*(pow(1.043,ch4))-1.2+0.2*ch4;
    }
    else if (ch4 < 0){
      ch4 = 1.2*(pow(1.043,-ch4))-1.2+0.2*-ch4;
    }
    else {
      ch4 = ch4;
    }

      Con1.Screen.setCursor(1,0);
  Con1.Screen.print(ch4);
    FL.spin(forward,ch2+ch4,percent);
    FR.spin(forward,ch2-ch4,percent);
    RL.spin(forward,ch2+ch4,percent);
    RR.spin(forward,ch2-ch4,percent);
    ML.spin(forward,ch2+ch4,percent);
    MR.spin(forward,ch2-ch4,percent);
    //This is for the launcher
     

    if (toggle){
      launch.spin(forward,100,percent);
      if (Con1.ButtonX.pressing()){
      toggle = false;
      wait(250,msec);
      }
    }
    else{
    if (Con1.ButtonX.pressing()){
      toggle = true;
      wait(250,msec);
    }
    }
    if (toggle == false){
      if (Con1.ButtonL1.pressing() and launch.velocity(rpm)<100){
        launch.spin(reverse,100,percent);
      }
      else{
      launch.stop(coast);
      }
    }
    //This is for the arm
    if (Con1.ButtonUp.pressing() == true){
      armthing = true;
      arm.spin(forward,100,percent);
    }
    else if (Con1.ButtonDown.pressing() == true){
      arm.spin(reverse,100,percent);
    }
    else {
      arm.stop(coast);
      if (armthing == true){
        wait(100,msec);
        arm.stop(hold);
        wait(30,msec);
        arm.stop(coast);
        armthing = false;
      }
    }
if (Con1.ButtonR1.pressing()){
  intake.spin(reverse,100,percent);
}
else if (Con1.ButtonR2.pressing()){
  intake.spin(forward,100,percent);
}
else{
  intake.stop(coast);
}
  if (tog){
    wings.set(true);
    if (Con1.ButtonLeft.pressing()){
      tog = false;
      wait(250,msec);
      }
    }
    else{
    if (Con1.ButtonLeft.pressing()){
      tog = true;
      wait(250,msec);
    }
    }
    if (tog == false){
        wings.set(false);
    }
    if (Con1.ButtonY.pressing()){
      lock.set(true);
    }
    else if (Con1.ButtonRight.pressing()){
      lock.set(false);
    }
    if (Con1.ButtonY.pressing()){
      pbrake.set(true);
    }
    else {
      pbrake.set(false);
    }
  // Controller Printing
  if (timey.time() >= 1000){
    timey.clear();
    if (vsec == 0){
      vmin = vmin-1;
      vsec = 59;
    }
    else{
      vsec = vsec-1;
    }

  }
  if (vsec < 0){
    vsec = 0;
  }
  if (vmin < 0){
    vmin = 0;
  }
  //Con1.Screen.setCursor(1,0);
  //Con1.Screen.print("Time: %d:%d",vmin,vsec);
  Con1.Screen.setCursor(2,0);
  Con1.Screen.print("Battery: %d%%",Brain.Battery.capacity());
  Con1.Screen.setCursor(3,0);
  Con1.Screen.print("Launch: %d, %d RPM",toggle, launch.velocity(rpm)*7);
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}

