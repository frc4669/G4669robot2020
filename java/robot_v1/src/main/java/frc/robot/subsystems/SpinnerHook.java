/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package frc.robot.subsystems;

import com.ctre.phoenix.motorcontrol.ControlMode;
import com.ctre.phoenix.motorcontrol.can.WPI_TalonSRX;

import edu.wpi.first.wpilibj.BuiltInAccelerometer;
import edu.wpi.first.wpilibj.interfaces.Accelerometer;
import edu.wpi.first.wpilibj2.command.SubsystemBase;
import frc.robot.Constants;

public class SpinnerHook extends SubsystemBase {
  /**
   * Creates a new SpinnerHook.
   */

  private WPI_TalonSRX spinnerMotor;
  private WPI_TalonSRX elevatorMotor;
  private WPI_TalonSRX leftWinchMotor;
  private WPI_TalonSRX rightWinchMotor;

  public Accelerometer accel;

  public SpinnerHook() {
    super();
    spinnerMotor = new WPI_TalonSRX(Constants.spinnerID);
    elevatorMotor = new WPI_TalonSRX(Constants.elevatorID);
    leftWinchMotor = new WPI_TalonSRX(Constants.leftClimbID);
    rightWinchMotor = new WPI_TalonSRX(Constants.rightClimbID);

    accel = new BuiltInAccelerometer(Accelerometer.Range.k4G); 
  }

  public void spinManual(double percent)
  {
    spinnerMotor.set(ControlMode.PercentOutput, percent);
  }

  public void spinDistance(double inches)
  {
    // spinnerMotor.set(ControlMode.MotionMagic, distance);
  }

  public void moveElevator(double heightInInches)
  {
    // elevatorMotor.set(ControlMode.MotionMagic, distance);
  }

  public void stopElevator() {
    elevatorMotor.set(ControlMode.Velocity, 0);
  }

  public void manualHeight(double percent)  {
    elevatorMotor.set(ControlMode.PercentOutput, percent);
  }

  public void climbAll() {
    elevatorMotor.set(0.7);
    leftWinchMotor.set(0.7);
    rightWinchMotor.set(0.7);
  }

  public void climbLeft(boolean climb){
    if (climb) leftWinchMotor.set(0.7);
    else leftWinchMotor.set(0);
  }
  public void climbRight(boolean climb){
    if (climb) rightWinchMotor.set(0.7);
    else rightWinchMotor.set(0);
  }
  public void climbCenter(boolean climb){
    if (climb) elevatorMotor.set(0.7);
    else elevatorMotor.set(0);
  }
  
  public void unwindLeft(boolean unwind){
    if (unwind) leftWinchMotor.set(-0.3);
    else leftWinchMotor.set(0);
  }
  public void unwindRight(boolean unwind){
    if (unwind) rightWinchMotor.set(-0.3);
    else rightWinchMotor.set(0);
  }
  public void unwindCenter(boolean unwind){
    if (unwind) elevatorMotor.set(-0.3);
    else elevatorMotor.set(0);
  }
  
  public void windLeft(boolean unwind){
    if (unwind) leftWinchMotor.set(0.3);
    else leftWinchMotor.set(0);
  }
  public void windRight(boolean unwind){
    if (unwind) rightWinchMotor.set(0.3);
    else rightWinchMotor.set(0);
  }
  public void windCenter(boolean unwind){
    if (unwind) elevatorMotor.set(0.3);
    else elevatorMotor.set(0);
  }
  
  public double getAccelX(){
    return accel.getX();
  }
  public double getAccelY(){
    return accel.getY();
  }
  public double getAccelZ(){
    return accel.getZ();
  }
  
  public void stop() {
    elevatorMotor.set(0);
    leftWinchMotor.set(0);
    rightWinchMotor.set(0);
  }


  @Override
  public void periodic() {
    // This method will be called once per scheduler run
  }
}
