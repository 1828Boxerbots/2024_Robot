// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <units/length.h>

struct VisionData 
{
  VisionData();
  void ResetData();
  double m_pitch;
  double m_yaw;
  double m_skew;
  double m_area;
  units::meter_t m_dist;
};
