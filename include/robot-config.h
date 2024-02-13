using namespace vex;

extern brain Brain;
extern controller Con1;

extern motor FL;
extern motor FR;
extern motor RL;
extern motor RR;

extern motor ML;
extern motor MR;

extern motor launch;

extern motor intake;

extern digital_out lock;

extern motor arm;

extern digital_in button;

extern digital_out wings;
extern digital_out pbrake;

extern inertial isense;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);