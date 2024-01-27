#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>

#include <rev/CANSparkMax.h>

#include "HardwarePorts.h"

class IntakeSubsystem : frc2::Subsystem
{
public:
    IntakeSubsystem();
    ~IntakeSubsystem();

    void Init();

    void Periodic() override;

    void SetIntakeSpeed(double speed);

private:
    // Motor Controller(s)
    rev::CANSparkMax m_IntakeMotor { CanID::INTAKE , rev::CANSparkMax::MotorType::kBrushed };
};