#include <vex.h>
using namespace vex;
void blockingauton(){
  marm(0.1,0);
  autoforward(100,-1.5,0.75);
  arm.stop(coast);
  turn(100,0.6,0.5);
  mintake(10,0.6);
  autoforward(100,-1.3,1);
  autoforward(100,0.75,0.5);
  autoforward(100,-0.8,0.5);
  autoforward(100,0.65,0.4);
  /*
  turn(100,0.5,0.75);
  marm(2,0);
  autoforward(100,-2.8,2);
  turn(100,0.75,1);
  autoforward(75,-5,3);
  coastbrake();
  */
}
/*
void leftauton(){
  wait(3,sec);
  autoforward(100,1.4,0.75);
  turn(100,0.5,0.5);
  mintake(-2,0.75);
  autoforward(100,1.3,1.3);
  autoforward(100,-0.75,0.5);
  autoforward(100,0.8,0.5);
  autoforward(100,-1.5,0.4);
  turn(100,-0.5,2);
  wings.set(true);
  autoforward(100,-2,2);
  wait(1.5,sec);
  wings.set(false);
  turn(100,-2.5,1.5);

}
*/