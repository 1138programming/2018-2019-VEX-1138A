#include "commands/Score.h"
#include "Robot.h"
#include "Constants.h"

Score::Score() {
  requires(Robot::arm);
  requires(Robot::claw);
  this->priority = 1; // Lowest priority
}

bool Score::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void Score::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  inc = 0;
}

void Score::execute() {
  // Code that runs when this command is scheduled to run
  //printf("Score command executed, inc is %d\n", inc);
  if (inc < 100) {
    Robot::claw->move(KMaxMotorSpeed);
  } else if (inc < 1000) {
    Robot::claw->move(0);
    Robot::arm->move(-KMaxMotorSpeed);
  } else if (inc < 1500) {
    Robot::arm->move(0);
  } else {
    Robot::arm->move(KMaxMotorSpeed);
  }

  inc++;
  delay(10);
}

bool Score::isFinished() {
  return inc >= 2000;
}

void Score::end() {
  // Code that runs when isFinished() returns true.
  //Robot::base->move(0, 0);
  Robot::arm->move(0);
  Robot::claw->move(0);
}

void Score::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::arm->move(0);
  Robot::claw->move(0);
}
