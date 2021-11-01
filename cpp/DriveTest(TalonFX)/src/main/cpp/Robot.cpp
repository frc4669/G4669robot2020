/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <iostream>

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>



void Robot::RobotInit() {
  
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }

  /* std::string musicPath = "C:/Users/Galil/git/Robot2020/cpp/DriveTest(TalonFX)/src/main/deploy/US Anthem.chrp";
  m_musicPlayer.LoadMusic(musicPath);
  m_musicPlayer.AddInstrument(m_container.m_drivetrain.m_leftMaster);
  m_musicPlayer.AddInstrument(m_container.m_drivetrain.m_rightMaster);
  m_musicPlayer.AddInstrument(m_container.m_drivetrain.m_leftSlave);
  m_musicPlayer.AddInstrument(m_container.m_drivetrain.m_rightSlave); */
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {

  // Hi Yasha it works now even though it's a jank way to do it
  // I know we desperate
  
  // if green button held, run intake
  if(m_container.f310.getButtonPressed(1)) {
    // m_container.m_intake.DeployIntake(); better to have it as one button but too busy to add a debounce so i'll remove so drivers dont break robot
    m_container.m_intake.RunIntake();
  }
  if(m_container.f310.getButtonReleased(1)) {
    m_container.m_intake.StopIntake();
    // m_container.m_intake.TuckIntake();
  }

  // if back button held, run intake
  if(m_container.f310.getButtonPressed(7)) {
    m_container.m_intake.DeployIntake();
  }
  // if start buttoneh]ef
  if(m_container.f310.getButtonPressed(8)) {
    m_container.m_intake.TuckIntake();
  }  

  // if red button held, run feeder
  if(m_container.f310.getButtonPressed(2)) {
    m_container.m_feeder.HoldRunLauncherFeeder();
    m_container.m_feeder.HoldRunHopperFeeder();
  }
  if(m_container.f310.getButtonReleased(2)) {
    m_container.m_feeder.StopHopperFeeder();
    m_container.m_feeder.StopLauncherFeeder();
  }

  // if blue button held, run feeder in reverse
  if(m_container.f310.getButtonPressed(3)) {
    m_container.m_feeder.HoldRunLauncherFeederRev();
    m_container.m_feeder.HoldRunHopperFeederRev();
  }
  if(m_container.f310.getButtonReleased(3)) {
    m_container.m_feeder.StopHopperFeeder();
    m_container.m_feeder.StopLauncherFeeder();
  }

  // right shoulder to shift up, left shoulder to shift down
  if(m_container.f310.getButtonPressed(m_container.f310.left_joy_button)) {
    m_container.m_drivetrain.ShiftForward();
  }
  if(m_container.f310.getButtonPressed(m_container.f310.right_joy_button)) {
    m_container.m_drivetrain.ShiftReverse();
  }

  // left joy button held, spin shooter
  if(m_container.f310.getButtonPressed(m_container.f310.left_shoulder_button)) {
    m_container.m_launcher.SetVelocity(4400);
  }
  if(m_container.f310.getButtonReleased(m_container.f310.left_shoulder_button)) {
    m_container.m_launcher.SetVelocity(0);
  }
  
  /* if (m_container.f310.getButtonPressed(m_container.f310.right_joy_button))
  {
    m_musicPlayer.Play();
  } */

}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
