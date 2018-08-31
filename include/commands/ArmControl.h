#ifndef _COMMANDS_ARMCONTROL_H_
#define _COMMANDS_ARMCONTROL_H_

#include "commands/Command.h"

class ArmControl: public Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    ArmControl();
  private:
    bool armUpButton;
    bool armDownButton;
};

#endif // _COMMANDS_DRIVEWITHJOY_H_
