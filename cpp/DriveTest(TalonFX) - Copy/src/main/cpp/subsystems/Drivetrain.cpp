/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drivetrain.h"
#include "Constants.h"
using namespace DriveConstants;

#include <frc/smartdashboard/SmartDashboard.h>
#include <utility>
#include <iostream>

Drivetrain::Drivetrain()
  : m_leftMaster{kLeftMotor1Port},
    m_leftSlave{kLeftMotor2Port},
    m_rightMaster{kRightMotor1Port},
    m_rightSlave{kRightMotor2Port},
    m_shifter{4, 5}
{
  m_drive.SetSafetyEnabled(false);
  ConfigMotor(m_leftMaster);
  ConfigMotor(m_leftSlave);
  ConfigMotor(m_rightMaster);
  ConfigMotor(m_rightSlave);
  m_leftMaster.GetSensorCollection().SetIntegratedSensorPosition(0);
  m_rightMaster.GetSensorCollection().SetIntegratedSensorPosition(0);

  m_yawChooser.SetDefaultOption("Z-Axis", "Z-Axis");
  m_yawChooser.AddOption("X-Axis", "X-Axis");
  m_yawChooser.AddOption("Y-Axis", "Y-Axis");
  frc::SmartDashboard::PutData("IMUYawAxis", &m_yawChooser);
  frc::SmartDashboard::PutBoolean("RunCal", false);
  frc::SmartDashboard::PutBoolean("ConfigCal", false);
  frc::SmartDashboard::PutBoolean("Reset", false);
  frc::SmartDashboard::PutBoolean("SetYawAxis", false);
}

// This method will be called once per scheduler run
void Drivetrain::Periodic() {
  frc::SmartDashboard::PutNumber("YawAngle", m_imu.GetAngle());
  frc::SmartDashboard::PutNumber("TurnError", 90-m_imu.GetAngle());
  frc::SmartDashboard::PutNumber("XCompAngle", m_imu.GetXComplementaryAngle());
  frc::SmartDashboard::PutNumber("YCompAngle", m_imu.GetYComplementaryAngle());
  m_runCal = frc::SmartDashboard::GetBoolean("RunCal", false);
  m_configCal = frc::SmartDashboard::GetBoolean("ConfigCal", false);
  m_reset = frc::SmartDashboard::GetBoolean("Reset", false);
  m_setYawAxis = frc::SmartDashboard::GetBoolean("SetYawAxis", false);
  m_yawSelected = m_yawChooser.GetSelected();

  // Set IMU settings
  if (m_configCal) {
    m_imu.ConfigCalTime(frc::ADIS16470CalibrationTime::_8s);
    m_configCal = frc::SmartDashboard::PutBoolean("ConfigCal", false);
  }
  if (m_reset) {
    m_imu.Reset();
    m_reset = frc::SmartDashboard::PutBoolean("Reset", false);
  }
  if (m_runCal) {
    m_imu.Calibrate();
    m_runCal = frc::SmartDashboard::PutBoolean("RunCal", false);
  }
  
  // Read the desired yaw axis from the dashboard
  if (m_yawSelected == "X-Axis") {
    m_yawActiveAxis = frc::ADIS16470_IMU::IMUAxis::kX;
  }
  else if (m_yawSelected == "Y-Axis") {
    m_yawActiveAxis = frc::ADIS16470_IMU::IMUAxis::kY;
  }
  else {
    m_yawActiveAxis = frc::ADIS16470_IMU::IMUAxis::kZ;
  }
  // Set the desired yaw axis from the dashboard
  if (m_setYawAxis) {
    m_imu.SetYawAxis(m_yawActiveAxis);
    m_setYawAxis = frc::SmartDashboard::PutBoolean("SetYawAxis", false);
  }
}

void Drivetrain::ArcadeDrive(double fwd, double rot) {
  m_drive.ArcadeDrive(fwd, rot);
}

void Drivetrain::DriveForward(double inches) {
  m_leftMaster.Set(ControlMode::MotionMagic, 40000); //inches * DriveConstants::kTicksPerInches);
  m_rightMaster.Set(ControlMode::MotionMagic, -40000); //inches * DriveConstants::kTicksPerInches);

  // m_leftMaster.Set(ControlMode::PercentOutput, 0.4); 
  // m_rightMaster.Set(ControlMode::PercentOutput, 0.4);

  m_rightSlave.Set(ControlMode::Follower, DriveConstants::kRightMotor1Port);
  m_leftSlave.Set(ControlMode::Follower, DriveConstants::kLeftMotor1Port);

  //m_rightSlave.Set(ControlMode::PercentOutput, 0.2);
  //wpi::outs() << m_rightMaster.GetMotorSafety();
  //wpi::outs() << "Expiration is: " << m_rightMaster.GetExpiration() << "\n";
  //wpi::outs() << "Time is: " << Timer::GetFPGATimestamp() <<"\n";
  //Timer::GetFPGATimestamp()
  //m_rightMaster.SetExpiration(100.0);
  //m_rightMaster.SetSafetyEnabled(false);
  //m_rightMaster.Set(ControlMode::PercentOutput, 0.2);
  //m_rightSlave.Set(ControlMode::PercentOutput, 0.2);

  // m_rightMaster.Set(ControlMode::Velocity, 9000);
  // m_leftMaster.Set(ControlMode::Velocity, 9000);
}

void Drivetrain::RotateRight(double angle) {}

void Drivetrain::ResetEncoders() {
  m_leftMaster.GetSensorCollection().SetIntegratedSensorPosition(0);
  m_rightMaster.GetSensorCollection().SetIntegratedSensorPosition(0);
}

double Drivetrain::GetLeftEncoderDistance() {
  return m_leftMaster.GetSensorCollection().GetIntegratedSensorPosition();
}

double Drivetrain::GetRightEncoderDistance() {
  return m_rightMaster.GetSensorCollection().GetIntegratedSensorPosition();
}

void Drivetrain::SetMaxOutput(double maxOutput) {
  m_drive.SetMaxOutput(maxOutput);
}

units::degree_t Drivetrain::GetHeading() {
  return units::degree_t(std::remainder(m_imu.GetAngle(), 360)) * (DriveConstants::kGyroReversed ? -1.0 : 1.0);
}

frc::ADIS16470_IMU& Drivetrain::GetIMU()
{
  return m_imu;
}

void Drivetrain::ShiftForward()
{
  m_shifter.Set(frc::DoubleSolenoid::kForward);
}

void Drivetrain::ShiftReverse()
{
  m_shifter.Set(frc::DoubleSolenoid::kReverse);
}

void Drivetrain::ConfigMotor(WPI_TalonFX &motor)
{
  motor.Config_kF(0, 1);
  motor.Config_kP(0, 0);
  motor.Config_kI(0, 0);
  motor.Config_kD(0, 0);
  motor.ConfigMotionCruiseVelocity(20000);
  motor.ConfigSupplyCurrentLimit(SupplyCurrentLimitConfiguration(true, 25, 25, 0.5));
  motor.ConfigStatorCurrentLimit(StatorCurrentLimitConfiguration(true, 25, 25, 0.5));
  motor.ConfigOpenloopRamp(0.8);
  motor.ConfigClosedloopRamp(0);
  motor.ConfigMotionAcceleration(8000);
  motor.SetNeutralMode(NeutralMode::Brake);
  motor.SetSafetyEnabled(false);
  motor.SetExpiration(0.1);
}

  // motor.Config_kF(0, 0.048);
  // motor.Config_kP(0, 0.009);
  // motor.Config_kI(0, 0);
  // motor.Config_kD(0, 0.02);