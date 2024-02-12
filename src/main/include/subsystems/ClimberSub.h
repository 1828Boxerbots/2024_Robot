// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "../Constants.h"

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <frc/AnalogPotentiometer.h>



class ClimberSub : public frc2::SubsystemBase {
 public:
  ClimberSub();

  void Init();
  void SetMotors(double speed);
  void Extend();
  void Retract();
  void Stop(); 
  bool IsAtRetractLimit();
  bool IsAtExtendLimit();
  

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:

  ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_motorL{OperatorConstants::kSymphonyClimberMotorIDL};
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_motorR{OperatorConstants::kSymphonyClimberMotorIDR};
};
