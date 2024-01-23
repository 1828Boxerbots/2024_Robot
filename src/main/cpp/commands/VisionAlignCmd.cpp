// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/VisionAlignCmd.h"

VisionAlignCmd::VisionAlignCmd(VisionSub *pVisionSub, DriveSub *pDriveSub, double speed, double deadZone, int targID)
{
  m_pVisionSub = pVisionSub;
  m_pDriveSub = pDriveSub;
  m_speed = speed;
  m_deadZone = deadZone;
  m_targID = targID;

  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_pVisionSub);
  AddRequirements(m_pDriveSub);
}

// Called when the command is initially scheduled.
void VisionAlignCmd::Initialize() 
{
  m_pVisionSub->SetPipeline(m_pipeline);
  frc::SmartDashboard::PutNumber("VisionAlignCmd-Pipeline", m_pipeline);
  m_targYaw = m_pVisionSub->GetTargYaw(m_targID);
}

// Called repeatedly when this Command is scheduled to run
void VisionAlignCmd::Execute() 
{
  if(m_pVisionSub == nullptr and m_pDriveSub == nullptr)
  {
    if((m_targYaw < m_deadZone) and (m_targYaw > -m_deadZone))
    {
      m_pDriveSub->DriveTank(0.0, 0.0);
    }
    else if(m_targYaw < 0.0)
    {
      m_pDriveSub->DriveTank(m_speed, -m_speed);
    }
    else if(m_targYaw > 0.0)
    {
      m_pDriveSub->DriveTank(m_speed, -m_speed);
    }
  }
}

// Called once the command ends or is interrupted.
void VisionAlignCmd::End(bool interrupted) 
{
  m_pDriveSub->DriveTank(0.0, 0.0);
}

// Returns true when the command should end.
bool VisionAlignCmd::IsFinished() 
{
  return false;
}
