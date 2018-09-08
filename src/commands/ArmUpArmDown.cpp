#include "commands/ArmUpArmDown.h"
#include "commands/MoveArmFor.h"
#include "Robot.h"
#include "Constants.h"

ArmUpArmDown::ArmUpArmDown() {
  addSequentialCommand(new MoveArmFor(1000, 127));
  addSequentialCommand(new MoveArmFor(1000, -127));
}
