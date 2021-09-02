/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Elevator.h"
#include "Constants.h"

Elevator::Elevator()
  : m_elevatorMotor(ElevatorConstants::kElevatorMotorPort),
    m_elevatorMotor2(ElevatorConstants::kElevatorMotor2Port)
{

  m_elevatorMotor2.Set(ControlMode::Follower, ElevatorConstants::kElevatorMotorPort);

  m_elevatorMotor.GetSensorCollection().SetQuadraturePosition(0);

  m_elevatorMotor.SelectProfileSlot(0, 0);
  m_elevatorMotor.Config_kF(0, 0.6);
  m_elevatorMotor.Config_kP(0, 0);
  m_elevatorMotor.Config_kI(0, 0);
  m_elevatorMotor.Config_kD(0, 0);

  m_elevatorMotor.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, 10);
  m_elevatorMotor.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, 10);

  m_elevatorMotor.ConfigNominalOutputForward(0);
  m_elevatorMotor.ConfigNominalOutputReverse(0);
  m_elevatorMotor.ConfigPeakOutputForward(1);
  m_elevatorMotor.ConfigPeakOutputReverse(-1);

  m_elevatorMotor.ConfigMotionCruiseVelocity(1500); // 2500
  m_elevatorMotor.ConfigMotionAcceleration(1500);

  m_elevatorMotor.SetSelectedSensorPosition(0);
  m_elevatorMotor.SetSensorPhase(true);
  m_elevatorMotor.ConfigMotionSCurveStrength(0);

}

//Called once scheduler run
void Elevator::Periodic() {}

bool Elevator::GetFwdLimitSwitch()
{
  return m_elevatorMotor.GetSensorCollection().IsFwdLimitSwitchClosed() == 1;
} 

bool Elevator::GetRevLimitSwitch()
{
  return m_elevatorMotor.GetSensorCollection().IsRevLimitSwitchClosed() == 1;
} 

void Elevator::GoUp()
{
  m_elevatorMotor.Set(ControlMode::PercentOutput, 0.8);
  //m_elevatorMotor2.Set(ControlMode::MotionMagic, 2000);
}

void Elevator::GoDown()
{
  m_elevatorMotor.Set(ControlMode::PercentOutput, -0.8);
  //m_elevatorMotor2.Set(ControlMode::MotionMagic, -2000);
}

void Elevator::Stop()
{
  m_elevatorMotor.Set(ControlMode::PercentOutput, 0);
  //m_elevatorMotor2.Set(ControlMode::PercentOutput, 0);
}

void Elevator::ResetEncoders()
{
  m_elevatorMotor.GetSensorCollection().SetQuadraturePosition(0);
}

int Elevator::GetElevatorPosition()
{
  return m_elevatorMotor.GetSensorCollection().GetQuadraturePosition();
}

void Elevator::SetServoAngle(double angle)
{
  m_servo.SetAngle(angle);
}