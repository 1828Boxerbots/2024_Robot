// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <photon/PhotonUtils.h>
#include <photon/PhotonCamera.h>
#include <frc/SmartDashboard/SmartDashboard.h>
#include "subsystems/VisionData.h"


class VisionSub : public frc2::SubsystemBase 
{
 public:
  VisionSub();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void Init();

  double GetTargYaw(int id);
  double GetTargPitch(int id);
  double GetTargSkew(int id);
  double GetTargArea(int id);
  int GetTargID();
  void ResetVisionData();
  units::meter_t GetTargDist(int id);

 private:
  //Initialize Camera:
  photon::PhotonCamera m_testCam{"TestCam1"};

  //Initialize Data Variables:
  int m_targetID = 0;
  const int m_idRequested = 3;
  const int m_idRequested2 = 4;
  double m_targetSkew = 0.0;
  double m_targetPitch = 0.0;
  double m_targetYaw = 0.0;
  double m_targetArea = 0.0;
  double m_targetSkew2 = 0.0;
  double m_targetPitch2 = 0.0;
  double m_targetYaw2 = 0.0;
  double m_targetArea2 = 0.0;
  int m_targetAmount = 0;
  int m_fiducialID1;
  int m_fiducialID2;
  int m_fiducialID3;
    
  units::meter_t m_targetDist = 0.0_in;
  units::meter_t m_targetDist2 = 0.0_in;
  const units::meter_t m_kCamHeight = 0.0625_ft;
  const units::meter_t m_kTargetHeight = 4_in;
  const units::radian_t m_kCamPitch = 0.0_deg;

  VisionData m_visionData[16];

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
