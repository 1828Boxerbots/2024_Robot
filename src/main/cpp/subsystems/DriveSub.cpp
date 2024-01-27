// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSub.h"
#include "Util.h"

DriveSub::DriveSub()
{
    SetName("DriveSub");
}

// This method will be called once per scheduler run
void DriveSub::Periodic()
{
    //// motor encoders
    //Util::Log("MotorEncoderL1-dist", GetDistanceL1(), GetName());
    //Util::Log("MotorEncoderL2-dist", GetDistanceL2(), GetName());
    //Util::Log("MotorEncoderR1-dist", GetDistanceR1(), GetName());
    //Util::Log("MotorEncoderR2-dist", GetDistanceR2(), GetName());
    //Util::Log("MotorEncoderL1-speed", GetSpeedL1(), GetName());
    //Util::Log("MotorEncoderL2-speed", GetSpeedL2(), GetName());
    //Util::Log("MotorEncoderR1-speed", GetSpeedR1(), GetName());
    //Util::Log("MotorEncoderR2-speed", GetSpeedR2(), GetName());
//
    //Util::Log("MotorEncoderL1-avgDepth", GetEncoderL1().GetAverageDepth(), GetName());
    //Util::Log("MotorEncoderL2-avgDepth", GetEncoderL2().GetAverageDepth(), GetName());
    //Util::Log("MotorEncoderR1-avgDepth", GetEncoderR1().GetAverageDepth(), GetName());
    //Util::Log("MotorEncoderR2-avgDepth", GetEncoderR2().GetAverageDepth(), GetName());
//
    //Util::Log("MotorEncoderL1-cntPerRev", GetEncoderL1().GetCountsPerRevolution(), GetName());
    //Util::Log("MotorEncoderL2-cntPerRev", GetEncoderL2().GetCountsPerRevolution(), GetName());
    //Util::Log("MotorEncoderR1-cntPerRev", GetEncoderR1().GetCountsPerRevolution(), GetName());
    //Util::Log("MotorEncoderR2-cntPerRev", GetEncoderR2().GetCountsPerRevolution(), GetName());
//
    //Util::Log("MotorEncoderL1-inverted", GetEncoderL1().GetInverted(), GetName());
    //Util::Log("MotorEncoderL2-inverted", GetEncoderL2().GetInverted(), GetName());
    //Util::Log("MotorEncoderR1-inverted", GetEncoderR1().GetInverted(), GetName());
    //Util::Log("MotorEncoderR2-inverted", GetEncoderR2().GetInverted(), GetName());
//
    //Util::Log("MotorEncoderL1-measPeriod", GetEncoderL1().GetMeasurementPeriod(), GetName());
    //Util::Log("MotorEncoderL2-measPeriod", GetEncoderL2().GetMeasurementPeriod(), GetName());
    //Util::Log("MotorEncoderR1-measPeriod", GetEncoderR1().GetMeasurementPeriod(), GetName());
    //Util::Log("MotorEncoderR2-measPeriod", GetEncoderR2().GetMeasurementPeriod(), GetName());
//
    //Util::Log("MotorEncoderL1-posConvFactor", GetEncoderL1().GetPositionConversionFactor(), GetName());
    //Util::Log("MotorEncoderL2-posConvFactor", GetEncoderL2().GetPositionConversionFactor(), GetName());
    //Util::Log("MotorEncoderR1-posConvFactor", GetEncoderR1().GetPositionConversionFactor(), GetName());
    //Util::Log("MotorEncoderR2-posConvFactor", GetEncoderR2().GetPositionConversionFactor(), GetName());
//
    //Util::Log("MotorEncoderL1-velConvFactor", GetEncoderL1().GetVelocityConversionFactor(), GetName());
    //Util::Log("MotorEncoderL2-velConvFactor", GetEncoderL2().GetVelocityConversionFactor(), GetName());
    //Util::Log("MotorEncoderR1-velConvFactor", GetEncoderR1().GetVelocityConversionFactor(), GetName());
    //Util::Log("MotorEncoderR2-velConvFactor", GetEncoderR2().GetVelocityConversionFactor(), GetName());
//
    //// IMU
    //Util::Log("IMU-angleX", GetAngleX(), GetName());
    //Util::Log("IMU-angleY", GetAngleY(), GetName());
    //Util::Log("IMU-angleZ", GetAngleZ(), GetName());
    //Util::Log("IMU-angle", (double)m_imu.GetAngle(), GetName());
//
    //Util::Log("IMU-barPressure", (double)m_imu.GetBarometricPressure(), GetName());
    //Util::Log("IMU-magFluxX", (double)m_imu.GetMagneticFieldX(), GetName());
    //Util::Log("IMU-magFluxY", (double)m_imu.GetMagneticFieldY(), GetName());
    //Util::Log("IMU-magFluxZ", (double)m_imu.GetMagneticFieldZ(), GetName());
    //Util::Log("IMU-temperature", (double)m_imu.GetTemperature(), GetName());
    //Util::Log("IMU-xCompAngle", (double)m_imu.GetXComplementaryAngle(), GetName());
    //Util::Log("IMU-yCompAngle", (double)m_imu.GetYComplementaryAngle(), GetName());
    //Util::Log("IMU-xAccelAngle", (double)m_imu.GetXFilteredAccelAngle(), GetName());
    //Util::Log("IMU-yAccelAngle", (double)m_imu.GetYFilteredAccelAngle(), GetName());
    //Util::Log("IMU-yAxis", (double)m_imu.GetYawAxis(), GetName());

    frc::SmartDashboard::PutNumber("Pot Angle: ", m_Pot.Get());
}

void DriveSub::Init()
{
    // invert apprpriate motors
    //m_motorControlR1.SetInverted(true);
    //m_motorControlR2.SetInverted(true);
    //m_motorControlL1.SetInverted(false);
    //m_motorControlL2.SetInverted(false);
    
    // stop all motors
    //m_motorControlR1.Set(0.0);
    //m_motorControlR2.Set(0.0);
    //m_motorControlL1.Set(0.0);
    //m_motorControlL2.Set(0.0);

    // initialize encoders
    const double wheelDia = 6.0; // inches
    const double countsPerRotation = 288; // TBD for REV-41-1300 value=288.  for REV-41-1291, value=28(bare),1120(40:1),560(20:1)
    // TBD TBD TBD TBD TBD TBD - where to set distancePerPulse?
    //GetEncoderL1().SetPositionConversionFactor(wheelDia * 3.14 / countsPerRotation);
    //GetEncoderL2().SetPositionConversionFactor(wheelDia * 3.14 / countsPerRotation);
    //GetEncoderR1().SetPositionConversionFactor(wheelDia * 3.14 / countsPerRotation);
    //GetEncoderR2().SetPositionConversionFactor(wheelDia * 3.14 / countsPerRotation);
    //GetEncoderL1().SetInverted(false);
    //GetEncoderL2().SetInverted(false);
    //GetEncoderR1().SetInverted(true);
    //GetEncoderR2().SetInverted(true);
    //GetEncoderL1().SetAverageDepth(tbd);
    //GetEncoderL1().SetMeasurementPeriod(tbd);
    //GetEncoderL1().SetVelocityConversionFactor(tbd);

    // initialize imu
    //m_imu.Calibrate();
    //m_imu.Reset();
}

void DriveSub::DriveTank(double left, double right)
{
    //m_motorControlR1.Set(right);
    //m_motorControlR2.Set(right);
    //m_motorControlL1.Set(left);
    //m_motorControlL2.Set(left);
}

void DriveSub::DriveRC(double vertical, double horizontal)
{
    DriveTank(vertical+horizontal, vertical-horizontal);
}

///////////////////////////////////////////////////////////////////////////////
// ENCODERS
// double DriveSub::GetDistanceL1()
// {
//     return GetEncoderL1().GetPosition();
// }
// double DriveSub::GetDistanceL2()
// {
//     return GetEncoderL2().GetPosition();
// }
// double DriveSub::GetDistanceR1()
// {
//     return GetEncoderR1().GetPosition();
// }
// double DriveSub::GetDistanceR2()
// {
//     return GetEncoderR2().GetPosition();
// }
// double DriveSub::GetSpeedL1()
// {
//     return GetEncoderL1().GetVelocity();
// }
// double DriveSub::GetSpeedL2()
// {
//     return GetEncoderL2().GetVelocity();
// }
// double DriveSub::GetSpeedR1()
// {
//     return GetEncoderR1().GetVelocity();
// }
// double DriveSub::GetSpeedR2()
// {
//     return GetEncoderR2().GetVelocity();
// }

///////////////////////////////////////////////////////////////////////////////
// IMU
// double DriveSub::GetAngle()
// {
//     return GetAngleX();
// }
// double DriveSub::GetAngleX()
// {
//     return (double)m_imu.GetGyroAngleX();;
// }
// double DriveSub::GetAngleY()
// {
//     return (double)m_imu.GetGyroAngleY();;
// }
// double DriveSub::GetAngleZ()
// {
//     return (double)m_imu.GetGyroAngleZ();;
// }
