/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShiftReverse.h"

ShiftReverse::ShiftReverse(Drivetrain* drive) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({drive});
  drivetrain = drive;
}

// Called when the command is initially scheduled.
void ShiftReverse::Initialize() {
  drivetrain->ShiftReverse();
}

// Called repeatedly when this Command is scheduled to run
void ShiftReverse::Execute() {}

// Called once the command ends or is interrupted.
void ShiftReverse::End(bool interrupted) {}

// Returns true when the command should end.
bool ShiftReverse::IsFinished() { return false; }
