#include "commands/ElevatorCommand.h"
#include "RobotContainer.h"
#include "Constants.h"

ElevatorCommand::ElevatorCommand(Elevator* elevator) {
  AddRequirements({elevator});
  m_elevator = elevator;
}

void ElevatorCommand::Initialize() {}

void ElevatorCommand::Execute()
{
  
}

bool ElevatorCommand::IsFinished() { return true; }