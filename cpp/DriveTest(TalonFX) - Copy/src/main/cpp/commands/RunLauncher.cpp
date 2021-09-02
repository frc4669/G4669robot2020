/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/RunLauncher.h"

RunLauncher::RunLauncher(Launcher * launch) {
  // Use addRequirements() here to declare subsystem dependencies.
  launcher = launch;
  AddRequirements({launch});
}

// Called when the command is initially scheduled.
void RunLauncher::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void RunLauncher::Execute() {
  launcher->SetVelocity(4750);
}

// Called once the command ends or is interrupted.
void RunLauncher::End(bool interrupted) {
  launcher->SetVelocity(0);
}

// Returns true when the command should end.
bool RunLauncher::IsFinished() { return false; }
