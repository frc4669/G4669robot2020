/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ArcadeDrive.h"

ArcadeDrive::ArcadeDrive(double moveSp, double rotateSp, Drivetrain* drive) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({drive});

  moveSpeed = moveSp;
  rotateSpeed = rotateSp;
  drivetrain = drive;
}

// Called when the command is initially scheduled.
void ArcadeDrive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ArcadeDrive::Execute() {
  drivetrain->ArcadeDrive(moveSpeed, rotateSpeed);
}

// Called once the command ends or is interrupted.
void ArcadeDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool ArcadeDrive::IsFinished() { return false; }
