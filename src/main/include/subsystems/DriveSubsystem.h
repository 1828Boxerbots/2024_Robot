#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>

#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <rev/CANSparkMax.h>

#include "HardwarePorts.h"

class DriveSubsystem : public frc2::Subsystem
{
public:
    DriveSubsystem();

    void Init();

    void Periodic() override;

    void Move(double x, double y);

private:
    // Motor Controllers
    ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_VictorSPX {CanID::VictorSPX};
    rev::CANSparkMax m_SparkMAX {CanID::SparkMAX, rev::CANSparkMax::MotorType::kBrushed};
};