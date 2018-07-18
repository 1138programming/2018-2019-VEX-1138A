#include "commands/DriveWithJoy.h"
#include "Robot.h"

DriveWithJoy::DriveWithJoy() {
  requires(Robot::base);
}

bool DriveWithJoy::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void DriveWithJoy::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  leftJoystick = joystickGetAnalog(1, 3); // Left y-channel
  rightJoystick = joystickGetAnalog(1, 2); // Right y-channel
}

void DriveWithJoy::execute() {
  // Code that runs when this command is scheduled to run
  Robot::base->move(leftJoystick, rightJoystick);
}

bool DriveWithJoy::isFinished() {
  return true; // This is the default value anyways, so this method can be removed
}

void DriveWithJoy::end() {
  // Code that runs when isFinished() returns true.
  //Robot::base->move(0, 0);
}

void DriveWithJoy::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
