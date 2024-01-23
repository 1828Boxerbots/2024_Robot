// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Autos.h"
#include "commands/VisionAlignCmd.h"

#include <frc2/command/Commands.h>
#include <frc2/command/SequentialCommandGroup.h>

frc2::CommandPtr autos::Position1CmdGrp(DriveSub* pDriveSub, VisionSub *pVisionSub, ShooterSub *pShooterSub)
{
  return frc2::SequentialCommandGroup(
    //VisionAlignCmd(pVisionSub, pDriveSub, 0.5, 0.5, 0)                                  // look for AprilTag - ID=???
    // , VisionFwdCmd(pVisionSub, pDriveSub, kOptDistToShoot, 1.0)              // go to optimal distance to shoot Speaker
    // , ShootCmd(pShooterSub, kOptDistShooterSpeed)                            // depends on 'kOptDistToShoot'
    // , TurnCmd(pDriveSub, XXX_deg)                                            // turn XX-deg to face note on ground (starting angle to look)
    // , GroundVisionAlignCmd(pVisionSub, pDriveSub, kOptDistToShoot, 1.0)      // look for note on ground
    // , LoadCmd(pIntakeSub, 1.0)                                               // turn ON loader
    // , ForwardCmd(pDriveSub, kOptDistToLoad, 1.0)                             // suck up note
    // , LoadCmd(pIntakeSub, 0.0)                                               // turn OFF loader
    // , TurnCmd(pDriveSub, XXX_deg)                                            // turn XX-deg to face AprilTag
    // , VisionAlignCmd(pVisionSub, pDriveSub, 0.5)                             // look for AprilTag
    // , VisionFwdCmd(pVisionSub, pDriveSub, kOptDistToShoot, 1.0)              // go to optimal distance to shoot
    // , ShootCmd(pShooterSub, kOptDistShooterSpeed)                            // depends on 'kOptDistToShoot'
    // , TurnCmd(pDriveSub, XXX_deg)                                            // turn XX-deg to face to cross line
    // , ForwardCmd(pDriveSub, kOptDistToCrossLine, 1.0)                        // move forward to cross line
  ).ToPtr();
}
