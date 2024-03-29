// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/ShooterSub.h"
#include "subsystems/VisionSub.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class ShootCmd
    : public frc2::CommandHelper<frc2::Command, ShootCmd> {
 public:
  ShootCmd(ShooterSub *pShooterSub, VisionSub *pVisionSub, double speed = -0.1);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
  double m_speed = 0;
  ShooterSub *m_pShooterSub = nullptr;
  VisionSub *m_pVisionSub = nullptr;
  bool m_isFinished = false;
};
