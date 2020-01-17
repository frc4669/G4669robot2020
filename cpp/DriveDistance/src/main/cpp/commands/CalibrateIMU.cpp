/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/CalibrateIMU.h"

CalibrateIMU::CalibrateIMU(Drivetrain* drive) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({drive});
  drivetrain = drive;
}

// Called when the command is initially scheduled.
void CalibrateIMU::Initialize() {
  drivetrain->GetIMU().Calibrate();
}

// Called repeatedly when this Command is scheduled to run
void CalibrateIMU::Execute() {}

// Called once the command ends or is interrupted.
void CalibrateIMU::End(bool interrupted) {}

// Returns true when the command should end.
bool CalibrateIMU::IsFinished() { return false; }
