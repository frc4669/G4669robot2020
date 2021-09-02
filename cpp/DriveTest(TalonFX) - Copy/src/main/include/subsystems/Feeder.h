/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include "frc/DoubleSolenoid.h"

class Feeder : public frc2::SubsystemBase {
 public:
  Feeder();  

  void RunHopperFeeder();

  void RunLauncherFeeder();

  void HoldRunHopperFeeder();

  void HoldRunLauncherFeeder();

  void HoldRunHopperFeederRev();

  void HoldRunLauncherFeederRev();

  void StopHopperFeeder();

  void StopLauncherFeeder();

  void ResetEncoders();

  double GetHopperFeederPosition();

  double GetLauncherFeederPosition();

  int GetHopperFeederError();

  int GetLauncherFeederError();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  WPI_TalonSRX m_hopperFeederMotor;
  WPI_TalonSRX m_launcherFeederMotor;


};
