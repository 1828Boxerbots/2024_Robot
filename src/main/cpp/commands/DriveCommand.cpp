#include "commands/DriveCommand.h"

DriveCommand::DriveCommand(DriveSubsystem* pDriveSub, frc::XboxController* pController)
{
    m_pDriveSub = pDriveSub;
    m_pController = pController;

    AddRequirements(m_pDriveSub);
}

void DriveCommand::Initialize()
{
    // NOTE: Currently does nothing
}

void DriveCommand::Execute()
{
    double leftY = 0.0;
    double rightY = 0.0;

    if (m_pController != nullptr)
    {
        leftY = m_pController->GetLeftY();
        rightY = m_pController->GetRightY();
    }

    m_pDriveSub->TankDrive(-leftY, -rightY);
}

void DriveCommand::End(bool isInterrupted)
{
    // Set motor power to 0 when not being controlled
    m_pDriveSub->TankDrive(0.0, 0.0);
}

bool DriveCommand::IsFinished()
{
    return false;
}