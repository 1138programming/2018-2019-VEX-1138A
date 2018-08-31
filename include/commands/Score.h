#ifndef _COMMANDS_SCORE_H_
#define _COMMANDS_SCORE_H_

#include "commands/Command.h"

class Score: public Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    Score();
  private:
    int inc = 0;
};

#endif // _COMMANDS_DRIVEWITHJOY_H_
