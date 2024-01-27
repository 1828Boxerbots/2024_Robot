// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h" 

#include "commands/TeleopShootCmd.h"
#include "commands/LoadCmd.h"
#include "commands/LoadUntilPhotogateCmd.h"
#include "commands/TeleopDriveCmd.h"

RobotContainer::RobotContainer() 
{
  // Initialize all of your commands and subsystems here
  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::Init()
{
  m_driveSub.Init();
  //m_driveSub.SetDefaultCommand(DriveCmd(&m_driveSub, &m_driverController).ToPtr);

  m_visionSub.Init();
  m_shooterSub.Init();
  m_shooterSub.SetDefaultCommand(TeleopShootCmd(&m_driverController, &m_shooterSub)); //in finished code use driverController2
  m_loaderSub.Init();
  m_LEDSub.Init();
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here
  m_driverController.A().WhileTrue(LoadCmd(&m_driverController, &m_loaderSub, 1.0).ToPtr()); //in finished code use driverController2 and 1.0 speed

  m_driverController.Y().WhileTrue(LoadUntilPhotogateCmd(&m_loaderSub, 1.0).ToPtr()); //in finished code use driverController2 and 1.0 speed

  // // Load
  // m_driverController.A().WhileTrue(LoadCommand(m_pLoadSub, &m_driverController, 1.0, LoaderSubBase::intake).ToPtr()); // m_aButton.WhenHeld(m_pLoadIntakeCMD);
  // m_driverController.B().WhileTrue(LoadCommand(m_pLoadSub, &m_driverController, 1.0, LoaderSubBase::intake).ToPtr()); // m_bButton.WhenHeld(m_pLoadUpperCMD);
  // m_driverController.X().WhileTrue(LoadCommand(m_pLoadSub, &m_driverController, 1.0, LoaderSubBase::lower).ToPtr()); // m_xButton.WhenHeld(m_pLoadLowerCMD);
  // m_driverController.Y().WhileTrue(LoadCommand(m_pLoadSub, &m_driverController).ToPtr()); // m_yButton.WhenHeld(m_pLoadAllCMD);
  // // Shoot
  // m_driverController.RightTrigger().WhileTrue(ShootCommand(m_pShootSub, &m_driverController).ToPtr()); // m_rightTrigger.WhenHeld(m_pShootCMD);
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() 
{
  switch (GetDPDT())
  {
    case 1:
      // position 2
      break;
    case 2:
      // position 3
      break;
    case 0:
    default:
      // position 1
      return autos::Position1CmdGrp(&m_driveSub, &m_visionSub, &m_shooterSub);
  }
}

int RobotContainer::GetDPDT() 
{
  return 0;
}
