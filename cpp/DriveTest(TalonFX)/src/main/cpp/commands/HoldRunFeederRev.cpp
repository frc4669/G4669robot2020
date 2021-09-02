/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/HoldRunFeederRev.h"

HoldRunFeederRev::HoldRunFeederRev(Feeder * feed) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({feed});
  feeder = feed;
}

// Called when the command is initially scheduled.
void HoldRunFeederRev::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void HoldRunFeederRev::Execute() {
  feeder->HoldRunHopperFeederRev();
}

// Called once the command ends or is interrupted.
void HoldRunFeederRev::End(bool interrupted) {
  feeder->StopHopperFeeder();
  feeder->StopLauncherFeeder();
}

// Returns true when the command should end.
bool HoldRunFeederRev::IsFinished() { return false; }
