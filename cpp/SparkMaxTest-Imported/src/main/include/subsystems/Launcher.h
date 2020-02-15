/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
 
#pragma once
 
#include <frc2/command/SubsystemBase.h>
#include "rev/CANSparkMax.h"
#include "Constants.h"
 
class Launcher : public frc2::SubsystemBase
{
public:
  Launcher();
 
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();
 
  /**
   * Resets the drive encoders to currently read a position of 0.
   */
  void ResetEncoders();
 
  /**
   * Gets the velocity of the encoder.
   *
   * @return the encoder velocity in ticks per second
   */
  double GetEncoderVelocity();
 
  /**
   * Sets the output of the launcher
   *
   * @param target the target output in terms of velocity
   */
  void SetVelocity(double target);
 
  void SetPercentOutput(double target);
 
private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::CANSparkMax m_launcher;

};