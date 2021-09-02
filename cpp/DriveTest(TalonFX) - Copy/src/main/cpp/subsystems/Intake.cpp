/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Intake.h"
#include "Constants.h"
using namespace IntakeConstants;

Intake::Intake() 
  : m_intakeMotor{kIntakeMotorPort},
    m_intakeDeployer{6, 7}
{}

// This method will be called once per scheduler run
void Intake::Periodic() {}

void Intake::RunIntake() {
  m_intakeMotor.Set(ControlMode::PercentOutput, 0.7);
}

void Intake::StopIntake() {
  m_intakeMotor.Set(ControlMode::PercentOutput, 0);
}

void Intake::DeployIntake() {
  m_intakeDeployer.Set(frc::DoubleSolenoid::kForward);
}
void Intake::TuckIntake() {
  m_intakeDeployer.Set(frc::DoubleSolenoid::kReverse);
}
