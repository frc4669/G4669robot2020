/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/drive/DifferentialDrive.h>

#include "Constants.h"


class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();

  void Periodic();

  void Drive(double speed, double rotation)
  {
    m_drive.ArcadeDrive(speed, rotation);
  }
 private:
  WPI_TalonSRX m_leftMotor{DriveConstants::kLeftMotorPort};
  WPI_TalonSRX m_rightMotor{DriveConstants::kRightMotorPort};

  frc::DifferentialDrive m_drive{m_leftMotor, m_rightMotor}
};
