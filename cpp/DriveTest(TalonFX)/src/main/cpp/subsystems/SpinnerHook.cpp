/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/SpinnerHook.h"
#include "Constants.h"
using namespace SpinnerHookConstants;

SpinnerHook::SpinnerHook() 
  : m_spinnerMotor{kSpinnerPort}
{
  m_colorMatcher.AddColorMatch(kBlueTarget);
  m_colorMatcher.AddColorMatch(kGreenTarget);
  m_colorMatcher.AddColorMatch(kRedTarget);
  m_colorMatcher.AddColorMatch(kYellowTarget);
}

// This method will be called once per scheduler run
void SpinnerHook::Periodic() {}

frc::Color SpinnerHook::GetDetectedColor()
{
  return m_colorSensor.GetColor();
}

frc::Color SpinnerHook::GetMatchedColor()
{
  frc::Color detectedColor = m_colorSensor.GetColor();
  double confidence = 0.0;
  return m_colorMatcher.MatchClosestColor(detectedColor, confidence);
}

void SpinnerHook::Spin()
{
  m_spinnerMotor.Set(ControlMode::PercentOutput, 0.4);
}

void SpinnerHook::ResetSpinnerPosition()
{
  m_spinnerMotor.GetSensorCollection().SetQuadraturePosition(0);
}

double SpinnerHook::GetSpinnerPosition() {
  return m_spinnerMotor.GetSensorCollection().GetQuadraturePosition();
}
