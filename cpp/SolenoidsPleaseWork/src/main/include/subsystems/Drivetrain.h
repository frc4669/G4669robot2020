/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/drive/DifferentialDrive.h>
#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include "frc/DoubleSolenoid.h"
#include "frc/SpeedControllerGroup.h"

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  void ArcadeDrive(double fwd, double rot);
  void ShiftForward();
  void ShiftReverse();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  WPI_TalonFX m_leftMaster;
  WPI_TalonFX m_leftSlave;
  WPI_TalonFX m_rightMaster;
  WPI_TalonFX m_rightSlave;

  frc::SpeedControllerGroup m_leftMotors{m_leftMaster, m_leftSlave};
  frc::SpeedControllerGroup m_rightMotors{m_rightMaster, m_rightSlave};

  frc::DoubleSolenoid m_shifter;

  frc::DifferentialDrive m_drive{m_leftMotors, m_rightMotors};
};
