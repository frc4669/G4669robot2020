/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/RunIntake.h"

RunIntake::RunIntake(Intake * in) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({in});
  intake = in;
}

// Called when the command is initially scheduled.
void RunIntake::Initialize() {
  intake->RunIntake();
}

// Called repeatedly when this Command is scheduled to run
void RunIntake::Execute() {
  intake->RunIntake();
}

// Called once the command ends or is interrupted.
void RunIntake::End(bool interrupted) {
  intake->StopIntake();
}

// Returns true when the command should end.
bool RunIntake::IsFinished() { return false; }
