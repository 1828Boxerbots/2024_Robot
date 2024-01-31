// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <photon/PhotonUtils.h>
#include <photon/PhotonCamera.h>
#include <frc/SmartDashboard/SmartDashboard.h>
#include "subsystems/VisionData.h"
#include <frc/Timer.h>

#include "Constants.h"

class VisionSub : public frc2::SubsystemBase 
{
 public:
  VisionSub();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /// @brief Initializes all hardware and library components
  void Init();

  /// @brief Determines from Periodic() data, which target ID is most likely to be used
  /// @return the appropriate ID to center/move towards
  int GetTargID();

  /// @brief Resets all vision data to 0.0's
  void ResetVisionData();

  /// @brief Determine's the distance from robot to target AprilTag
  /// @return distance in meters to target AprilTag ID.
  units::meter_t GetTargDist();

  /// @brief get target info
  /// @return 
  double GetTargYaw();
  double GetTargPitch();
  double GetTargSkew();
  double GetTargArea();
  //
  double GetYaw();
  bool HasTargets();
  int NumTargets();
  double GetDistanceInMeters();

  void InitNetworkTableData();
  double GetNetworkTableData();

 private:
  void Periodic2(); // delete me
  
  //Initialize Camera:
  photon::PhotonCamera m_testCam{"TestCam1"};
  units::length::meter_t GetTargetHeight(int id); // in meters

  //Initialize Data Variables:
  int m_targetID = 0;
  int m_targetAmount = 0;
  int m_fiducialID1;
  int m_fiducialID2;
  int m_fiducialID3;

  frc::Timer m_timer;
  bool m_isPeriodicFinished = true;

  units::meter_t m_targetDist = 0.0_in;
  units::meter_t m_targetDist2 = 0.0_in;
  const units::meter_t m_kCamHeight = 0.0625_ft;
  const units::meter_t m_kTargetHeight = 4_in;
  const units::radian_t m_kCamPitch = 0.0_deg;

  /// @brief one data element per AprilTag
  VisionData m_visionData[OperatorConstants::kMaxNumAprilTags];

  nt::DoubleSubscriber m_dblSub;
  nt::DoubleSubscriber m_dblSub2;
  nt::DoubleSubscriber m_dblSub3;

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
