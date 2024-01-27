// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>

#include "Constants.h"
#include "subsystems/VisionSub.h"
#include "subsystems/DriveSub.h"
#include "subsystems/ShooterSub.h"
#include "subsystems/LoaderSub.h"

#include "subsystems/LEDSub.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();

  int GetDPDT();
  void Init();

 private:
  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc2::CommandXboxController m_driverController{
      OperatorConstants::kDriverControllerPort};
  frc2::CommandXboxController m_driverController2{
      OperatorConstants::kDriverControllerPort};

  void ConfigureBindings();

  // The robot's subsystems are defined here...
  VisionSub m_visionSub;
  DriveSub m_driveSub;
  ShooterSub m_shooterSub;
  LoaderSub m_loaderSub;
  // IntakeSub m_intakeSub;
  // ClimberSub m_climberSub;
  LEDSub m_LEDSub;
};
