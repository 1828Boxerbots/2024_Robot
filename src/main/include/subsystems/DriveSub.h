// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Victor.h>
#include "Util.h"


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
 frc::Victor m_MotorRight{0};
 frc::Victor m_MotorLeft{1};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
