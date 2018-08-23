// 6 motors

#ifndef ARM_H
#define ARM_H

#include "main.h"

class Arm : public Subsystem {
  private:
    static Arm* instance;

    // Arm motors
    Motor* armMotor;

    Encoder armRightEncoder;

    Arm();
  public:
    void initDefaultCommand();
    void move(int speed);
    static Arm* getInstance();
};

#endif
