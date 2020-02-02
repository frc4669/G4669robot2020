#include "subsystems/Intake.h"
#include "Constants.h"

Intake::Intake()
    : m_intake{IntakeConstants::kIntakeMotorPort},
      m_intakeJaw{IntakeConstants::kIntakeJawMotorPort}
{}

void Intake::Periodic() {}

void Intake::IntakeBall(){
    m_intake.Set(TalonFXControlMode::PercentOutput, 0.7);
}

void Intake::OpenJaw(){
    m_intakeJaw.Set(TalonFXControlMode::PercentOutput, 0.25);
}

void Intake::CloseJaw(){
    m_intakeJaw.Set(TalonFXControlMode::PercentOutput, -0.15);
}

void Intake::StopIntake(){
    m_intake.Set(TalonFXControlMode::PercentOutput, 0);
}

void Intake::StopJaw(){
    m_intakeJaw.Set(TalonFXControlMode::PercentOutput, 0);
}