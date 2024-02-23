// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <photon/PhotonUtils.h>
#include <photon/PhotonCamera.h>
#include <frc/SmartDashboard/SmartDashboard.h>
#include <frc/Timer.h>
#include <string>

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

  /// @brief returns YAW of VALID target found.  if more than one target, calculate best ID
  /// @return YAW value (in degrees)
  double GetYaw();

  /// @brief returns YAW of BestTarget found
  /// @return YAW value (in degrees) of BestTarget found
  double GetBestYaw();

  /// @brief returns if there are ANY targets found in FOV
  /// @return TRUE=one or more targets found.  FALSE=no targets found
  bool HasTargets();

  /// @brief returns number of VALID targets (where ID is >=1 and <=16)
  /// @param pTarget1Id output parameter for ID of aprilTag #1
  /// @param pTarget2Id output parameter for ID of aprilTag #2
  /// @param pYaw1 output parameter for yaw of aprilTag #1
  /// @param pYaw2 output parameter for yaw of aprilTag #2
  /// @return quantity of targets found, within ( >=1 and <=16 )
  int NumValidTargets(int *pTarget1Id = nullptr, int *pTarget2Id = nullptr, double *pYaw1 = nullptr, double *pYaw2 = nullptr);

  /// @brief gets distance to target
  /// @return distance to target in meters
  double GetDistanceInMeters();
  double GetDistanceInInches();


  // NETWORK TABLE TEST ///////////////////////////////////////////////////////
  // TBD TBD TBD - test only
  /// @brief initializes data for network table data acquisition
  void InitNetworkTableData();

  /// @brief returns network data from subscriptions
  /// @return value for given data
  double GetNetworkTableData();
  // NETWORK TABLE TEST ///////////////////////////////////////////////////////

  double CalculateDeadZone(double distance1, double calcAngle1, double distance2, double calcAngle2);

 private:
  /// @brief returns target height (center of aprilTag), for given April-Tag ID
  /// @param id = April-Tag ID
  /// @return height of target, from robot (Symphony) drawings
  units::length::meter_t GetTargetHeight(int id); // in meters
  
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  //Initialize Camera:
  const std::string m_cameraName = "TestCam1";
  photon::PhotonCamera m_testCam{m_cameraName};

  frc::Timer m_timer;

  const units::meter_t m_kCamHeight = 0.875_in;  // TBD TBD - need actual robot specs
  const units::meter_t m_kTargetHeight = 9.25_in;    // TBD TBD - need actual robot specs
  const units::radian_t m_kCamPitch = 0.0_deg;    // TBD TBD - need actual robot specs
  const int m_kMaxTargetId = 16;

  // NETWORK TABLE TEST ///////////////////////////////////////////////////////
  nt::DoubleSubscriber m_dblSub;
  nt::DoubleSubscriber m_dblSub2;
  nt::DoubleSubscriber m_dblSub3;
  // NETWORK TABLE TEST ///////////////////////////////////////////////////////
};
