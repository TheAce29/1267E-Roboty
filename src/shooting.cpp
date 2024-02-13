#include <vex.h>
using namespace vex;
void shootingauton(){
pidmove(4.75); //forward
pidturn(90); //turn toward triball
chicken(true,0.1); //wings down
pidmove(0.5); // forward a little
turn(100,-0.75,0.35); //*these could be replaced with a turn 180, then turn 90 counterclockwise
chicken(false,0.1); //wings up
pidturn(90); //*
mintake(5,0.2); //unintake triball
autoforward(100,-1,0.5); //push toward goal (use autoforward because it will stop even if it hits the goal)
pidmove(0.8); //backwards
autoforward(100,-0.85,0.5); // second push
pidmove(0.8); //backwards
pidturn(180); // turn for lining up
autoforward(100,3.4,0.75); //get closer to og position
turn(100,-0.5,0.25); //line up with bar
autoforward(100,3,0.5); //move to bar
marm(2,1.1);
wait(100,msec);
arm.stop(hold);
wait(30,msec);
coastbrake();
}
