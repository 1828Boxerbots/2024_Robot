// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include "commands/VisionAlignCmd.h"

#include "commands/Autos.h"

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
}

void RobotContainer::ConfigureBindings() 
{
  // Configure your trigger bindings here
  // // Load
  // m_driverController.A().WhileTrue(LoadCommand(m_pLoadSub, &m_driverController, 1.0, LoaderSubBase::intake).ToPtr()); // m_aButton.WhenHeld(m_pLoadIntakeCMD);
  // m_driverController.B().WhileTrue(LoadCommand(m_pLoadSub, &m_driverController, 1.0, LoaderSubBase::intake).ToPtr()); // m_bButton.WhenHeld(m_pLoadUpperCMD);
   m_driverController.X().WhileTrue(VisionAlignCmd(&m_visionSub, &m_driveSub, 0.5, 0.1).ToPtr()); // m_xButton.WhenHeld(m_pLoadLowerCMD);
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
      return autos::Position2CmdGrp(&m_driveSub, &m_visionSub, &m_shooterSub);
      break;
    case 2:
      // position 3
      return autos::Position3CmdGrp(&m_driveSub, &m_visionSub, &m_shooterSub);
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
