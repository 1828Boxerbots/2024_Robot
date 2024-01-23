// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/VisionAlignCmd.h"

VisionAlignCmd::VisionAlignCmd(VisionSub *pVisionSub, DriveSub *pDriveSub, double speed, double deadZone)
{
  m_pVisionSub = pVisionSub;
  m_pDriveSub = pDriveSub;
  m_speed = speed;
  m_deadZone = deadZone;
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_pVisionSub);
  AddRequirements(m_pDriveSub);
}

// Called when the command is initially scheduled.
void VisionAlignCmd::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void VisionAlignCmd::Execute() 
{
  
}

// Called once the command ends or is interrupted.
void VisionAlignCmd::End(bool interrupted) {}

// Returns true when the command should end.
bool VisionAlignCmd::IsFinished() 
{
  return false;
}
