/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SpinToColor.h"

#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/shuffleboard/Shuffleboard.h>

#include <iostream>


SpinToColor::SpinToColor(SpinnerHook * spinHook, frc::Color color) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({spinHook});
  spinnerHook = spinHook;
  targetColor = color;
}

// Called when the command is initially scheduled.
void SpinToColor::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SpinToColor::Execute() {
  spinnerHook->SpinColor();
}

// Called once the command ends or is interrupted.
void SpinToColor::End(bool interrupted) {
  spinnerHook->Stop();
}

// Returns true when the command should end.
bool SpinToColor::IsFinished() { 
  return spinnerHook->GetMatchedColor() == targetColor;
}
