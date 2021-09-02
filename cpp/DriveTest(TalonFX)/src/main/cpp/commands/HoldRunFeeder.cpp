/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/HoldRunFeeder.h"

HoldRunFeeder::HoldRunFeeder(Feeder * feed) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({feed});
  feeder = feed;
}

// Called when the command is initially scheduled.
void HoldRunFeeder::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void HoldRunFeeder::Execute() {
  feeder->HoldRunHopperFeeder();
  feeder->HoldRunLauncherFeeder();
}

// Called once the command ends or is interrupted.
void HoldRunFeeder::End(bool interrupted) {
  feeder->StopHopperFeeder();
  feeder->StopLauncherFeeder();
}

// Returns true when the command should end.
bool HoldRunFeeder::IsFinished() { return false; }
