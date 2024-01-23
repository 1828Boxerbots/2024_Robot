// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/VisionSub.h"
#include "Util.h"

VisionSub::VisionSub()
{
    SetName("VisionSub");
}

// This method will be called once per scheduler run
void VisionSub::Periodic() 
{
    char prefix[250];

    //Initialize:
    m_targetSkew = 0.0;
    m_targetPitch = 0.0;
    m_targetYaw = 0.0;
    m_targetID = 0;
    m_targetArea = 0.0;

    static int heartBeat = 0;
    Util::Log("HB", heartBeat++, GetName());

units::meter_t testTargDist = 0_in;
units::meter_t testTargDist2 = 0_in;

    photon::PhotonPipelineResult currentResult = m_testCam.GetLatestResult();
    bool seeTargets = currentResult.HasTargets();
    Util::Log("See Targets", seeTargets, GetName());

    //Check if Targets are Present:
    if(seeTargets == true)
    {
        //Get Total Targets Camera Sees:
        std::span<const photon::PhotonTrackedTarget, 4294967295U> targetArray = currentResult.GetTargets();

        unsigned int targetAmount = targetArray.size();
        Util::Log("numTargets", targetAmount, GetName());

        //Find Requested Target:
        for(unsigned int i = 0; i < targetAmount; i++)
        {
            sprintf(prefix, "%s target #%d ", GetName().c_str(), i);

            photon::PhotonTrackedTarget potentialTarget = targetArray[i];
            m_targetID = potentialTarget.GetFiducialId();
            Util::Log("target ID", m_targetID, prefix);
            Util::Log("Target Requested ID", m_idRequested, GetName());
            Util::Log("Target Requested ID 2", m_idRequested2, GetName());

            if(m_targetID == m_idRequested)
            {
                potentialTarget.GetDetectedCorners();
                // wpi::SmallVector<std::pair<double, double>, 4> targetCorners = potentialTarget.GetDetectedCorners();
                // wpi::SmallVector<std::pair<double, double>, 4> targetMinAreaCorners = potentialtarget.GetMinAreaRectCorners();

                m_targetPitch = potentialTarget.GetPitch();
                Util::Log("targetPitch", m_targetPitch, prefix);

                m_targetSkew = potentialTarget.GetSkew(); 
                Util::Log("targetSkew", m_targetSkew, prefix);

                m_targetYaw = potentialTarget.GetYaw();
                Util::Log("targetYaw", m_targetYaw, prefix);

                m_targetArea = potentialTarget.GetArea();   
                Util::Log("targetArea", m_targetArea, prefix);

// TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - 
testTargDist = photon::PhotonUtils::CalculateDistanceToTarget (m_kCamHeight, 6.5_in, m_kCamPitch, (units::degree_t)m_targetPitch);
Util::Log("TEST+TargDist A(at 6.5in)", (double)testTargDist, prefix);
testTargDist2 = photon::PhotonUtils::CalculateDistanceToTarget (m_kCamHeight, 6.75_in, m_kCamPitch, (units::degree_t)m_targetPitch);
Util::Log("TEST+TargDist2 A(at 6.75in)", (double)testTargDist2, prefix);
// TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - 

                m_targetDist = photon::PhotonUtils::CalculateDistanceToTarget
                    (m_kCamHeight, m_kTargetHeight, m_kCamPitch, (units::degree_t)m_targetPitch);
                Util::Log("targetDist(meters)", (double)m_targetDist, prefix);
            }
            else if (m_targetID == m_idRequested2)
            {
                potentialTarget.GetDetectedCorners();
                // wpi::SmallVector<std::pair<double, double>, 4> targetCorners = potentialTarget.GetDetectedCorners();
                // wpi::SmallVector<std::pair<double, double>, 4> targetMinAreaCorners = potentialtarget.GetMinAreaRectCorners();

                m_targetPitch2 = potentialTarget.GetPitch();
                Util::Log("targetPitch2", m_targetPitch2, prefix);

                m_targetSkew2 = potentialTarget.GetSkew();
                Util::Log("targetSkew2", m_targetSkew2, prefix);

                m_targetYaw2 = potentialTarget.GetYaw();
                Util::Log("targetYaw2", m_targetYaw2, prefix);

                m_targetArea2 = potentialTarget.GetArea();   
                Util::Log("targetArea2", m_targetArea2, prefix);

                m_targetDist2 = photon::PhotonUtils::CalculateDistanceToTarget
                    (m_kCamHeight, m_kTargetHeight, m_kCamPitch, (units::degree_t)m_targetPitch2);
                Util::Log("targetDist2(meters)", (double)m_targetDist2, prefix);

// TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - 
testTargDist = photon::PhotonUtils::CalculateDistanceToTarget (m_kCamHeight, 6.5_in, m_kCamPitch, (units::degree_t)m_targetPitch);
Util::Log("TEST+TargDist B(at 6.5in)", (double)testTargDist, prefix);
testTargDist2 = photon::PhotonUtils::CalculateDistanceToTarget (m_kCamHeight, 6.75_in, m_kCamPitch, (units::degree_t)m_targetPitch);
Util::Log("TEST+TargDist2 B(at 6.75in)", (double)testTargDist2, prefix);
// TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - TEST ONLY - 

            }
        }
    }

}

void VisionSub::Init()
{
    // initialize Addressable LED lights
    // TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD 
}

double VisionSub::GetTargYaw(int id)
{
    if (id == m_idRequested)
    {
        return m_targetYaw;
    } else if (id == m_idRequested2)
    {
        return m_targetYaw2;
    }
    return 0.0;
}
  
double VisionSub::GetTargSkew(int id)
{
    if (id == m_idRequested)
    {
        return m_targetSkew;
    } else if (id == m_idRequested2)
    {
        return m_targetSkew2;
    }
    return 0.0;
}
  
double VisionSub::GetTargArea(int id)
{
    if (id == m_idRequested)
    {
        return m_targetArea;
    } else if (id == m_idRequested2)
    {
        return m_targetArea2;
    }
    return 0.0;
}

units::meter_t VisionSub::GetTargDist(int id)
{
    if (id == m_idRequested)
    {
        return m_targetDist;
    } else if (id == m_idRequested2)
    {
        return m_targetDist2;
    }
    return 0.0_m;
}
