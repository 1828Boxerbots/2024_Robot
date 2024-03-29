// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/XboxController.h>
#include "subsystems/DriveSub.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class TeleopDriveCmd : public frc2::CommandHelper<frc2::Command, TeleopDriveCmd> 
{
 public:
  TeleopDriveCmd(DriveSub *pDriveSub, frc::XboxController *pController);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
  DriveSub* m_pDriveSub = nullptr;
  frc::XboxController* m_pController = nullptr;
  double m_yRight= 0;
  double m_yLeft= 0;
  double m_xRight= 0;
  double m_xLeft= 0;
  bool m_isFinished = false;

};
