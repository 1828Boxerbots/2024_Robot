// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/BatonSub.h"
#include <frc/smartdashboard/SmartDashboard.h>

BatonSub::BatonSub() = default;

// This method will be called once per scheduler run
void BatonSub::Periodic() 
{
    frc::SmartDashboard::PutNumber ("BatonPotentiometer", m_potentiometer.Get());
    frc::SmartDashboard::PutNumber ("BatonMotorLSpeed", m_motorL.Get());
    frc::SmartDashboard::PutNumber ("BatonMotorRSpeed", m_motorR.Get());
}

void BatonSub::Swing(double speed)
{
    m_motorL.Set(speed);
    m_motorR.Set(speed);
} 

void BatonSub::Init()
{
    m_motorR.SetInverted(true);
}

double BatonSub::GetPotentiometer()
{
    return m_potentiometer.Get();
} 

bool BatonSub::GoToRest()
{
    bool isAtLimit = IsAtRestLimit();
    double speed = -m_optimalSpeed;
    if (isAtLimit == true)
    {
      speed = 0.0;
    }
    m_motorL.Set(speed);
    m_motorR.Set(speed);
    return isAtLimit;
}

bool BatonSub::GoToSwing()
{
    bool isAtLimit = IsAtSwingLimit();
    double speed = m_optimalSpeed;
    if (isAtLimit == true)
    {
      speed = 0.0;
    }
    m_motorL.Set(speed);
    m_motorR.Set(speed);
    return isAtLimit;
} 

void BatonSub::Stop()
{
    m_motorL.Set(0.0);
    m_motorR.Set(0.0);
} 

bool BatonSub::IsAtRestLimit()
{
   return GetPotentiometer() <= OperatorConstants::kSymphonyBatonRestAngle;
}

bool BatonSub::IsAtSwingLimit()
{
   return GetPotentiometer() >= OperatorConstants::kSymphonyBatonSwingAngle;
}