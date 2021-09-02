/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drivetrain.h"
#include "Constants.h"
using namespace DriveConstants;

Drivetrain::Drivetrain() 
  : m_leftMaster{kLeftMotor1Port},
    m_leftSlave{kLeftMotor2Port},
    m_rightMaster{kRightMotor1Port},
    m_rightSlave{kRightMotor2Port},
    m_shifter{4, 5}
{
  m_drive.SetSafetyEnabled(false);
}

// This method will be called once per scheduler run
void Drivetrain::Periodic() {

}

void Drivetrain::ArcadeDrive(double fwd, double rot) {
  m_drive.ArcadeDrive(fwd, rot);
}

void Drivetrain::ShiftForward() {
  m_shifter.Set(frc::DoubleSolenoid::kForward);
}

void Drivetrain::ShiftReverse() {
  m_shifter.Set(frc::DoubleSolenoid::kReverse);
}