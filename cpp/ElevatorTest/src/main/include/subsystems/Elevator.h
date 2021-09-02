/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Servo.h>
#include "ctre/Phoenix.h"
#include "Constants.h"

class Elevator : public frc2::SubsystemBase
{
public:
  Elevator();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();
  
  /**
   * Sets percent output of the motor.
   * @param target is the percent the motor outputs at, positive values are up (tentatively)
   */
  void SetPercentOutput(double percent);

  /**
   * Tells whether forward limit switch is hit.
   * @return true if forward limit switch is hit, false otherwise
   */ 
  bool GetFwdLimitSwitch();

  /**
   * Tells whether reverse limit switch is hit.
   * @return true if reverse limit switch is hit, false otherwise
   */ 
  bool GetRevLimitSwitch();

  /**
   * Runs elevator up until it hits forward limit switch.
   */
  void GoUp();

  /**
   * Runs elevator down until it hits reverse limit switch.
   */ 
  void GoDown();

  /**
   * Stops elevator.
   */ 
  void Stop();

  void ResetEncoders();

  int GetElevatorPosition();

  void SetServoAngle(double angle);

private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  
  WPI_TalonSRX m_elevatorMotor;
  WPI_TalonSRX m_elevatorMotor2; // follows m_elevatorMotor

  frc::Servo m_servo{ElevatorConstants::kServoChannel};

};
