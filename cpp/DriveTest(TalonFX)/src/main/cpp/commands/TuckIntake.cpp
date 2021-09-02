/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TuckIntake.h"

TuckIntake::TuckIntake(Intake * in) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({in});
  intake = in;
}

// Called when the command is initially scheduled.
void TuckIntake::Initialize() {
  intake->TuckIntake();
}

// Called repeatedly when this Command is scheduled to run
void TuckIntake::Execute() {}

// Called once the command ends or is interrupted.
void TuckIntake::End(bool interrupted) {}

// Returns true when the command should end.
bool TuckIntake::IsFinished() { return false; }
