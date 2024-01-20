#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>

#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <rev/CANSparkMax.h>
#include <frc/motorcontrol/PWMSparkMax.h>

#include <frc/motorcontrol/Spark.h>

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
    //ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_VictorSPX {CanID::VictorSPX};
    //rev::CANSparkMax m_SparkMAX {CanID::SparkMAX, rev::CANSparkMax::MotorType::kBrushed};

    //Test Motors (Shooter):
    frc::Spark m_sparkL2{0};
    frc::Spark m_sparkR2{1};

    // ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_VictorSPXL1 {CanID::VictorSPXL1};
    // rev::CANSparkMax m_neoL1 {CanID::SparkMAXL1, rev::CANSparkMax::MotorType::kBrushed};
    // ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_VictorSPXR1 {CanID::VictorSPXR1};
    // rev::CANSparkMax m_neoR1 {CanID::SparkMAXR1, rev::CANSparkMax::MotorType::kBrushed};

    //rev::CANSparkMax m_neoL1 {3, rev::CANSparkMax::MotorType::kBrushed};
    //rev::CANSparkMax m_neoR1 {2, rev::CANSparkMax::MotorType::kBrushed};

    frc::PWMSparkMax m_neoL1 {3};
    frc::PWMSparkMax m_neoR1 {2};
};