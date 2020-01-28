/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ColorDetector.h"
#include <frc/util/color.h>

#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"
#include "Constants.h"

ColorDetector::ColorDetector() 
  : m_colorSensor{ColorDetectionConstants::i2cPort}
{}

void ExampleSubsystem::Periodic()
{
  // Implementation of subsystem periodic method goes here.
  frc::Color detectedColor = m_colorSensor.GetColor();
  double IR = m_colorSensor.GetIR();
  
  frc::SmartDashboard::PutNumber("Red", detectedColor.red);
  frc::SmartDashboard::PutNumber("Green", detectedColor.green);
  frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
  frc::SmartDashboard::PutNumber("IR", IR);

  uint32_t proximity = m_colorSensor.GetProximity();
  frc::SmartDashboard::PutNumber("Proximity", proximity);
  
}
