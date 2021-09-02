/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ElevatorDown.h"

ElevatorDown::ElevatorDown(Elevator * elev) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({elev});
  elevator = elev;
}

// Called when the command is initially scheduled.
void ElevatorDown::Initialize() {
  elevator->ResetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void ElevatorDown::Execute() {
  elevator->GoDown();
}

// Called once the command ends or is interrupted.
void ElevatorDown::End(bool interrupted) {
  elevator->Stop();
  elevator->ResetEncoders();
}

// Returns true when the command should end.
bool ElevatorDown::IsFinished() { 
  return abs(elevator->GetElevatorPosition()) >= 10000 || abs(elevator->GetElevatorPosition()) >= 10000;
  //return false; 
}
