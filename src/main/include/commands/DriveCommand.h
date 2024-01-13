#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include <frc/XboxController.h>

#include "subsystems/DriveSubsystem.h"

class DriveCommand : public frc2::CommandHelper<frc2::Command, DriveCommand>
{
    public:
        DriveCommand(DriveSubsystem* pDriveSub, frc::XboxController* pController);

        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override;

    private:
        DriveSubsystem* m_pDriveSub = nullptr;
        frc::XboxController* m_pController = nullptr;
};