// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/controller/PIDController.h>
#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "subsystems/VisionSub.h"
#include "subsystems/DriveSub.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class VisionAlignCmd : public frc2::CommandHelper<frc2::Command, VisionAlignCmd> 
{
 public:
  VisionAlignCmd(VisionSub *pVisionSub, DriveSub *pDriveSub, double speed, double deadZone);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
  VisionSub* m_pVisionSub = nullptr;
  DriveSub* m_pDriveSub = nullptr;
  double m_speed = 0.0;
  double m_deadZone = 0.0;
  double m_targYaw =0.0;
  bool m_isFinished = false;
  const double kMinDeadZone = 0.1;

  const double kProportionalGain = 0.1;
  const double kIntegralGain = 0.0;
  const double kDerivativeGain = 0.0;

  frc::PIDController m_controller { kProportionalGain, kIntegralGain, kDerivativeGain };
};
