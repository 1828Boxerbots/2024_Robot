// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/VisionRangeCmd.h"

VisionRangeCmd::VisionRangeCmd(VisionSub *pVisionSub, DriveSub *pDriveSub, double speed, double range, double deadZone) 
{
  SetName("VisionRangeCmd");
  m_pVisionSub = pVisionSub;
  m_pDriveSub = pDriveSub;
  m_range = fabsf(range);
  m_speed = fabsf(speed);

  m_deadZone = fabsf(deadZone);
  if(m_deadZone <= kMinDeadZone)
  {
    m_deadZone = kMinDeadZone;
  }

  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_pVisionSub);
  AddRequirements(m_pDriveSub);
}

// Called when the command is initially scheduled.
void VisionRangeCmd::Initialize() 
{
  m_isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void VisionRangeCmd::Execute() 
{
  if(m_pVisionSub == nullptr or m_pDriveSub == nullptr)
  {
    m_isFinished = true;
    return;
  }
  
  //No Target Check.
  if(m_pVisionSub->HasTargets() == false)
  {
    // no targets
    return;
  }

  if (m_pVisionSub->NumValidTargets() == 0)
  {
    // no targets
    return;
  }

  double dist= m_pVisionSub->GetDistanceInInches();
  
  // double speed = m_speed;
  // speed = m_controller.Calculate(dist, m_deadZone);

  if(m_range >= (dist+m_deadZone) and -m_range <= (dist-m_deadZone))
  {
    m_pDriveSub->DriveTank(0.0, 0.0);
    return;
  }

  if(m_range < dist)
  {
    m_pDriveSub->DriveTank(m_speed, m_speed);
    return;
  }

  if(m_range > dist)
  {
    m_pDriveSub->DriveTank(-m_speed, -m_speed);
  }
}

// Called once the command ends or is interrupted.
void VisionRangeCmd::End(bool interrupted) 
{
  m_pDriveSub->DriveTank(0.0, 0.0);
}

// Returns true when the command should end.
bool VisionRangeCmd::IsFinished() 
{
  return m_isFinished;
}
