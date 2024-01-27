// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace OperatorConstants 
{
// LED Strip(s)
constexpr int PIXEL_COUNT = 60;

//Drive:
inline constexpr int kDriverControllerPort = 0;
inline constexpr int kSymphonyDriveMotorIDR1 = 1; //Change value.
inline constexpr int kSymphonyDriveMotorIDL1 = 2; //Change value.
inline constexpr int kSymphonyDriveMotorIDR2 = 3; //Change value.
inline constexpr int kSymphonyDriveMotorIDL2 = 4; //Change value.
inline constexpr int kSymphonyDriveMotorControlR1 = 1; //Change value.
inline constexpr int kSymphonyDriveMotorControlL1 = 2; //Change value.
inline constexpr int kSymphonyDriveMotorControlR2 = 3; //Change value.
inline constexpr int kSymphonyDriveMotorControlL2 = 4; //Change value.
inline constexpr int kSymphonyDriveEncoderAR = 1; //Change value.
inline constexpr int kSymphonyDriveEncoderAL = 2; //Change value.
inline constexpr int kSymphonyDriveEncoderBR = 3; //Change value.
inline constexpr int kSymphonyDriveEncoderBL = 4; //Change value.
inline constexpr int kSymphonyL1EncoderCounts = 363; //Change value.
inline constexpr int kSymphonyL2EncoderCounts = 363; //Change value.
inline constexpr int kSymphonyR1EncoderCounts = 363; //Change value.
inline constexpr int kSymphonyR2EncoderCounts = 363; //Change value.



//Shooter:
inline constexpr int kSymphonyShooterPWMPortL = 3;
inline constexpr int kSymphonyShooterPWMPortR = 2;
inline constexpr int kSymphonyShooterEncoderAL = 2; //values are for C418
inline constexpr int kSymphonyShooterEncoderBL = 3; //values are for C418
inline constexpr int kSymphonyShooterEncoderAR = 0; //values are for C418
inline constexpr int kSymphonyShooterEncoderBR = 1; //values are for C418

//Loader:
inline constexpr int kSymphonyLoaderPhotogate = 8; //values are for C418
inline constexpr int kSymphonyLoaderMotor = 5; //values are for C418

//Baton:
inline constexpr int kSymphonyBatonMotorL = 9; //bogus port value, not true at all
inline constexpr int kSymphonyBatonMotorR = 10; //bogus port value, not true at all
inline constexpr int kSymphonyBatonPotentiometerPort = 12; //bogus port value, not true at all 
inline constexpr int kSymphonyBatonRestAngle = 90; //bogus value
inline constexpr int kSymphonyBatonSwingAngle = 13; //bogus value

// Climber
inline constexpr int kSymphonyClimberMotorLeft = 1; 
inline constexpr int kSymphonyClimberMotorRight = 2; 
inline constexpr double kSymphonyClimberExtendedAngleLimit = 50.0; 
inline constexpr double kSymphonyClimberRetractedAngleLimit = 10.0; 
inline constexpr double kSymphonyClimberMotorSpeed = 1.0; 
inline constexpr int kSymphonyClimberPotentiometerPort = 1;
inline constexpr int kSymphonyClimberPotentiometerRestAngle = 0;




}  // namespace OperatorConstants
