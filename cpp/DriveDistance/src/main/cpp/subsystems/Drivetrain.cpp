/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drivetrain.h"
#include "Constants.h"

Drivetrain::Drivetrain()
    : m_leftMaster{DriveConstants::kLeftMotor1Port},
      m_leftSlave{DriveConstants::kLeftMotor2Port},
      m_rightMaster{DriveConstants::kRightMotor1Port},
      m_rightSlave{DriveConstants::kRightMotor2Port}
{
    m_leftSlave.Set(ControlMode::Follower, DriveConstants::kLeftMotor1Port);
    m_rightSlave.Set(ControlMode::Follower, DriveConstants::kRightMotor1Port);

}

// This method will be called once per scheduler run
void Drivetrain::Periodic() {}

void Drivetrain::ArcadeDrive(double fwd, double rot) {
  m_drive.ArcadeDrive(fwd, rot);
}

void Drivetrain::DriveForward(double inches) {
  m_leftMaster.Set(TalonFXControlMode::MotionMagic, inches*DriveConstants::kTicksPerInches);
  m_rightMaster.Set(TalonFXControlMode::MotionMagic, inches*DriveConstants::kTicksPerInches);
}

void Drivetrain::RotateRight(double angle) {
  
}

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

frc::ADIS16470_IMU GetIMU() {
  return m_imu;
}