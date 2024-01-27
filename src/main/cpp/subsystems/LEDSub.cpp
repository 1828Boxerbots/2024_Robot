#include "subsystems/LEDSub.h"

LEDSub::LEDSub()
{

}

void LEDSub::Init()
{
    m_AddressableLED.SetLength(OperatorConstants::PIXEL_COUNT);
    m_AddressableLED.SetData(m_PixelBuffer);
    m_AddressableLED.Start();
}

void LEDSub::Periodic()
{
    for (int i = 0; i < OperatorConstants::PIXEL_COUNT; i++)
    {
        const auto curPixelHue = (m_PixelHue + (i * 180 / OperatorConstants::PIXEL_COUNT)) % 180;
        m_PixelBuffer[i].SetHSV(curPixelHue, 255, 128);
    }

    m_PixelHue += 3;
    m_PixelHue %= 180;

    m_AddressableLED.SetData(m_PixelBuffer);
}