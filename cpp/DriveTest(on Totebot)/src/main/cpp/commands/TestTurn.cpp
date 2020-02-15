/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TestTurn.h"
#include "subsystems/Drivetrain.h"

TestTurn::TestTurn(Drivetrain * drive) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({drive});
  drivetrain = drive;
  
}

// Called when the command is initially scheduled.
void TestTurn::Initialize() {
  
}

// Called repeatedly when this Command is scheduled to run
void TestTurn::Execute() {
  drivetrain->DriveForward(10);
}

// Called once the command ends or is interrupted.
void TestTurn::End(bool interrupted) {
}

// Returns true when the command should end.
bool TestTurn::IsFinished() { return false; }
