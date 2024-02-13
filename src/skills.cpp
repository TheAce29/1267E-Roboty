#include <vex.h>
using namespace vex;
/*
  void autoforward(int speed, float distance, float sleep){
  FL.setVelocity(speed,percent);
  FR.setVelocity(speed,percent);
  RL.setVelocity(speed,percent);
  RR.setVelocity(speed,percent);
  ML.setVelocity(speed,percent);
  MR.setVelocity(speed,percent);

  ML.setBrake(coast);
  MR.setBrake(coast);

  FL.spinFor(distance, rev, false);
  FR.spinFor(distance, rev, false);
  RL.spinFor(distance, rev, false);
  RR.spinFor(distance, rev, false);
  ML.spinFor(distance*0, rev, false);
  MR.spinFor(distance*0, rev, false);

  wait(sleep,sec);
  }
  
  void slide(int speed, float distance){
    //_ is left, _ is right
    FL.setVelocity(speed,percent);
    FR.setVelocity(speed,percent);
    RL.setVelocity(speed,percent);
    RR.setVelocity(speed,percent);

    FL.spinFor(distance, rev, false);
    FR.spinFor(-distance, rev, false);
    RL.spinFor(-distance, rev, false);
    RR.spinFor(distance, rev, true);
  }

  void turn(int speed, float distance, float sleep){
    FL.setVelocity(speed,percent);
    FR.setVelocity(speed,percent);
    RL.setVelocity(speed,percent);
    RR.setVelocity(speed,percent);
    ML.setVelocity(speed,percent);
    MR.setVelocity(speed,percent);

    ML.setBrake(coast);
    MR.setBrake(coast);

    FL.spinFor(distance, rev, false);
    FR.spinFor(-distance, rev, false);
    RL.spinFor(distance, rev, false);
    RR.spinFor(-distance, rev, false);
    ML.spinFor(distance*0, rev, false);
    MR.spinFor(-distance*0, rev, false);

    wait(sleep,sec);
  }
  void marm(float distance,float sleep){
    arm.setVelocity(100,percent);
    arm.spinFor(distance,rev,false);
    wait(sleep,sec);
  }
  void coastbrake(){
    FL.stop(coast);
    FR.stop(coast);
    RL.stop(coast);
    RR.stop(coast);
    ML.stop(coast);
    MR.stop(coast);

  }
  */
  void autolaunch(bool ss){
    if (ss == true){
      launch.spin(reverse,100,percent);
    }
    else {
      launch.stop(coast);
    }
  }


/*
void skillsauton(){
  autolaunch(true);
  chicken(true,0);
  marm(0.1,0.1);
  marm(-0.1,0.1);
  arm.stop(coast);
  autoforward(5,500,0);
  isense.setHeading(45,degrees);
  wait(35,sec);
  mintake(8,0);
  wait(5,sec);
  autolaunch(0);
  autoforward(100,-3,0.8);
  degturn(60,2.5,false,0.3);
  autoforward(100,-10,3);
  degturn(100,90,true,0.5);
  autoforward(100,-8,2.7);
  degturn(100,135,true,0.5);
  autoforward(100,-2.5,0.8);
  degturn(100,180,true,0.5);
  autoforward(100,-2.2,1);
  autoforward(100,0.8,0.5);
  degturn(100,180,true,0.25);
  autoforward(100,-1,0.5);
  autoforward(100,1.2,0.5);
  degturn(100,230,true,0.75);
  autoforward(100,-5,1.5);
  degturn(100,180,false,0.75);
  autoforward(100,-1.5,0.5);
  degturn(100,90,false,0.5);
  chicken(1,0.25);
  autoforward(100,-3,1.5);
  autoforward(100,1,1);
  autoforward(100,-3,1.5);
  autoforward(100,-1.3,1);
  chicken(0,0.25);
  coastbrake();

  coastbrake();
}
*/
void skillsauton(){
  autolaunch(true);
  marm(2,1.1);
  wait(100,msec);
  arm.stop(hold);
  wait(30,msec);
}