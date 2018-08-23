#ifndef _COMMANDS_ARMDOWN_H_
#define _COMMANDS_ARMDOWN_H_

#include "commands/Command.h"

class ArmDown: public Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    ArmDown();
  private:
    int inc = 0;
};

#endif // _COMMANDS_DRIVEWITHJOY_H_
