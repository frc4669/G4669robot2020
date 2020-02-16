/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SpinRotations.h"
#include "Constants.h"
using namespace SpinnerHookConstants;


SpinRotations::SpinRotations(SpinnerHook * spinHook, int rotations) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({spinHook});
  spinnerHook = spinHook;
  targetRotations = rotations;
}

// Called when the command is initially scheduled.
void SpinRotations::Initialize() {
  //spinnerHook->ResetSpinnerPosition();
  initialSpinnerTicks = spinnerHook->GetSpinnerPosition();
  spinnerHook->Init();
  spinnerHook->Spin();
}

// Called repeatedly when this Command is scheduled to run
void SpinRotations::Execute() {
  std::cout << "Error: " << spinnerHook->GetError() << "\n";
}

// Called once the command ends or is interrupted.
void SpinRotations::End(bool interrupted) {
  //spinnerHook->Stop();
}

// Returns true when the command should end.
bool SpinRotations::IsFinished() { 
  if (spinnerHook->GetError() < 250) // Spinner stops before error is 0
  {
    return true;
    std::cout << "WE HAVE SPUN THE COLOR WHEEL ENOUGH TIMES!!\n";
  }
  std::cout << "NOT DONE\n";
  return false;
}
