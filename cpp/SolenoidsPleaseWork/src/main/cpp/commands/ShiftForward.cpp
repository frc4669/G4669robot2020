/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShiftForward.h"
#include <iostream>

ShiftForward::ShiftForward(Drivetrain * dt) {
  AddRequirements({dt});
  drivetrain = dt;
}

// Called when the command is initially scheduled.
void ShiftForward::Initialize() {
  drivetrain->ShiftForward();
  wpi::outs() << "forward called";
}

// Called repeatedly when this Command is scheduled to run
void ShiftForward::Execute() {}

// Called once the command ends or is interrupted.
void ShiftForward::End(bool interrupted) {}

// Returns true when the command should end.
bool ShiftForward::IsFinished() { return false; }
