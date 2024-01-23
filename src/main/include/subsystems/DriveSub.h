// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
//#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
//#include <rev/


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


  void Periodic() override;

 private:

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};