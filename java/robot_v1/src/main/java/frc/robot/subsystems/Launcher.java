/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package frc.robot.subsystems;

// import com.revrobotics.CANEncoder;
import com.revrobotics.CANPIDController;
import com.revrobotics.CANSparkMax;
import com.revrobotics.ControlType;
import com.revrobotics.CANSparkMaxLowLevel.MotorType;

import edu.wpi.first.wpilibj2.command.SubsystemBase;
import frc.robot.Constants;

public class Launcher extends SubsystemBase {
  /**
   * Creates a new Launcher.
   */

  private CANSparkMax leftLaunchMotor;
  // private CANEncoder leftEncoder;
  private CANPIDController leftPIDController;
  private CANSparkMax rightLaunchMotor;
  // private CANEncoder rightEncoder;
  // private CANPIDController rightPIDController;

  public Launcher() {
    super();
    leftLaunchMotor = new CANSparkMax(Constants.leftLaunchID, MotorType.kBrushless);
    // leftEncoder = leftLaunchMotor.getEncoder();
    leftPIDController = leftLaunchMotor.getPIDController();
    rightLaunchMotor = new CANSparkMax(Constants.rightLaunchID, MotorType.kBrushless);
    // rightEncoder = rightLaunchMotor.getEncoder();
    // rightPIDController = rightLaunchMotor.getPIDController();

    configurePID();
  }

  public void configurePID() {
    // set PID coefficients
    leftPIDController.setP(0);
    leftPIDController.setI(0);
    leftPIDController.setD(0);
    leftPIDController.setIZone(0);
    leftPIDController.setFF(0.001);
    leftPIDController.setOutputRange(-1, 1);
  }

  public void setLaunchRPM(int targetRPM) {
    // int maxRPM = 5700;
    leftPIDController.setReference(targetRPM, ControlType.kVelocity);
    rightLaunchMotor.follow(leftLaunchMotor, true);
  }

  public void stop() {
    setLaunchRPM(0);
  }

  @Override
  public void periodic() {
    // This method will be called once per scheduler run
  }
}
