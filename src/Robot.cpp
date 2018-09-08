#include "Robot.h"
#include "events/EventScheduler.h"
#include "events/JoystickButton.h"
#include "events/JoystickChannel.h"

#include "commands/StopBase.h"
#include "commands/StopArm.h"
#include "commands/StopClaw.h"
#include "commands/DriveWithJoy.h"
#include "commands/ArmControl.h"
#include "commands/ClawControl.h"
#include "commands/ArmUpArmDown.h"

Robot* Robot::instance = 0;
Base*  Robot::base = 0;
Arm*   Robot::arm = 0;
Claw*  Robot::claw = 0;

Robot::Robot() {
  printf("Overridden robot constructor!\n");
  // Initialize any subsystems
  base = Base::getInstance();
  arm  = Arm::getInstance();
  claw = Claw::getInstance();

  // Initialize any actions/commands needed
  //JoystickButton* armUpJoystick = new JoystickButton(MainJoystick, Btn5U);
  //armUpJoystick->whileHeld(new ArmUp());
  //JoystickButton* armDownJoystick = new JoystickButton(MainJoystick, Btn5D);
  //armDownJoystick->whileHeld(new ArmDown());
  /*
  JoystickButton* clawOpenJoystick = new JoystickButton(MainJoystick, Btn6U);
  clawOpenJoystick->whileHeld(new ClawOpenCommand());
  JoystickButton* clawCloseJoystick = new JoystickButton(MainJoystick, Btn6D);
  clawCloseJoystick->whileHeld(new ClawCloseCommand());
  */
  JoystickChannel* RightY = new JoystickChannel(MainJoystick, ChRightY);
  JoystickChannel* LeftY = new JoystickChannel(MainJoystick, ChLeftY);
  JoystickButton* ArmUp = new JoystickButton(MainJoystick, Btn6U);
  JoystickButton* ArmDown = new JoystickButton(MainJoystick, Btn6D);
  JoystickButton* ClawOpen = new JoystickButton(MainJoystick, Btn5U);
  JoystickButton* ClawClose = new JoystickButton(MainJoystick, Btn5D);
  //JoystickButton* ArmUpArmDownButton = new JoystickButton(MainJoystick, Btn8U);

  DriveWithJoy* driveCommand = new DriveWithJoy();
  RightY->whilePastThreshold(driveCommand);
  LeftY->whilePastThreshold(driveCommand);

  ArmUp->whileHeld(new ArmControl(true));
  ArmDown->whileHeld(new ArmControl(false));

  ClawOpen->whileHeld(new ClawControl(true));
  ClawClose->whileHeld(new ClawControl(false));

  //ArmUpArmDownButton->whileHeld(new ArmUpArmDown());
}

void Robot::robotInit() {
  printf("Robot created.\n");
}

void Robot::autonInit() {
  //printf("Default autonInit() function\n");
}

void Robot::autonPeriodic() {
  //printf("Default autonPeriodic() function\n");
  EventScheduler::getInstance()->update();
  Motor::periodicUpdate();
}

void Robot::teleopInit() {
  //printf("Default teleopInit() function\n");
}

void Robot::teleopPeriodic() {
  //printf("Default teleopPeriodic() function\n");
    EventScheduler::getInstance()->update();
    Motor::periodicUpdate();
}

void Robot::disabledInit() {
  //printf("Default disabledInit() function\n");
}

void Robot::disabledPeriodic() {
  //printf("Default disabledPeriodic() function");
}

Robot* Robot::getInstance() {
    if (instance == NULL) {
        instance = new Robot();
    }
    return instance;
}
