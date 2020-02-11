/*----------------------------------------------------------------------------*/

/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */

/* Open Source Software - may be modified and shared by FRC teams. The code   */

/* must be accompanied by the FIRST BSD license file in the root directory of */

/* the project.                                                               */

/*----------------------------------------------------------------------------*/

#include "subsystems/Launcher.h"

using namespace DriveConstants;

Launcher::Launcher()
{
    rev::CANSparkMax m_launcher{LauncherConstants::kLauncherMotorPort, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANPIDController m_pidController = m_launcher.GetPIDController();
    rev::CANEncoder m_encoder = m_launcher.GetEncoder();
}

// This method will be called once per scheduler run

void Launcher::Periodic() {}

double Launcher::GetEncoderVelocity()
{
    return m_encoder.();
}

void Launcher::SetVelocity(double target)
{
    m_pidController.SetReference(target, rev::ControlType::kVelocity);
}

void Launcher::SetPercentOutput(double target)
{
    m_pidController.SetReference(target, rev::ControlType::kCurrent);
}