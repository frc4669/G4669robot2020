/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Launcher.h"
#include "Constants.h"
Launcher::Launcher() 
  : m_leftLaunchMotor{LaunchConstants::kLeftLaunchPort, rev::CANSparkMax::MotorType::kBrushless},
    m_rightLaunchMotor{LaunchConstants::kRightLaunchPort, rev::CANSparkMax::MotorType::kBrushless},
    m_leftPIDController{m_leftLaunchMotor.GetPIDController()}
{}

// This method will be called once per scheduler run
void Launcher::Periodic() {}

void Launcher::ConfigurePID() {
  // set PID coefficients
  m_leftPIDController.SetP(0);
  m_leftPIDController.SetI(0);
  m_leftPIDController.SetD(0);
  m_leftPIDController.SetIZone(0);
  m_leftPIDController.SetFF(0.001);
  m_leftPIDController.SetOutputRange(-1, 1);
}

void Launcher::SetLaunchRPM(int targetRPM) {
  // int maxRPM = 5700;
  m_leftPIDController.SetReference(targetRPM, rev::ControlType::kVelocity);
  m_rightLaunchMotor.Follow(m_leftLaunchMotor, true);
}

void Launcher::Stop() {
  SetLaunchRPM(0);
}
