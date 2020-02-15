/* If you do not understand anything or do not agree with the way things are you can fix things because Jack did some of the code (most of it for now)*/

#pragma once

#include <frc/util/color.h>
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"
#include <iostream>

// #include <frc/TimedRobot.h>
// #inclued 

class ColorSensor : public frc2::SubsystemBase
{
  //try to connect

  // these are pre-determined colors
  /*static constexpr*/ frc::Color kBlueTarget = frc::Color(0.143, 0.427, 0.429);
  /*static constexpr*/ frc::Color kGreenTarget = frc::Color(0.197, 0.561, 0.240);
  /*static constexpr*/ frc::Color kRedTarget = frc::Color(0.561, 0.232, 0.114);
  /*static constexpr*/ frc::Color kYellowTarget = frc::Color(0.361, 0.524, 0.113);


  //these are here to find out what color is found
  std::string colorString;
  double confidence = 0.0;
  rev::ColorMatch m_colorMatcher;
  static constexpr auto i2cPort = frc::I2C::Port::kOnboard;
  rev::ColorSensorV3 m_colorSensor{i2cPort};
  frc::Color detectedColor = m_colorSensor.GetColor();
  frc::Color matchedColor = m_colorMatcher.MatchClosestColor(detectedColor, confidence);

  public:
    ColorSensor() {
      
      //these check every example color to check what color the color sensor is looking at
      if (matchedColor == kBlueTarget) {
        colorString = "Blue";
      } else if (matchedColor == kRedTarget) {
        colorString = "Red";
      } else if (matchedColor == kGreenTarget) {
        colorString = "Green";
      } else if (matchedColor == kYellowTarget) {
        colorString = "Yellow";
      } else {
        colorString = "Unknown";
      } 
      //If some one knows how to print the color string to see if it works please type it here
      wpi::outs() << "This is just a Test" << colorString << "o-|-<\n";
    };


    void Periodic() {

    };

    ~ColorSensor() {
      
    };
};