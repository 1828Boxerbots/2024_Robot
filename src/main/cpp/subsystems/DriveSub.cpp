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
    // m_MotorLeftOne.Set(0.0);
    // m_MotorLeftTwo.Set(0.0);
    // m_MotorRightOne.Set(0.0);
    // m_MotorRightTwo.Set(0.0);

    // m_MotorLeftOne.SetInverted(false);
    // m_MotorLeftTwo.SetInverted(false);
    // m_MotorRightOne.SetInverted(true);
    // m_MotorRightTwo.SetInverted(true);
}

void DriveSub::DriveTank(double left, double right)
{
    // m_MotorLeftOne.Set(left);
    // m_MotorLeftTwo.Set(left);
    // m_MotorRightOne.Set(right);
    // m_MotorRightTwo.Set(right);
}

void DriveSub::DriveRC(double vertical, double horizontal)
{
    DriveTank((vertical+horizontal), (vertical-horizontal));
}

