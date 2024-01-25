// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>

#include "subsystems/DriveSub.h"
#include "subsystems/VisionSub.h"
#include "subsystems/ShooterSub.h"

namespace autos 
{
    frc2::CommandPtr Position1CmdGrp(DriveSub* pDriveSub, VisionSub *pVisionSub, ShooterSub *pShooterSub);
    frc2::CommandPtr Position2CmdGrp(DriveSub* pDriveSub, VisionSub *pVisionSub, ShooterSub *pShooterSub);
    frc2::CommandPtr Position3CmdGrp(DriveSub* pDriveSub, VisionSub *pVisionSub, ShooterSub *pShooterSub);
}  // namespace autos
