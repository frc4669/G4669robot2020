/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveForward.h"

DriveForward::DriveForward(Drivetrain * drive) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({drive});
  drivetrain = drive;
}

// Called when the command is initially scheduled.
void DriveForward::Initialize() {
  drivetrain->ResetEncoders();
  drivetrain->DriveForward(5);
}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute() {}

// Called once the command ends or is interrupted.
void DriveForward::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveForward::IsFinished() { return false; }
