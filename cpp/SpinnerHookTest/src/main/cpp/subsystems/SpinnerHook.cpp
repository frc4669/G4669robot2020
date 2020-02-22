/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/SpinnerHook.h"
#include "Constants.h"
using namespace SpinnerHookConstants;
#include <iostream>


SpinnerHook::SpinnerHook() 
  : m_spinnerMotor{kSpinnerPort}
{
  Init();
}

void SpinnerHook::Init() {
  m_colorMatcher.AddColorMatch(kBlueTarget);
  m_colorMatcher.AddColorMatch(kGreenTarget);
  m_colorMatcher.AddColorMatch(kRedTarget);
  m_colorMatcher.AddColorMatch(kYellowTarget);

  redEntry = frc::Shuffleboard::GetTab("ColorDetected").Add("Red", 0).GetEntry();
  greenEntry = frc::Shuffleboard::GetTab("ColorDetected").Add("Green", 0).GetEntry();
  blueEntry = frc::Shuffleboard::GetTab("ColorDetected").Add("Blue", 0).GetEntry();
  redMatchedEntry = frc::Shuffleboard::GetTab("ColorDetected").Add("RedMatched", 0).GetEntry();
  greenMatchedEntry = frc::Shuffleboard::GetTab("ColorDetected").Add("GreenMatched", 0).GetEntry();
  blueMatchedEntry = frc::Shuffleboard::GetTab("ColorDetected").Add("BlueMatched", 0).GetEntry();

  m_spinnerMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0);

  m_spinnerMotor.SelectProfileSlot(0, 0);
  m_spinnerMotor.Config_kF(0, 0.3);
  m_spinnerMotor.Config_kP(0, 0.2);
  m_spinnerMotor.Config_kI(0, 0);
  m_spinnerMotor.Config_kD(0, 0);

  m_spinnerMotor.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, 10);
  m_spinnerMotor.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, 10);

  m_spinnerMotor.ConfigNominalOutputForward(0);
  m_spinnerMotor.ConfigNominalOutputReverse(0);
  m_spinnerMotor.ConfigPeakOutputForward(1);
  m_spinnerMotor.ConfigPeakOutputReverse(-1);

  m_spinnerMotor.ConfigMotionCruiseVelocity(1500); // 2500
  m_spinnerMotor.ConfigMotionAcceleration(1500);

  m_spinnerMotor.SetSelectedSensorPosition(0);
  m_spinnerMotor.SetSensorPhase(true);
  m_spinnerMotor.ConfigMotionSCurveStrength(0);

}

// This method will be called once per scheduler run
void SpinnerHook::Periodic() {
  redEntry.SetDouble(this->GetDetectedColor().red);
  greenEntry.SetDouble(this->GetDetectedColor().green);
  blueEntry.SetDouble(this->GetDetectedColor().blue);

  redMatchedEntry.SetDouble(this->GetMatchedColor().red);
  greenMatchedEntry.SetDouble(this->GetMatchedColor().green);
  blueMatchedEntry.SetDouble(this->GetMatchedColor().blue);

  // std::cout << "red: " << this->GetMatchedColor().red << "\n";
  // std::cout << "green" << this->GetMatchedColor().green << "\n";
  // std::cout << "blue " << this->GetMatchedColor().blue << "\n";

}

frc::Color SpinnerHook::GetDetectedColor()
{
  return m_colorSensor.GetColor();
}

frc::Color SpinnerHook::GetMatchedColor()
{
  frc::Color detectedColor = m_colorSensor.GetColor();
  double confidence = 0.95;
  return m_colorMatcher.MatchClosestColor(detectedColor, confidence);
}

void SpinnerHook::SpinRotations()
{
  m_spinnerMotor.Set(ControlMode::MotionMagic, kColorWheelCircumference / kSpinnerCircumference * kTicksPerSpinnerRotation * 3.5);
}

void SpinnerHook::SpinColor()
{
  m_spinnerMotor.Set(ControlMode::PercentOutput, 0.5);
}

void SpinnerHook::Stop()
{
  m_spinnerMotor.Set(ControlMode::Disabled, 0);
}

void SpinnerHook::ResetSpinnerPosition()
{
  m_spinnerMotor.GetSensorCollection().SetQuadraturePosition(0);
}

double SpinnerHook::GetSpinnerPosition() {
  int raw_quadrature_position =  m_spinnerMotor.GetSensorCollection().GetQuadraturePosition();
  std::cout << "\n" << "raw quadrature position: " << raw_quadrature_position << "\n";
  return raw_quadrature_position;
  //return m_spinnerMotor.GetSensorCollection().GetQuadraturePosition();
}

int SpinnerHook::GetError()
{
  return m_spinnerMotor.GetClosedLoopError(0);
}


