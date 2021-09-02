/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/RunFeeder.h"
#include "Constants.h"
#include <iostream>

RunFeeder::RunFeeder(Feeder * feed) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({feed});
  feeder = feed;
}

// Called when the command is initially scheduled.
void RunFeeder::Initialize() {
  feeder->ResetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void RunFeeder::Execute() {
  feeder->RunLauncherFeeder();
  feeder->RunHopperFeeder();

}

// Called once the command ends or is interrupted.
void RunFeeder::End(bool interrupted) {
  feeder->StopHopperFeeder();
  feeder->StopLauncherFeeder();
}

// Returns true when the command should end.
bool RunFeeder::IsFinished() 
{ 
  //return false;
  return abs(feeder->GetHopperFeederPosition()) >= 5000 || abs(feeder->GetLauncherFeederPosition()) >= 5000;
}
