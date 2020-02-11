/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ElevatorUp.h"
#include "subsystems/Elevator.h"
#include "Robot.h"

ElevatorUp::ElevatorUp(Elevator * m_elevator) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_elevator});
  m_elevator->GoDown();
}