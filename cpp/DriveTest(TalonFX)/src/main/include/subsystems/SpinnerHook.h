/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>

#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"
#include "ctre/Phoenix.h"


class SpinnerHook : public frc2::SubsystemBase {
 public:
  SpinnerHook();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  frc::Color GetDetectedColor();

  frc::Color GetMatchedColor();

  void Spin();

  void ResetSpinnerPosition();

  double GetSpinnerPosition();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  WPI_TalonSRX m_spinnerMotor;
  rev::ColorSensorV3 m_colorSensor{frc::I2C::Port::kOnboard};
  rev::ColorMatch m_colorMatcher;

};
