/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/TimedRobot.h>
#include <frc/XboxController.h>
#include <pixy2/Pixy2UART.h>
#include <pixy2/Pixy2CCC.h>

#include "Drivetrain.h"

class Robot : public frc::TimedRobot {
 public:
  Pixy2UART m_pixy;
  
  void AutonomousPeriodic() override {
    TeleopPeriodic();
    m_drive.UpdateOdometry();
  }

  void TeleopPeriodic() override {
    // Get the x speed. We are inverting this because Xbox controllers return
    // negative values when we push forward.
    const auto xSpeed =
        -m_controller.GetY(frc::GenericHID::kLeftHand) * Drivetrain::kMaxSpeed;

    // Get the rate of angular rotation. We are inverting this because we want a
    // positive value when we pull to the left (remember, CCW is positive in
    // mathematics). Xbox controllers return positive values when you pull to
    // the right by default.
    const auto rot = -m_controller.GetX(frc::GenericHID::kRightHand) *
                     Drivetrain::kMaxAngularSpeed;

    m_drive.Drive(xSpeed, rot);
    //do pixy2 stuff
    //init if not initialized
    static bool is_initialized = false;
    if (!is_initialized) {
      wpi::outs() << "initializing pixy2...\n";
      m_pixy.init();
      is_initialized = true;
    }

    uint16_t num_blocks = m_pixy.ccc.getBlocks();
    wpi::outs() << "Num blocks is: " << num_blocks << "\n";
    for (uint16_t i = 0; i < num_blocks; i++) {
      wpi::outs() << "block " << i << "\n";
      m_pixy.ccc.blocks[i].print();
    }
  }

 private:
  frc::XboxController m_controller{0};
  Drivetrain m_drive;
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
