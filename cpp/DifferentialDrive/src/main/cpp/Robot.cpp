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

class Robot : public frc::TimedRobot {
 public:
  void AutonomousPeriodic() override {
    TeleopPeriodic();
    m_drive.UpdateOdometry();
  }

  void TeleopPeriodic() override {
    printf("test print through printf\n");
    wpi::outs() << "test print through wpi::outs\n";
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
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
