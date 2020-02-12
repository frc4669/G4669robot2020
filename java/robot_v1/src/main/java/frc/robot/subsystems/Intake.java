/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package frc.robot.subsystems;

import com.ctre.phoenix.motorcontrol.ControlMode;
import com.ctre.phoenix.motorcontrol.can.WPI_TalonSRX;

import edu.wpi.first.wpilibj.DoubleSolenoid;
import edu.wpi.first.wpilibj2.command.SubsystemBase;
import frc.robot.Constants;

public class Intake extends SubsystemBase {
  /**
   * Creates a new Intake.
   */

  private WPI_TalonSRX intakeMotor;
  private DoubleSolenoid deploy;
  public Intake() {
    super();
    intakeMotor = new WPI_TalonSRX(Constants.intakeID);
    deploy = new DoubleSolenoid(Constants.deploy1, Constants.deploy2);
  }

  public void runIntake() {
    intakeMotor.set(ControlMode.PercentOutput, 0.4);
  }

  public void stop() {
    intakeMotor.set(ControlMode.PercentOutput, 0);
  }

  public void deployIntake() {
    deploy.set(DoubleSolenoid.Value.kForward);
  }
  public void tuckIntake() {
    deploy.set(DoubleSolenoid.Value.kReverse);
  }

  @Override
  public void periodic() {
    // This method will be called once per scheduler run
  }
}
