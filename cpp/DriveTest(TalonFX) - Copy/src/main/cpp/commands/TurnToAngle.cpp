/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TurnToAngle.h"
#include "subsystems/Drivetrain.h"
#include "Constants.h"
#include <iostream>
#include <iomanip>
#include <frc/smartdashboard/SmartDashboard.h>

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
TurnToAngle::TurnToAngle(units::degree_t targetAngle, Drivetrain * drive)
    : CommandHelper(frc2::PIDController(0.02, 0 /*0.0015*/, 0),
                    // Close loop on heading
                    [drive, targetAngle] { wpi::outs()<<"Heading: "<<drive->GetHeading().to<double>()<<"\n";
                      wpi::outs()<<"Target Angle: "<<targetAngle.to<double>()<<"\n";
                      return drive->GetHeading().to<double>(); },
                    // Set reference to target
                    targetAngle.to<double>(),
                    // Pipe output to turn robot
                    [drive](double output) { drive->ArcadeDrive(0, output); 
                                              wpi::outs()<<"Output"<<output<<"\n";},
                    // Require the drive
                    {drive}) {
  //std::cout << "Turntoangle";
  AddRequirements({drive});
  // Set the controller to be continuous (because it is an angle controller)
  m_controller.EnableContinuousInput(-180, 180);
  // Set the controller tolerance - the delta tolerance ensures the robot is
  // stationary at the setpoint before it is considered as having reached the
  // reference
  m_controller.SetTolerance(DriveConstants::kTurnTolerance.to<double>(),
                            DriveConstants::kTurnRateTolerance.to<double>());
  
}

// Returns true when the command should end.
bool TurnToAngle::IsFinished() { 
  double error = abs(m_measurement()-m_setpoint());
  frc::SmartDashboard::PutNumber("TurnError", error);
  wpi::outs()<<"Error: "<<std::to_string(error)<<"\n";
  if (error<tolerance)
  {
    wpi::outs()<<"Done turning\n";
    return true;
  }
  else
  {
    return false;
  }
  //return false;
}
