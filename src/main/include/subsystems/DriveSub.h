// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <rev/CANSparkMax.h> // from https://www.chiefdelphi.com/t/2024-software-download-links/448077.  use (https://software-metadata.revrobotics.com/REVLib-2024.json) file.
#include "Constants.h"
#include <frc/ADIS16448_IMU.h>
#include <frc/AnalogPotentiometer.h>


class DriveSub : public frc2::SubsystemBase 
{
 public:
  DriveSub();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */

  void Init();
  void DriveTank(double left, double right);
  void DriveRC(double vertical, double horizontal);

  /// @brief gets yaw position (in degrees) from start position
  /// @return angle in degrees
  double GetAngle();
  double GetAngleX();
  double GetAngleY();
  double GetAngleZ();

  /// @brief gets the current distance traveled from left encoders
  /// @return distance in inches
  double GetDistanceL1();
  double GetDistanceL2();
  double GetSpeedL1();
  double GetSpeedL2();

  /// @brief gets the current distance traveled from right encoder2
  /// @return distance in inches
  double GetDistanceR1();
  double GetDistanceR2();
  double GetSpeedR1();
  double GetSpeedR2();


  void Periodic() override;

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  private:
  ///////////////////////////////////////////////////////////////////////////////
  // CAN Motors
  //ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_motorControlL1 {OperatorConstants::kSymphonyDriveMotorControlL1};
  //rev::CANSparkMax m_motorL1 {OperatorConstants::kSymphonyDriveMotorIDL1, rev::CANSparkMax::MotorType::kBrushed};
//
  //ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_motorControlR1 {OperatorConstants::kSymphonyDriveMotorControlR1};
  //rev::CANSparkMax m_motorR1 {OperatorConstants::kSymphonyDriveMotorIDR1, rev::CANSparkMax::MotorType::kBrushed};
//
  //ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_motorControlL2 {OperatorConstants::kSymphonyDriveMotorControlL2};
  //rev::CANSparkMax m_motorL2 {OperatorConstants::kSymphonyDriveMotorIDL2, rev::CANSparkMax::MotorType::kBrushed};
//
  //ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_motorControlR2 {OperatorConstants::kSymphonyDriveMotorControlR2};
  //rev::CANSparkMax m_motorR2 {OperatorConstants::kSymphonyDriveMotorIDR2, rev::CANSparkMax::MotorType::kBrushed};

  // Potentiometer Test
  frc::AnalogPotentiometer m_Pot {0, 3600, 0};

  // encoders are part of CANSparkMax - keep private
  //inline rev::SparkRelativeEncoder GetEncoderL1()
  //{
  //  return m_motorL1.GetEncoder(rev::CANEncoder::EncoderType::kQuadrature, OperatorConstants::kSymphonyL1EncoderCounts);
  //}
  //inline rev::SparkRelativeEncoder GetEncoderL2()
  //{
  //  return m_motorL2.GetEncoder(rev::CANEncoder::EncoderType::kQuadrature, OperatorConstants::kSymphonyL1EncoderCounts);
  //}
  //inline rev::SparkRelativeEncoder GetEncoderR1()
  //{
  //  return m_motorR1.GetEncoder(rev::CANEncoder::EncoderType::kQuadrature, OperatorConstants::kSymphonyL1EncoderCounts);
  //}
  //inline rev::SparkRelativeEncoder GetEncoderR2()
  //{
  //  return m_motorR2.GetEncoder(rev::CANEncoder::EncoderType::kQuadrature, OperatorConstants::kSymphonyL1EncoderCounts);
  //}

  ///////////////////////////////////////////////////////////////////////////////
  // IMU
  //frc::ADIS16448_IMU m_imu;
};
