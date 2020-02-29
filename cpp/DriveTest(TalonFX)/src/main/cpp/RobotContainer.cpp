/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc2/command/button/JoystickButton.h>

#include "commands/TurnToAngle.h"
#include "commands/DriveForward.h"
#include "commands/ShiftForward.h"
#include "commands/ShiftReverse.h"
#include "commands/RunLauncher.h"
#include "Constants.h"

#include <iostream>

RobotContainer::RobotContainer()
{
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();

  // Set up default drive command
  m_drivetrain.SetDefaultCommand(frc2::RunCommand(
      [this] {
        m_drivetrain.ArcadeDrive(-f310.getLeftY() * 0.85, -f310.getRightX() * 0.85);
        // std::cout << "Left: " << m_drivetrain.GetLeftEncoderDistance() << "\n";
        // std::cout << "Right: " << m_drivetrain.GetRightEncoderDistance() << "\n\n";
      },
      {&m_drivetrain}));

  m_drivetrain.ResetEncoders();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here

  // // While holding the shoulder button, drive at half speed
  // frc2::JoystickButton(&m_driverController, 6)
  //     .WhenPressed(&m_driveHalfSpeed)
  //     .WhenReleased(&m_driveFullSpeed);

  // // Drive forward by 3 meters when the 'A' button is pressed, with a timeout of
  // // 10 seconds
  // frc2::JoystickButton(&m_driverController, 1)
  //     .WhenPressed(DriveDistanceProfiled(3_m, &m_drivetrain).WithTimeout(10_s));

//   // Do the same thing as above when the 'B' button is pressed, but defined
//   // inline
//   frc2::JoystickButton(&m_driverController, 2)
//       .WhenPressed(
//           frc2::TrapezoidProfileCommand<units::meters>(
//               frc::TrapezoidProfile<units::meters>(
//                   // Limit the max acceleration and velocity
//                   {DriveConstants::kMaxSpeed, DriveConstants::kMaxAcceleration},
//                   // End at desired position in meters; implicitly starts at 0
//                   {3_m, 0_mps}),
//               // Pipe the profile state to the drive
//               [this](auto setpointState) {
//                 m_drivetrain.SetDriveStates(setpointState, setpointState);
//               },
//               // Require the drive
//               {&m_drivetrain})
//               .BeforeStarting([this]() { m_drivetrain.ResetEncoders(); })
//               .WithTimeout(10_s));

  f310.redButtonObject.WhenPressed(DriveForward{&m_drivetrain});
  f310.orangeButtonObject.WhenPressed(TurnToAngle{90_deg, &m_drivetrain});
  f310.greenButtonObject.WhenPressed(ShiftForward{&m_drivetrain});
  f310.blueButtonObject.WhenPressed(ShiftReverse{&m_drivetrain});

  f310.rightShoulderButtonObject.WhenHeld(RunLauncher{&m_launcher});
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // Runs the chosen command in autonomous
  
  return new frc2::InstantCommand([] {});
}
