/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/TimedRobot.h>
#include <frc/XboxController.h>

#include "Drivetrain.h"
#include "F310.h"
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"

class Robot : public frc::TimedRobot {
 public:

 /**
   * Note: Any example colors should be calibrated as the user needs, these
   * are here as a basic example.
   */
  static constexpr frc::Color kBlueTarget = frc::Color(0.152, 0.445, 0.412);
  static constexpr frc::Color kGreenTarget = frc::Color(0.182, 0.568, 0.249);
  static constexpr frc::Color kRedTarget = frc::Color(0.464, 0.375, 0.160);
  static constexpr frc::Color kYellowTarget = frc::Color(0.319, 0.553, 0.127);

 void RobotInit() {
    m_colorMatcher.AddColorMatch(kBlueTarget);
    m_colorMatcher.AddColorMatch(kGreenTarget);
    m_colorMatcher.AddColorMatch(kRedTarget);
    m_colorMatcher.AddColorMatch(kYellowTarget);
  }

  void AutonomousPeriodic() override {
    TeleopPeriodic();
    m_drive.UpdateOdometry();
  }

  void TeleopPeriodic() override {
    printf("test print through printf\n");
    wpi::outs() << "test print through wpi::outs\n";
    frc::Color detectedColor = m_colorSensor.GetColor();
    double confidence = 0.0;
    frc::Color matchedColor = m_colorMatcher.MatchClosestColor(detectedColor, confidence);
    wpi::outs() << "color sensor values r:" << detectedColor.red << " g:"
      << detectedColor.green << " b:"<< detectedColor.blue << "\n";

    if (matchedColor == kBlueTarget) {
      // red is greatest
      wpi::outs() << "I see BLUE\n";
    }
    else if (matchedColor == kRedTarget)
    {
      // green is greatest
      wpi::outs() << "I see RED\n";
    }
    else if (matchedColor == kGreenTarget) {
      // blue is greatest
      wpi::outs() << "I see GREEN\n";
    }
    else if (matchedColor == kYellowTarget)
    {
      // yellow is greatest
      wpi::outs() << "I see YELLOW\n";
    }
    else {
      // ??
      wpi::outs() << "I don't know what I see\n";
    }
    
    

    // Get the x speed. We are inverting this because Xbox controllers return
    // negative values when we push forward.
    const auto xSpeed =
        -m_controller.getLeftY() * Drivetrain::kMaxSpeed;

    // Get the rate of angular rotation. We are inverting this because we want a
    // positive value when we pull to the left (remember, CCW is positive in
    // mathematics). Xbox controllers return positive values when you pull to
    // the right by default.
    const auto rot = -m_controller.getRightX() *
                     Drivetrain::kMaxAngularSpeed;

    m_drive.Drive(xSpeed, rot);
  }

 private:
  F310 m_controller;
  Drivetrain m_drive;
  /**
   * Change the I2C port below to match the connection of your color sensor
   */
  static constexpr auto i2cPort = frc::I2C::Port::kOnboard;

  /**
   * A Rev Color Sensor V3 object is constructed with an I2C port as a 
   * parameter. The device will be automatically initialized with default 
   * parameters.
   */
  rev::ColorSensorV3 m_colorSensor{i2cPort};
  rev::ColorMatch m_colorMatcher;
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
