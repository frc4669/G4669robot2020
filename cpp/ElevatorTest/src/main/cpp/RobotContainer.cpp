/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "commands/ElevatorDown.h"
#include "commands/ElevatorUp.h"
#include "commands/TurnElevatorServo.h"
#include "Constants.h"


RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
  
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  f310.greenButtonObject.WhenPressed(ElevatorUp{&m_elevator});
  f310.blueButtonObject.WhenPressed(ElevatorDown{&m_elevator});

  f310.redButtonObject.WhenPressed(TurnElevatorServo{&m_elevator, 180});
  f310.orangeButtonObject.WhenPressed(TurnElevatorServo{&m_elevator, 0});
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return nullptr;
}
