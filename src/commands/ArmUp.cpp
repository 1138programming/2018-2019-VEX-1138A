#include "commands/ArmUp.h"
#include "Robot.h"
#include "Constants.h"

ArmUp::ArmUp() {
  requires(Robot::base);
}

bool ArmUp::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void ArmUp::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  //leftJoystick = joystickGetAnalog(1, 3); // Left y-channel
  //rightJoystick = joystickGetAnalog(1, 2); // Right y-channel
  inc = 0;
}

void ArmUp::execute() {
  // Code that runs when this command is scheduled to run
  Robot::arm->move(KMaxMotorSpeed);
  inc++;
}

bool ArmUp::isFinished() {
  return inc > 100; // This is the default value anyways, so this method can be removed
}

void ArmUp::end() {
  // Code that runs when isFinished() returns true.
  //Robot::base->move(0, 0);
  Robot::arm->move(0);
}

void ArmUp::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
