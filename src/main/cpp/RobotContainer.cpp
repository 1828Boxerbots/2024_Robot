// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

RobotContainer::RobotContainer() 
{
  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() 
{
  // NOTE: Use this function to configure button bindings on controllers
}

void RobotContainer::Init()
{
  // Initialize Subsystems
  m_DriveSub.Init();

  // Set default commands for each subsystem
  m_DriveSub.SetDefaultCommand(DriveCommand(&m_DriveSub, &m_DriveController));
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() 
{
  // NOTE: Currently does nothing
}
