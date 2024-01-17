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

    void TankDrive(double leftY, double rightY);

private:
    // Motor Controllers
    rev::CANSparkMax m_LeftDrive1 {CanID::DRIVE_LEFT1, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_LeftDrive2 {CanID::DRIVE_LEFT2, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_RightDrive1 {CanID::DRIVE_RIGHT1, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_RightDrive2 {CanID::DRIVE_RIGHT2, rev::CANSparkMax::MotorType::kBrushless};
};