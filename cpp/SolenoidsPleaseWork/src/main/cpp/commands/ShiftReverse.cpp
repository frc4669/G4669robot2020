/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShiftReverse.h"
#include <iostream>

ShiftReverse::ShiftReverse(Drivetrain * dt) {
  AddRequirements({dt});
  drivetrain = dt;
}

// Called when the command is initially scheduled.
void ShiftReverse::Initialize() {
  drivetrain->ShiftReverse();
  wpi::outs() << "reverse called";
}

// Called repeatedly when this Command is scheduled to run
void ShiftReverse::Execute() {}

// Called once the command ends or is interrupted.
void ShiftReverse::End(bool interrupted) {}

// Returns true when the command should end.
bool ShiftReverse::IsFinished() { return false; }
