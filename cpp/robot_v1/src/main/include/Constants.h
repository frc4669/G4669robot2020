/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

#include <units/units.h>
#include <wpi/math>
#include "frc/util/color.h"

namespace OIConstants {
  constexpr int kF310 = 0;
}  

namespace SpinnerHookConstants {
  constexpr int kSpinnerPort = 5;

  // Color Sensor Target Colors
  constexpr frc::Color kBlueTarget = frc::Color(0.177124, 0.466187, 0.356812);
  constexpr frc::Color kGreenTarget = frc::Color(0.196899, 0.560913, 0.240112);
  constexpr frc::Color kRedTarget = frc::Color(0.386108, 0.417847, 0.195923);
  constexpr frc::Color kYellowTarget = frc::Color(0.326050, 0.494507, 0.179321);

  
  constexpr double kPi = 3.14159265359; // in radians

  constexpr double kSpinnerDiameter = 4; // in inches
  constexpr double kTicksPerSpinnerRotation = 4096;
  constexpr double kSpinnerCircumference = kSpinnerDiameter * kPi; // in inches

  constexpr double kColorWheelDiameter = 31; // in inches, real diameter is 35in
  constexpr double kColorWheelCircumference = kColorWheelDiameter * kPi; // in inches

  constexpr double kInchesPerTicks = kSpinnerCircumference / kTicksPerSpinnerRotation;
  constexpr double kTicksPerInches = 1 / kInchesPerTicks;

  constexpr double kTicksPerColorWheelRotation = kColorWheelCircumference * kTicksPerInches;

  const std::string kBlueOption = "Blue";
  const std::string kGreenOption = "Green";
  const std::string kRedOption = "Red";
  const std::string kYellowOption = "Yellow";
  
}

namespace DistanceSensorConstants {
  constexpr int sensorBaudRate = 115200;
}