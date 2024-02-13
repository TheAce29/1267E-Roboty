#include <vex.h>
using namespace vex;

void skillsauton(){
  autolaunch(true);
  marm(2,1.1);
  wait(100,msec);
  arm.stop(hold);
  wait(30,msec);
}