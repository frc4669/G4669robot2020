/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Feeder.h"
#include "Constants.h"
using namespace FeederConstants;

Feeder::Feeder() 
  : m_hopperFeederMotor{kHopperFeederPort},
    m_launcherFeederMotor{kLauncherFeederPort}
{}

// This method will be called once per scheduler run
void Feeder::Periodic() {}


void Feeder::RunHopperFeeder() {
  m_hopperFeederMotor.Set(ControlMode::PercentOutput, 0.4);
}

void Feeder::RunLauncherFeeder() {
  m_launcherFeederMotor.Set(ControlMode::PercentOutput, 0.4);
}

void Feeder::StopHopperFeeder() {
  m_hopperFeederMotor.Set(ControlMode::PercentOutput, 0);
}

void Feeder::StopLauncherFeeder() {
  m_launcherFeederMotor.Set(ControlMode::PercentOutput, 0);
}
