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

namespace OIConstants {
  constexpr int kF310 = 0;
}

namespace ElevatorConstants {
  constexpr int kElevatorMotorPort = 5;
  constexpr int kElevatorMotor2Port = 8;

  constexpr double kTicksPerRotation = 4096;
  constexpr double kInchesPerRotation = 10; // Replace with actual value

  constexpr double kInchesPerTicks =  kInchesPerRotation / kTicksPerRotation;
  constexpr double kTicksPerInches = 1 / kInchesPerTicks;

  constexpr int kServoChannel = 0;

}

// namespace F310DPadConstants{
// constexpr int F310_DPAD_UP = 0;
// constexpr int F310_DPAD_LEFT = 90;
// constexpr int F310_DPAD_DOWN = 180;
// constexpr int F310_DPAD_RIGHT = 270;
// }