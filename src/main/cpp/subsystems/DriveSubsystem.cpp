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

void DriveSubsystem::Move(double x, double y)
{
    m_SparkMAX.Set(y);
    m_VictorSPX.Set(y);
}