/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Launcher.h"

using namespace DriveConstants;

Launcher::Launcher()
    : m_launcher{kLauncherMotorPort}
{
    m_launcher.Set(ControlMode::Velocity, 0);
    m_launcher.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, kTimeoutMs);
    m_launcher.SetSensorPhase(false);

    /* set the peak and nominal outputs */
    m_launcher.ConfigNominalOutputForward(0, kTimeoutMs);
    m_launcher.ConfigNominalOutputReverse(0, kTimeoutMs);
    m_launcher.ConfigPeakOutputForward(1, kTimeoutMs);
    m_launcher.ConfigPeakOutputReverse(-1, kTimeoutMs);
    /* set closed loop gains in slot0 */
    m_launcher.Config_kF(kPIDLoopIdx, 0.018,   kTimeoutMs);
    m_launcher.Config_kP(kPIDLoopIdx, 0.15,    kTimeoutMs);
    m_launcher.Config_kI(kPIDLoopIdx, 0.001,   kTimeoutMs);
    m_launcher.Config_kD(kPIDLoopIdx, 11,      kTimeoutMs);

    m_launcher.SetInverted(false);
}

// This method will be called once per scheduler run
void Launcher::Periodic() {}

double Launcher::GetEncoderVelocity()
{
    return m_launcher.GetSelectedSensorVelocity(kPIDLoopIdx);
}

void Launcher::SetVelocity(double target)
{
    m_launcher.Set(ControlMode::Velocity, target);
}

void Launcher::SetPercentOutput(double target)
{
    m_launcher.Set(ControlMode::PercentOutput, target);
}
