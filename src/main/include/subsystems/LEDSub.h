#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/AddressableLED.h>

#include "Constants.h"

class LEDSub : public frc2::SubsystemBase
{
public:
    LEDSub();

    void Init();

    void Periodic() override;

private:
    frc::AddressableLED m_AddressableLED {6};
    std::array<frc::AddressableLED::LEDData, OperatorConstants::PIXEL_COUNT> m_PixelBuffer;

    int m_PixelHue = 0;
};