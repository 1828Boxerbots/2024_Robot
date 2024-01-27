#include "subsystems/IntakeSubsystem.h"

IntakeSubsystem::IntakeSubsystem()
{
    // NOTE: Currently does nothing
}

IntakeSubsystem::~IntakeSubsystem()
{
    // NOTE: Currently does nothing
}

void IntakeSubsystem::Init()
{
    // NOTE: Currently does nothing
    // NOTE: Use this to set motor inversion, encoder state, etc.
}

void IntakeSubsystem::Periodic()
{
    // NOTE: DO NOT do any processing in this function. Use this to output debug data to
    //       smart dashboard.
}

void IntakeSubsystem::SetIntakeSpeed(double speed)
{
    m_IntakeMotor.Set(speed);
}