#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem()
{
    // NOTE: Currently does nothing
}

void DriveSubsystem::Init()
{
    // NOTE: Use this to set motor inversion, encoder state, etc.

    m_neoR1.SetInverted(false);
    m_sparkR2.SetInverted(false);

    m_neoL1.SetInverted(true);
    m_sparkL2.SetInverted(true);
}

void DriveSubsystem::Periodic()
{
    // NOTE: DO NOT do any processing in this function. Use this to output debug data to
    //       smart dashboard.
}

void DriveSubsystem::Move(double x, double y)
{

    double yMod = (y*0.75);

    //Left:
    m_neoR1.Set(yMod);
    m_sparkR2.Set(yMod);

    //Right:
    m_neoL1.Set(yMod);
    m_sparkL2.Set(yMod);
}