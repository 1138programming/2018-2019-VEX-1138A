#ifndef _COMMANDS_ARMUP_H_
#define _COMMANDS_ARMUP_H_

#include "commands/Command.h"

class ArmUp: public Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    ArmUp();
  private:
    int inc = 0;
};

#endif // _COMMANDS_DRIVEWITHJOY_H_
