/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>

class Intake : public frc2::SubsystemBase {
 public:
  Intake();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  // private WPI_TalonSRX intakeMotor;
  // private DoubleSolenoid deploy;
  // public Intake() {
  //   super();
  //   intakeMotor = new WPI_TalonSRX(Constants.intakeID);
  //   deploy = new DoubleSolenoid(Constants.deploy1, Constants.deploy2);
  // }

  // public void runIntake() {
  //   intakeMotor.set(ControlMode.PercentOutput, 0.4);
  // }

  // public void stop() {
  //   intakeMotor.set(ControlMode.PercentOutput, 0);
  // }

  // public void deployIntake() {
  //   deploy.set(DoubleSolenoid.Value.kForward);
  // }
  // public void tuckIntake() {
  //   deploy.set(DoubleSolenoid.Value.kReverse);
  // }


 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
