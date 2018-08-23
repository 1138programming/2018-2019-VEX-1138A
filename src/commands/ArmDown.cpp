#include "commands/ArmDown.h"
#include "Robot.h"
#include "Constants.h"

ArmDown::ArmDown() {
  requires(Robot::base);
}

bool ArmDown::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void ArmDown::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  //leftJoystick = joystickGetAnalog(1, 3); // Left y-channel
  //rightJoystick = joystickGetAnalog(1, 2); // Right y-channel
  inc = 0;
}

void ArmDown::execute() {
  // Code that runs when this command is scheduled to run
  Robot::arm->move(-KMaxMotorSpeed);
  inc++;
}

bool ArmDown::isFinished() {
  return inc > 100; // This is the default value anyways, so this method can be removed
}

void ArmDown::end() {
  // Code that runs when isFinished() returns true.
  //Robot::base->move(0, 0);
  Robot::arm->move(0);
}

void ArmDown::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
