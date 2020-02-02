#pragma once

#include <frc2/command/SubsystemBase.h>

#include "Constants.h"
#include "ctre/Phoenix.h"

class Intake : public frc2::SubsystemBase
{
public:
  Intake();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  
  /**
   * Spins the intake motor to intake the power cell.
   */
  void IntakeBall();

  /**
   * Lowers the intake "jaw".
   */
  void OpenJaw();

  /**
   * Raises the intake "jaw".
   */
  void CloseJaw();

  /**
   * Stops the intake motor.
   */
  void StopIntake();

  /**
   * Stops the jaw motor.
   */
  void StopJaw();
  

private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  // The motor controllers
  WPI_TalonFX m_intake;
  WPI_TalonFX m_intakeJaw;
};
