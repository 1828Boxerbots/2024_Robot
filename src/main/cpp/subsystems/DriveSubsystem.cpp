#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem()
{
    // NOTE: Currently does nothing
}

void DriveSubsystem::Init()
{
    // NOTE: Currently does nothing
    // NOTE: Use this to set motor inversion, encoder state, etc.
}

void DriveSubsystem::Periodic()
{
    // NOTE: DO NOT do any processing in this function. Use this to output debug data to
    //       smart dashboard.
}

void DriveSubsystem::TankDrive(double leftY, double rightY)
{
    m_LeftDrive1.Set(leftY);
    m_LeftDrive2.Set(leftY);
    m_RightDrive1.Set(rightY);
    m_RightDrive2.Set(rightY);
}