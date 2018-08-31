#include "commands/ClawControl.h"
#include "Robot.h"
#include "Constants.h"

ClawControl::ClawControl() {
  requires(Robot::claw);
  this->priority = DefaultCommandPriority; // Lowest priority
}

bool ClawControl::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void ClawControl::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void ClawControl::execute() {
  // Code that runs when this command is scheduled to run
  clawUpButton = joystickGetDigital(1, 5, JOY_UP);
  clawDownButton = joystickGetDigital(1, 5, JOY_DOWN);

  if (clawUpButton)
    Robot::claw->move(-KMaxMotorSpeed);
  else if (clawDownButton)
    Robot::claw->move(KMaxMotorSpeed);
  else
    Robot::claw->move(0);
}

bool ClawControl::isFinished() {
  return false;
}

void ClawControl::end() {
  // Code that runs when isFinished() returns true.
  //Robot::base->move(0, 0);
  Robot::claw->move(0);
}

void ClawControl::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
