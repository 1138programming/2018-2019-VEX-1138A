#include "Robot.h"
#include "events/EventScheduler.h"
#include "events/JoystickButton.h"

#include "commands/DriveWithJoy.h"
#include "commands/ArmUp.h"
#include "commands/ArmDown.h"
//#include "commands/ClawOpen.h"
//#include "commands/ClawClose.h"

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
  JoystickButton* armUpJoystick = new JoystickButton(MainJoystick, Btn5U);
  armUpJoystick->whileHeld(new ArmUp());
  JoystickButton* armDownJoystick = new JoystickButton(MainJoystick, Btn5D);
  armDownJoystick->whileHeld(new ArmDown());
  /*
  JoystickButton* clawOpenJoystick = new JoystickButton(MainJoystick, Btn6U);
  clawOpenJoystick->whileHeld(new ClawOpenCommand());
  JoystickButton* clawCloseJoystick = new JoystickButton(MainJoystick, Btn6D);
  clawCloseJoystick->whileHeld(new ClawCloseCommand());
  */
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
