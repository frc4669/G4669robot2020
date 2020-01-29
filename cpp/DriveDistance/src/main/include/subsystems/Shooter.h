#pragma once

#include <frc/Servo.h> 
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"
#include "ctre/Phoenix.h"


class Shooter : public frc2::SubsystemBase
{
public:
  Shooter();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  
  /**
   * So anyway, I started blasting.
   */
  void Fire();

  /**
   * Increases the angle at which you blast.
   */
  void AngleUp();

  /**
   * Decreases the angle at which you blast.
   */
  void AngleDown();

  /**
   * Stops the blaster motor.
   */
  void StopFiring();

  /**
   * Stops the angling motor.
   */
  void StopAngler();
  

private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  // The motor controllers
  WPI_TalonFX m_shooter;

  //Servo
  
};
