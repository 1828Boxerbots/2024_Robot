// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <units/length.h>
#include "subsystems/VisionSub.h"
#include "Util.h"

VisionSub::VisionSub()
{
    SetName("VisionSub");
}

// This method will be called once per scheduler run
void VisionSub::Periodic() 
{
    ResetVisionData();

    char prefix[250];

    static int heartBeat = 0;
    Util::Log("HB", heartBeat++, GetName());

    photon::PhotonPipelineResult currentResult = m_testCam.GetLatestResult();
    bool seeTargets = currentResult.HasTargets();
    Util::Log("See Targets", seeTargets, GetName());

    //Check if Targets are Present:
    if(seeTargets == true)
    {
        //Get Total Targets Camera Sees:
        std::span<const photon::PhotonTrackedTarget, 4294967295U> targetArray = currentResult.GetTargets();

        int numTargets = (int)targetArray.size();
        Util::Log("numTargets", numTargets, GetName());

        //Find Requested Target:
        for(int i = 0; i < numTargets; i++)
        {

            int ID = targetArray[i].GetFiducialId();
            Util::Log("ID", ID, prefix);

            sprintf(prefix, "%s target #%d ", GetName().c_str(), i);

            // there can only be three possible conditions:  1 target, 2 targets,  3 targets
            // set appropriate ID to each targets
            switch(i)
            {
                case 0:
                m_fiducialID1 = ID;
                Util::Log("fiducialID1", ID, prefix);
                break;

                case 1:
                m_fiducialID2 = ID;
                Util::Log("fiducialID2", ID, prefix);
                break;

                case 2:
                m_fiducialID3 = ID;
                Util::Log("fiducialID3", ID, prefix);
                break;
            }

            // yaw
            m_visionData[ID-1].m_yaw = targetArray[i].GetYaw();
            Util::Log("yaw", m_visionData[ID-1].m_yaw, prefix);

            // pitch
            double targetPitch  = targetArray[i].GetPitch();
            m_visionData[ID-1].m_pitch = targetPitch;
            Util::Log("pitch", targetPitch, prefix);

            // skew
             m_visionData[ID-1].m_skew = targetArray[i].GetSkew();
             Util::Log("pitch", m_visionData[ID-1].m_skew, prefix);

            // area
            m_visionData[ID-1].m_area = targetArray[i].GetArea();
            Util::Log("area", m_visionData[ID-1].m_area, prefix);

            // distance to target AprilTag
            units::meter_t targetHeight = OperatorConstants::kTargetHeightToAmp; // if only one target, we are at AMP
            switch (m_targetAmount)
            {
                case 2:
                    targetHeight = OperatorConstants::kTargetHeightToSpeakers; // if two targets, we are at SPEAKERS
                    break;
                case 3:
                    targetHeight = OperatorConstants::kTargetHeightToSpeakers; // TBD
                    break;
            }
            m_visionData[ID-1].m_dist = photon::PhotonUtils::CalculateDistanceToTarget (m_kCamHeight, targetHeight, m_kCamPitch, (units::degree_t)targetPitch);
            Util::Log("dist(m)", (double)m_visionData[ID-1].m_dist, prefix);
        }
    }
}

void VisionSub::Init()
{
    // initialize Addressable LED lights
    // TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD 
}

void VisionSub::ResetVisionData()
{
    for (int i = 0; i < OperatorConstants::kMaxNumAprilTags; i++)
    {
        m_visionData[i].ResetData();
    }
}

units::meter_t VisionSub::GetTargDist()
{
    int id = GetTargID();
    return m_visionData[ id - 1 ].m_dist;
}

double VisionSub::GetTargYaw()
{
    int id = GetTargID();
    return m_visionData[ id - 1 ].m_yaw;
}

double VisionSub::GetTargPitch()
{
    int id = GetTargID();
    return m_visionData[ id - 1 ].m_pitch;
}

double VisionSub::GetTargSkew()
{
    int id = GetTargID();
    return m_visionData[ id - 1 ].m_skew;
}

double VisionSub::GetTargArea()
{
    int id = GetTargID();
    return m_visionData[ id - 1 ].m_area;
}

int VisionSub::GetTargID()
{
    switch(m_targetAmount)
    {
        case 1:
        return m_fiducialID1;

        case 2:
        if(m_fiducialID1 > m_fiducialID2)
        {
            return m_fiducialID1;
        }
        else
        {
            return m_fiducialID2;
        }

        break;

        case 3:
        return m_fiducialID1;
        //TBD

        default:
        return 0;
    }
}
