// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/VisionAlignCmd.h"

VisionAlignCmd::VisionAlignCmd(VisionSub *pVisionSub, DriveSub *pDriveSub, double speed, double deadZone)
{
  SetName("VisionAlignCmd");

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

  Util::Log("HB", heartBeat++, GetName());

  if(m_pVisionSub == nullptr or m_pDriveSub == nullptr)
  {
    m_isFinished = true;
    return;
  }
  
  //No Target Check.
  if(m_pVisionSub->HasTargets() == false)
  {
    // no targets
    m_isFinished = true;
    return;
  }

  if (m_pVisionSub->NumValidTargets() == 0)
  {
    // no targets
    m_isFinished = true;
    return;
  }

  double yaw = m_pVisionSub->GetBestYaw();
  if (m_pVisionSub->NumValidTargets() > 1)
  {
    yaw = m_pVisionSub->GetYaw();
  }

  // if at center, then stop
  if((yaw < m_deadZone) and (yaw > -m_deadZone))
  {
    m_isFinished = true;
    return;
  }
  
  double speed = m_speed;
  speed = m_controller.Calculate(yaw, m_deadZone);
  Util::Log("pidSpeed", speed, GetName());

  // if target is left of robot
  if(yaw < 0.0)
  {
    Util::Log("direction", "Left " + std::to_string(-yaw), GetName() );

    //Turn left.
    m_pDriveSub->DriveTank(m_speed, -m_speed);
  }
  // if target is right of robot
  else if(yaw > 0.0)
  {
    Util::Log("direction", "Right " + std::to_string(yaw), GetName() );

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
