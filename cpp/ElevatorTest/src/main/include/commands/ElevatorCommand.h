#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Elevator.h"

/**
 * A simple command that grabs a hatch with the HatchSubsystem.  Written
 * explicitly for pedagogical purposes.  Actual code should inline a command
 * this simple with InstantCommand.
 *
 * @see InstantCommand
 */
class ElevatorCommand : public frc2::CommandHelper<frc2::CommandBase, ElevatorCommand> {
 public:
  explicit ElevatorCommand(Elevator* m_elevator);

  void Initialize() override;

  void Execute() override;

  bool IsFinished() override;

 private:
  Elevator * m_elevator;
};