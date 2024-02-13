#include <vex.h>
using namespace vex;
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
  ML.spinFor(distance, rev, false);
  MR.spinFor(distance, rev, false);

  wait(sleep,sec);
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

    FL.spinFor(-distance, rev, false);
    FR.spinFor(distance, rev, false);
    RL.spinFor(-distance, rev, false);
    RR.spinFor(distance, rev, false);
    ML.spinFor(-distance, rev, false);
    MR.spinFor(distance, rev, false);

    wait(sleep,sec);
  }
  void marm(float distance,float sleep){ //1.02 sec works pretty well
    arm.setVelocity(100,percent);
    arm.spinFor(distance,rev,false);
    wait(sleep,sec);
    arm.stop(coast);
  }
  void coastbrake(){
    FL.stop(coast);
    FR.stop(coast);
    RL.stop(coast);
    RR.stop(coast);
    ML.stop(coast);
    MR.stop(coast);
    arm.stop(coast);
    intake.stop(coast);
  }
  void mintake(float distance,float sleep){ // + out, - in
    intake.setVelocity(100,percent);
    intake.setBrake(coast);
    intake.spinFor(distance,rev,false);
    wait(sleep,sec);
  }
   void chicken(bool value, float sleep){
    wings.set(value);
    wait(sleep,sec);
   }
void degturn(float speed,float angle, bool dir, float sleep){
  //false is left, true is right
  float dec = 2.5;
    FL.setVelocity(speed,percent);
    FR.setVelocity(speed,percent);
    RL.setVelocity(speed,percent);
    RR.setVelocity(speed,percent);
    ML.setVelocity(speed,percent);
    MR.setVelocity(speed,percent);
    if (dir==false){
    while(fabs(isense.angle(degrees)-angle)>35){
      FL.spin(forward);
      FR.spin(reverse);
      RL.spin(forward);
      RR.spin(reverse);
      ML.spin(forward);
      MR.spin(reverse);
    }
    FL.stop(hold);
    FR.stop(hold);
    RL.stop(hold);
    RR.stop(hold);
    ML.stop(hold);
    MR.stop(hold);
    while(fabs(isense.angle(degrees)-angle)>5){
    FL.setVelocity(speed/dec,percent);
    FR.setVelocity(speed/dec,percent);
    RL.setVelocity(speed/dec,percent);
    RR.setVelocity(speed/dec,percent);
    ML.setVelocity(speed/dec,percent);
    MR.setVelocity(speed/dec,percent);
      FL.spin(forward);
      FR.spin(reverse);
      RL.spin(forward);
      RR.spin(reverse);
      ML.spin(forward);
      MR.spin(reverse);

    }
    FL.stop(hold);
    FR.stop(hold);
    RL.stop(hold);
    RR.stop(hold);
    ML.stop(hold);
    MR.stop(hold);
    }
    else if (dir==true){
    while(fabs(isense.angle(degrees)-angle)>45){
      FL.spin(reverse);
      FR.spin(forward);
      RL.spin(reverse);
      RR.spin(forward);
      ML.spin(reverse);
      MR.spin(forward);
    }
    FL.stop(hold);
    FR.stop(hold);
    RL.stop(hold);
    RR.stop(hold);
    ML.stop(hold);
    MR.stop(hold);
    while(fabs(isense.angle(degrees)-angle)>5){
    FL.setVelocity(speed/dec,percent);
    FR.setVelocity(speed/dec,percent);
    RL.setVelocity(speed/dec,percent);
    RR.setVelocity(speed/dec,percent);
    ML.setVelocity(speed/dec,percent);
    MR.setVelocity(speed/dec,percent);
      FL.spin(reverse);
      FR.spin(forward);
      RL.spin(reverse);
      RR.spin(forward);
      ML.spin(reverse);
      MR.spin(forward);

    }
    FL.stop(hold);
    FR.stop(hold);
    RL.stop(hold);
    RR.stop(hold);
    ML.stop(hold);
    MR.stop(hold);      
    }


}
    

    void printstuff(){
      while (1==1){
      Con1.Screen.clearLine(2);
      Con1.Screen.setCursor(2,2);
      Con1.Screen.print(isense.angle(degrees));
      }
    }

    void pidmove(float revolution){
      float error_prior=0;
      float integral_prior=0;
      float kp=100;
      float ki=0;
      float kd=30;
      float bias=0;
      float iteration_time=10;
      FL.resetPosition();
      FR.resetPosition();
      while(1){
      float error = revolution - (FL.position(degrees)/360 + FR.position(degrees)/360)/2;
      float integral = integral_prior+error*iteration_time;
      float derivative = (error-error_prior)/iteration_time;
      float output = kp*error+ki*integral+kd*derivative+bias;
      Con1.Screen.clearLine(0);
      Con1.Screen.setCursor(0,0);
      Con1.Screen.print(output);
      FL.spin(forward,output,percent);
      FR.spin(forward,output,percent);
      RL.spin(forward,output,percent);
      RR.spin(forward,output,percent);
      ML.spin(forward,output,percent);
      MR.spin(forward,output,percent);
      wait(iteration_time,msec);
      float breakvalue = 1;
      if (output > -breakvalue and output < breakvalue){
        FL.stop(coast);
        FR.stop(coast);
        RL.stop(coast);
        RR.stop(coast);
        ML.stop(coast);
        MR.stop(coast);
        break;
      }
      }

    }

    void pidturn(float angle, bool dir){
      if (dir == false){
      float error_prior=0;
      float integral_prior=0;
      float breakvalue = 1;
      float kp=0.3;
      float ki=0;
      float kd=0.2;
      float bias=0;
      float iteration_time=10;
      FL.resetPosition();
      FR.resetPosition();
      while(1){
      float error = angle+5 - isense.heading(degrees);
      float integral = integral_prior+error*iteration_time;
      float derivative = (error-error_prior)/iteration_time;
      float output = kp*error+ki*integral+kd*derivative+bias;
      Con1.Screen.clearLine(0);
      Con1.Screen.setCursor(0,0);
      Con1.Screen.print(output);
      Con1.Screen.clearLine(2);
      Con1.Screen.setCursor(2,2);
      Con1.Screen.print(isense.heading(degrees));
      Con1.Screen.clearLine(3);
      Con1.Screen.setCursor(3,3);
      Con1.Screen.print(error);
      
      FL.spin(forward,output,percent);
      FR.spin(reverse,output,percent);
      RL.spin(forward,output,percent);
      RR.spin(reverse,output,percent);
      ML.spin(forward,output,percent);
      MR.spin(reverse,output,percent);
      wait(iteration_time,msec);
      if (output > -breakvalue and output < breakvalue){
        FL.stop(coast);
        FR.stop(coast);
        RL.stop(coast);
        RR.stop(coast);
        ML.stop(coast);
        MR.stop(coast);
        break;
      }
     /*
      if (isense.heading(degrees) > angle-breakvalue and isense.heading(degrees) < angle+breakvalue){
        FL.stop(coast);
        FR.stop(coast);
        RL.stop(coast);
        RR.stop(coast);
        ML.stop(coast);
        MR.stop(coast);
        break;
      }
      */
      }
      }
      // /*
      else if (dir == true){ //counterclockwise is scuffed. Don't use it.
      float error_prior=0;
      float integral_prior=0;
      float kp=0.35;
      float ki=0;
      float kd=0;
      float bias=0;
      float iteration_time=10; //msec
      while(1){
      float error = (angle+5 - (360-isense.heading(degrees)));
      float integral = (integral_prior+error*iteration_time);
      float derivative = ((error-error_prior)/iteration_time);
      float output = -1*(kp*error+ki*integral+kd*derivative+bias);
      Con1.Screen.clearLine(0);
      Con1.Screen.setCursor(0,0);
      Con1.Screen.print(output);
      Con1.Screen.clearLine(2);
      Con1.Screen.setCursor(2,2);
      Con1.Screen.print(360-isense.heading(degrees));
      
      FL.spin(forward,output,percent);
      FR.spin(reverse,output,percent);
      RL.spin(forward,output,percent);
      RR.spin(reverse,output,percent);
      ML.spin(forward,output,percent);
      MR.spin(reverse,output,percent);
      wait(iteration_time,msec);
      float breakvalue = 1;
      if (isense.heading(degrees) > angle-breakvalue and isense.heading(degrees) < angle+breakvalue){
        FL.stop(coast);
        FR.stop(coast);
        RL.stop(coast);
        RR.stop(coast);
        ML.stop(coast);
        MR.stop(coast);
        break;
      }
      }
      }  
      // */  
    }
  void autolaunch(bool ss){
    if (ss == true){
      launch.spin(reverse,100,percent);
    }
    else {
      launch.stop(coast);
    }
  }