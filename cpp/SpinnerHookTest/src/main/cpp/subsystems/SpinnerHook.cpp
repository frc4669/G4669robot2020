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
  Init();
}
void SpinnerHook::Init() {
  m_colorMatcher.AddColorMatch(kBlueTarget);
  m_colorMatcher.AddColorMatch(kGreenTarget);
  m_colorMatcher.AddColorMatch(kRedTarget);
  m_colorMatcher.AddColorMatch(kYellowTarget);

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

  m_spinnerMotor.ConfigMotionCruiseVelocity(1500);
  m_spinnerMotor.ConfigMotionAcceleration(1500);

  m_spinnerMotor.SetSelectedSensorPosition(0);
  m_spinnerMotor.SetSensorPhase(true);
  m_spinnerMotor.ConfigMotionSCurveStrength(0);
  //m_spinnerMotor.SetInverted(true);

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
  m_spinnerMotor.Set(ControlMode::MotionMagic, kColorWheelCircumference / kSpinnerCircumference * kTicksPerSpinnerRotation);
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