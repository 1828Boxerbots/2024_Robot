// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSub.h"

DriveSub::DriveSub()
{
    SetName("DriveSub");
}

// This method will be called once per scheduler run
void DriveSub::Periodic()
{
    static int heartBeat = 0;
    Util::Log("HB", heartBeat++, GetName());
}

void DriveSub::Init()
{
    m_MotorLeft.Set(0.0);
    m_MotorRight.Set(0.0);

    m_MotorLeft.SetInverted(false);
    m_MotorRight.SetInverted(true);
}

void DriveSub::DriveTank(double left, double right)
{
    m_MotorLeft.Set(left);
    m_MotorRight.Set(right);
}

void DriveSub::DriveRC(double vertical, double horizontal)
{
    DriveTank((vertical+horizontal), (vertical-horizontal));
}

