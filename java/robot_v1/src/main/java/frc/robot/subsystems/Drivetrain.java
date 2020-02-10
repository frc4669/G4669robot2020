
/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package frc.robot.subsystems;

import com.analog.adis16470.frc.ADIS16470_IMU;
import com.ctre.phoenix.motorcontrol.ControlMode;
import com.ctre.phoenix.motorcontrol.FeedbackDevice;
import com.ctre.phoenix.motorcontrol.NeutralMode;
import com.ctre.phoenix.motorcontrol.StatusFrameEnhanced;
import com.ctre.phoenix.motorcontrol.can.WPI_TalonFX;

import edu.wpi.first.wpilibj.DoubleSolenoid;
import edu.wpi.first.wpilibj.SpeedControllerGroup;
import edu.wpi.first.wpilibj.drive.DifferentialDrive;
import edu.wpi.first.wpilibj2.command.SubsystemBase;
import frc.robot.Constants;

public class Drivetrain extends SubsystemBase {
  /**
   * Creates a new Drivetrain.
   */

  private WPI_TalonFX leftDriveMaster;
  private WPI_TalonFX leftDriveSlave;
  private WPI_TalonFX rightDriveMaster;
  private WPI_TalonFX rightDriveSlave;

  private DifferentialDrive drivetrain;

  private DoubleSolenoid shifter;

  private ADIS16470_IMU imu;

  public Drivetrain() {
    super();
    imu = new ADIS16470_IMU();

    leftDriveMaster = new WPI_TalonFX(Constants.driveLeftMasterID);
    leftDriveSlave = new WPI_TalonFX(Constants.driveLeftSlaveID);
    rightDriveMaster = new WPI_TalonFX(Constants.driveRightMasterID);
    rightDriveSlave = new WPI_TalonFX(Constants.driveRightSlaveID);

    drivetrain = new DifferentialDrive(new SpeedControllerGroup(leftDriveMaster, leftDriveSlave),
        new SpeedControllerGroup(rightDriveMaster, rightDriveSlave));

    shifter = new DoubleSolenoid(Constants.shifter1, Constants.shifter2);

  }

  public void configMotor(WPI_TalonFX falcon, boolean left) {

    falcon.configFactoryDefault();

    falcon.configSelectedFeedbackSensor(FeedbackDevice.IntegratedSensor, 0, 10);
    falcon.setInverted(!left);
    falcon.setSensorPhase(true);

    falcon.setNeutralMode(NeutralMode.Brake);

    falcon.configOpenloopRamp(0.5, 0);

    falcon.configNominalOutputForward(0, 0);
    falcon.configNominalOutputReverse(0, 0);
    falcon.configPeakOutputForward(0.95, 0);
    falcon.configPeakOutputReverse(-0.95, 0);

    falcon.setStatusFramePeriod(StatusFrameEnhanced.Status_13_Base_PIDF0, 10, 10);
    falcon.setStatusFramePeriod(StatusFrameEnhanced.Status_10_MotionMagic, 10, 10);

    falcon.selectProfileSlot(0, 0);
    falcon.config_kF(0, 0, 10);
    falcon.config_kP(0, 0, 10);
    falcon.config_kI(0, 0, 10);
    falcon.config_kD(0, 0, 10);
    falcon.config_IntegralZone(0, 0, 10);

    falcon.setSelectedSensorPosition(0, 0, 10);

    setCurrentLimit(falcon);

    falcon.configMotionCruiseVelocity(100, 10);
    falcon.configMotionAcceleration(200, 10);

  }

  public void setCurrentLimit(WPI_TalonFX falcon) {
  }

  /**
   * The angle is expected to increase as the gyro turns clockwise when looked at
   * from the top. It needs to follow NED axis conventions in order to work
   * properly with dependent control loops.
   */
  public double getAngle() {
    return imu.getAngle();
  }

  public double getAbsoluteAngle() {
    return imu.getAngle() % 360;
  }

  public void arcadeDrive(double speed, double rotation) {
    drivetrain.arcadeDrive(speed, rotation);
  }

  public void driveForward(double distance) {
    leftDriveMaster.set(ControlMode.MotionMagic, distance);
    leftDriveSlave.set(ControlMode.Follower, Constants.driveLeftMasterID);
    rightDriveMaster.set(ControlMode.MotionMagic, -distance);
    rightDriveSlave.set(ControlMode.Follower, Constants.driveRightMasterID);
  }

  public void shiftHighSpeed() {
    shifter.set(DoubleSolenoid.Value.kForward);
  }

  public void shiftLowSpeed() {
    shifter.set(DoubleSolenoid.Value.kReverse);
  }

  public void stop() {
    drivetrain.arcadeDrive(0, 0);
  }

  @Override
  public void periodic() {
    // This method will be called once per scheduler run
  }
}
