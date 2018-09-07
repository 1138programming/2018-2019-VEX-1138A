#include "main.h"
#include "Constants.h"
#include "commands/StopArm.h"

Arm* Arm::instance = 0;

Arm::Arm() {
  // Get arm motors
  armMotor = Motor::getMotor(armPort);
}

void Arm::initDefaultCommand() {
  setDefaultCommand(new StopArm());
}

/**
 * Move the arm
 * @param left - speed of the left side
 * @param right - speed of the right side
 */
void Arm::move(int speed) {
  speed = threshold((int)speed);

  armMotor->setSpeed(speed);
}

Arm* Arm::getInstance() {
    if (instance == 0) {
      instance = new Arm();
    }

    return instance;
}
