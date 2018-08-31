#include "commands/ArmControl.h"
#include "Robot.h"
#include "Constants.h"

ArmControl::ArmControl() {
  requires(Robot::arm);
  this->priority = DefaultCommandPriority; // Lowest priority
}

bool ArmControl::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void ArmControl::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void ArmControl::execute() {
  // Code that runs when this command is scheduled to run
  printf("Arm default command is running\n");
  armUpButton = joystickGetDigital(1, 6, JOY_UP);
  armDownButton = joystickGetDigital(1, 6, JOY_DOWN);

  if (armUpButton)
    Robot::arm->move(-KMaxMotorSpeed);
  else if (armDownButton)
    Robot::arm->move(KMaxMotorSpeed);
  else
    Robot::arm->move(0);
}

bool ArmControl::isFinished() {
  return false;
}

void ArmControl::end() {
  // Code that runs when isFinished() returns true.
  //Robot::base->move(0, 0);
  Robot::arm->move(0);
}

void ArmControl::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
