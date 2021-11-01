/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc2/command/button/JoystickButton.h>

#include "commands/DriveDistanceProfiled.h"

//#include "commands/TurnToAngle.h"
#include "commands/ArcadeDrive.h"
#include "commands/TestTurn.h"

RobotContainer::RobotContainer()
{
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();

  // Set up default drive command
  m_drivetrain.SetDefaultCommand(frc2::RunCommand(
      [this] {
        m_drivetrain.ArcadeDrive(
            f310.getLeftY(),
            f310.getLeftX());
      },
      {&m_drivetrain}));
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

  //f310.redButtonObject.WhenPressed(TurnToAngle{90_deg, &m_drivetrain}.WithTimeout(5_s));
  //f310.greenButtonObject.WhenPressed(TestTurn{&m_drivetrain});
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // Runs the chosen command in autonomous
  
  return new frc2::InstantCommand([] {});
}
