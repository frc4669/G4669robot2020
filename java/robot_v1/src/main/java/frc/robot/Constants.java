/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package frc.robot;

/**
 * The Constants class provides a convenient place for teams to hold robot-wide numerical or boolean
 * constants.  This class should not be used for any other purpose.  All constants should be
 * declared globally (i.e. public static).  Do not put anything functional in this class.
 *
 * <p>It is advised to statically import this class (or one of its inner classes) wherever the
 * constants are needed, to reduce verbosity.
 */
public final class Constants {
    /** USB IDs for gamepad and joysticks */
	public static final int leftJoystick = 0;
	public static final int rightJoystick = 1;
	public static final int f310 = 2;
	public static final int extremeJoystick = 3;
	public static final int buttonBoard = 4;
    public static final int testButonBoard = 5;
    
    /** CAN IDs for motor controllers */
	public static final int driveLeftMasterID = 1;
	public static final int driveLeftSlaveID = 2;
	public static final int driveRightMasterID = 3;
	public static final int driveRightSlaveID = 4;
	public static final int intakeID = 5;
	public static final int hopperFeederID = 6;
	public static final int launchFeederID = 7;
	public static final int leftLaunchID = 8;
	public static final int rightLaunchID = 9;
	public static final int elevatorID = 10;
	public static final int spinnerID = 11;
	public static final int leftClimbID = 12;
	public static final int rightClimbID = 13;

	/** PCM IDs for solenoids */
	public static final int shifter1 = 0;
	public static final int shifter2 = 1;
	public static final int deploy1 = 2;
	public static final int deploy2 = 3;

}
