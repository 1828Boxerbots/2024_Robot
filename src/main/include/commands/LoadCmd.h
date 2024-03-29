// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <frc/Xboxcontroller.h>
#include <subsystems/LoaderSub.h>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class LoadCmd
    : public frc2::CommandHelper<frc2::Command, LoadCmd> {
 public:
  LoadCmd(frc::XboxController *pController, LoaderSub *pSub, double speed = 1.0);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private: 
  frc::XboxController *m_pController = nullptr;
  LoaderSub *m_pSub = nullptr;
  double m_speed = 0;
  bool m_isFinished = false;
};
