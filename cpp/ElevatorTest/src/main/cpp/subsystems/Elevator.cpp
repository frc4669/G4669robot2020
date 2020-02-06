/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Elevator.h"
#include "Constants.h"

Elevator::Elevator()
  : m_elevatorMotor(ElevatorConstants::kElevatorMotorPort)
{

}

//Called once scheduler run
void Elevator::Periodic() {}

void Elevator::SetPercentOutput(double percent)
{
    m_elevatorMotor.Set(ControlMode::PercentOutput, percent);
}

bool Elevator::GetFwdLimitSwitch()
{
    return m_elevatorMotor.GetSensorCollection().IsFwdLimitSwitchClosed()==1;
} 

bool Elevator::GetRevLimitSwitch()
{
    return m_elevatorMotor.GetSensorCollection().IsRevLimitSwitchClosed()==1;
} 

void Elevator::GoUp()
{
    m_elevatorMotor.Set(ControlMode::PercentOutput, 0.35);
}

void Elevator::GoDown()
{
    m_elevatorMotor.Set(ControlMode::PercentOutput, -0.15);
}