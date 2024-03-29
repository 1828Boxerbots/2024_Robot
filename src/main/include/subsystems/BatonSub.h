// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <Constants.h>
#include <rev/CANSparkMax.h>
#include <frc/DigitalInput.h>


class BatonSub : public frc2::SubsystemBase 
{
 public:
  BatonSub();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override; 

  void Init();

  double GetPotentiometer(); 

  bool GoToRest();
  bool GoToSwing();
  void Stop();
  bool IsAtRestLimit();
  bool IsAtSwingLimit();



 private:
 void Swing(double speed);

frc::DigitalInput m_SwingMagnet{OperatorConstants::kSymphonyBatonSwingMagnetPort};
frc::DigitalInput m_RestMagnet{OperatorConstants::kSymphonyBatonRestMagnetPort};
 rev::CANSparkMax m_motorL{OperatorConstants::kSymphonyBatonMotorL, rev::CANSparkMax::MotorType::kBrushless}; 
 rev::CANSparkMax m_motorR{OperatorConstants::kSymphonyBatonMotorR, rev::CANSparkMax::MotorType::kBrushless}; 

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};

