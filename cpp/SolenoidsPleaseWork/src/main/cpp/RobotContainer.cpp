/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "commands/ShiftForward.h"
#include "commands/ShiftReverse.h"
#include <iostream>

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();

  // Set up default drive command
  m_drivetrain.SetDefaultCommand(frc2::RunCommand(
      [this] {
        m_drivetrain.ArcadeDrive(-f310.getLeftY() * 0.65, -f310.getRightX() * 0.65);
        },
      {&m_drivetrain}
    )
  );

  m_drivetrain.ResetEncoders();
}

void RobotContainer::ConfigureButtonBindings() {
  wpi::outs() << "buttons called";
  f310.blueButtonObject.WhenPressed(ShiftForward{&m_drivetrain});
  f310.redButtonObject.WhenPressed(ShiftReverse{&m_drivetrain});
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
