// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/VisionAlignCmd.h"

VisionAlignCmd::VisionAlignCmd(VisionSub *pVisionSub, DriveSub *pDriveSub, double speed, double deadZone)
{
  m_pVisionSub = pVisionSub;
  m_pDriveSub = pDriveSub;
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
void VisionAlignCmd::Initialize() 
{
}

// Called repeatedly when this Command is scheduled to run
void VisionAlignCmd::Execute() 
{

  int heartBeat = 0;

  frc::SmartDashboard::PutNumber("VisionAlignCmd - HB", heartBeat++);

  if(m_pVisionSub == nullptr or m_pDriveSub == nullptr)
  {
    m_isFinished = true;
    return;
  }
  
  //No Target Check.
  if(m_pVisionSub->HasTargets() == false)
  {
    m_isFinished = true;
    return;
  }

  // if at center, then stop
  double yaw = m_pVisionSub->GetYaw();
  if((yaw < m_deadZone) and (yaw > -m_deadZone))
  {
    m_isFinished = true;
    return;
  }
  
  // if target is left of robot
  if(yaw < 0.0)
  {
    //Turn left.
    m_pDriveSub->DriveTank(m_speed, -m_speed);
  }
  // if target is right of robot
  else if(yaw > 0.0)
  {
    //Turn right.
    m_pDriveSub->DriveTank(-m_speed, m_speed);
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
  return m_isFinished;
}
