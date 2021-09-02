/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Launcher.h"
#include "Constants.h"

using namespace LauncherConstants;

Launcher::Launcher() 
    : m_launcher{kLauncherPort, rev::CANSparkMax::MotorType::kBrushless},
      m_pidController{m_launcher.GetPIDController()},
      m_encoder{m_launcher.GetEncoder()},
      m_follower{kFollowPort, rev::CANSparkMax::MotorType::kBrushless},
      m_followerPIDController{m_follower.GetPIDController()},
      m_followerEncoder{m_follower.GetEncoder()}
{
    m_follower.Follow(m_launcher,true);
    m_launcher.SetInverted(false);
    m_pidController.SetP(0.00);
    m_pidController.SetI(0.00);
    m_pidController.SetD(0.00);
    m_pidController.SetFF(0.0001947);
}

// This method will be called once per scheduler run
void Launcher::Periodic() {
}

double Launcher::GetEncoderVelocity()
{
    return m_encoder.GetVelocity();
}

void Launcher::SetVelocity(double target)
{
    m_pidController.SetReference(target, rev::ControlType::kVelocity);
}

void Launcher::SetVoltage(double target)
{
}
