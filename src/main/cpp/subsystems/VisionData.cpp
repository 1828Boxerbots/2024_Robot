// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/VisionData.h"

VisionData::VisionData() = default;

void VisionData::resetData()
{
    m_pitch = 0.0;
    m_skew = 0.0;
    m_yaw = 0.0;
}

