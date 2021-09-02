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
{
  
  m_hopperFeederMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0);
  m_hopperFeederMotor.SelectProfileSlot(0, 0);
  m_hopperFeederMotor.Config_kF(0, 0.4);
  m_hopperFeederMotor.Config_kP(0, 0);
  m_hopperFeederMotor.Config_kI(0, 0);
  m_hopperFeederMotor.Config_kD(0, 0);
  m_hopperFeederMotor.ConfigMotionAcceleration(10);
  m_hopperFeederMotor.SetInverted(true);
  m_hopperFeederMotor.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, 10);
  m_hopperFeederMotor.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, 10);
  m_hopperFeederMotor.ConfigMotionCruiseVelocity(3000); // 2500
  m_hopperFeederMotor.ConfigMotionAcceleration(1500);
  m_hopperFeederMotor.SetSelectedSensorPosition(0);
  //m_hopperFeederMotor.SetSensorPhase(true);

  m_launcherFeederMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0);
  m_launcherFeederMotor.SelectProfileSlot(0, 0);
  m_launcherFeederMotor.Config_kF(0, 0.4);
  m_launcherFeederMotor.Config_kP(0, 0);
  m_launcherFeederMotor.Config_kI(0, 0);
  m_launcherFeederMotor.Config_kD(0, 0);
  m_launcherFeederMotor.ConfigMotionAcceleration(10);
  m_launcherFeederMotor.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, 10);
  m_launcherFeederMotor.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, 10);
  m_launcherFeederMotor.ConfigMotionCruiseVelocity(3000); // 2500
  m_launcherFeederMotor.ConfigMotionAcceleration(1500);
  m_launcherFeederMotor.SetSelectedSensorPosition(0);
  m_launcherFeederMotor.SetInverted(false);
  //m_launcherFeederMotor.SetSensorPhase(true);

}

// This method will be called once per scheduler run
void Feeder::Periodic() {}


void Feeder::RunHopperFeeder() {
  //m_hopperFeederMotor.Set(ControlMode::MotionMagic, (int)(14 * DriveConstants::kTicksPerInches)); // no work
  m_hopperFeederMotor.Set(ControlMode::MotionMagic, 15000); // around 5000 ticks per one ball shift
}

void Feeder::RunLauncherFeeder() {
  //m_launcherFeederMotor.Set(ControlMode::MotionMagic, (int)(14 * DriveConstants::kTicksPerInches));
  m_launcherFeederMotor.Set(ControlMode::MotionMagic, 15000);
}

void Feeder::StopHopperFeeder() {
  m_hopperFeederMotor.Set(ControlMode::PercentOutput, 0);
}

void Feeder::StopLauncherFeeder() {
  m_launcherFeederMotor.Set(ControlMode::PercentOutput, 0);
}

void Feeder::HoldRunHopperFeeder() {
  m_hopperFeederMotor.Set(ControlMode::PercentOutput, 0.6);
}

void Feeder::HoldRunLauncherFeeder() {
  m_launcherFeederMotor.Set(ControlMode::PercentOutput, 0.6);
}

void Feeder::HoldRunHopperFeederRev() {
  m_hopperFeederMotor.Set(ControlMode::PercentOutput, -0.6);
}

void Feeder::HoldRunLauncherFeederRev() {
  m_launcherFeederMotor.Set(ControlMode::PercentOutput, -0.6);
}

void Feeder::ResetEncoders() {
  m_launcherFeederMotor.GetSensorCollection().SetQuadraturePosition(0);
  m_hopperFeederMotor.GetSensorCollection().SetQuadraturePosition(0);
}

double Feeder::GetHopperFeederPosition() {
  return m_hopperFeederMotor.GetSensorCollection().GetQuadraturePosition();
}

double Feeder::GetLauncherFeederPosition() {
  return m_launcherFeederMotor.GetSensorCollection().GetQuadraturePosition();
}

int Feeder::GetHopperFeederError()
{
  return m_hopperFeederMotor.GetClosedLoopError(0);
}

int Feeder::GetLauncherFeederError()
{
  return m_launcherFeederMotor.GetClosedLoopError(0);
}