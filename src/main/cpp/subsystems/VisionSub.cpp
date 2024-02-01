// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <NetworkTables/NetworkTable.h>
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
    double start = (double)m_timer.Get();
    
    Util::Log("yaw", GetYaw(), GetName() );
    Util::Log("yaw(best)", GetBestYaw(), GetName() );
//    Util::Log("dist(in meters)", (double)GetDistanceInMeters(), GetName());

//    Util::Log("NetworkTableData", GetNetworkTableData(), GetName());

    double total = (double)m_timer.Get() - start;
    Util::Log("periodic(msec)", total*1000.0, GetName());
}
void VisionSub::Periodic2() 
{
    double start = (double)m_timer.Get();

    if(m_isPeriodicFinished == false)
    {
        return;
    }

    m_isPeriodicFinished = false;

    ResetVisionData();

    char prefix[250];

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

    m_isPeriodicFinished = true;

    double end = (double)m_timer.Get();

    double timeDelta = (end - start);

    frc::SmartDashboard::PutNumber("VisionSub - TimeDelta", timeDelta);
}

void VisionSub::Init()
{
    // initialize Addressable LED lights
    // TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD TBD 
    m_timer.Reset();
    m_timer.Start();

    InitNetworkTableData();
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

double VisionSub::GetBestYaw()
{
    photon::PhotonPipelineResult result = m_testCam.GetLatestResult();
    if (result.HasTargets() == false)
    {
        return 0.0;
    }
    Util::Log("Best ID", result.GetBestTarget().GetFiducialId(), GetName());
    return result.GetBestTarget().GetYaw();
}
double VisionSub::GetYaw()
{
    photon::PhotonPipelineResult result = m_testCam.GetLatestResult();
    if (result.HasTargets() == false)
    {
        return 0.0;
    }

    std::span<const photon::PhotonTrackedTarget, 4294967295U> targets = result.GetTargets();
                                                                                // int id1;
                                                                                // int id2;
                                                                                // int id3;

    // find specific ID
    int requiredID = 1; // TBD TBD
    for(unsigned i=0; i<targets.size(); ++i)
    {
        Util::Log(std::string("ID #") + std::to_string(i), targets[i].GetFiducialId(), GetName());
        Util::Log(std::string("Yaw #") + std::to_string(i), targets[i].GetYaw(), GetName());

        if (targets[i].GetFiducialId() == requiredID)
        {
            double yaw = targets[i].GetYaw();
            Util::Log("Final Yaw", targets[i].GetYaw(), GetName());
            return yaw;
        }
    }
    return 0.0;
}

bool VisionSub::HasTargets()
{
    return m_testCam.GetLatestResult().HasTargets();
}
int VisionSub::NumValidTargets()
{
    if (m_testCam.GetLatestResult().HasTargets() == false)
    {
        return 0;
    }
    return m_testCam.GetLatestResult().GetTargets().size();
}

double VisionSub::GetDistanceInMeters()
{
    photon::PhotonPipelineResult result = m_testCam.GetLatestResult();
    if (result.HasTargets() == false)
    {
        return 0.0;
    }

    // get target info
    std::span<const photon::PhotonTrackedTarget, 4294967295U> targets = result.GetTargets();
                                                        // int id1;
                                                        // int id2;
                                                        // int id3;

    // find specific ID
    const int requiredID = 15; // TBD TBD
    for(unsigned i=0; i<targets.size(); ++i)
    {
        Util::Log(std::string("ID #") + std::to_string(i), targets[i].GetFiducialId(), GetName());
        double dist = (double)photon::PhotonUtils::CalculateDistanceToTarget (m_kCamHeight, GetTargetHeight(targets[i].GetFiducialId()), m_kCamPitch, (units::degree_t)targets[i].GetPitch());

        Util::Log(std::string("Dist #") + std::to_string(i), dist, GetName());
        if (targets[i].GetFiducialId() == requiredID)
        {
            Util::Log("Final Dist", dist, GetName());
            return dist;
        }
    }
                                                        // switch(targets.size())
                                                        // {
                                                        //     case 1:
                                                        //         return (double)photon::PhotonUtils::CalculateDistanceToTarget (m_kCamHeight, GetTargetHeight(targets[0].GetFiducialId()), m_kCamPitch, (units::degree_t)targets[0].GetPitch());
                                                        //     case 2:
                                                        //         id1 = targets[0].GetFiducialId();
                                                        //         id2 = targets[1].GetFiducialId();
                                                        //         // only use larger of ID's
                                                        //         if (id1 > id2)
                                                        //         {
                                                        //             return (double)photon::PhotonUtils::CalculateDistanceToTarget (m_kCamHeight, GetTargetHeight(targets[0].GetFiducialId()), m_kCamPitch, (units::degree_t)targets[0].GetPitch());
                                                        //         }
                                                        //         else
                                                        //         {
                                                        //             return (double)photon::PhotonUtils::CalculateDistanceToTarget (m_kCamHeight, GetTargetHeight(targets[1].GetFiducialId()), m_kCamPitch, (units::degree_t)targets[1].GetPitch());
                                                        //         }
                                                        //         break;
                                                        //     case 3:
                                                        //         id1 = targets[0].GetFiducialId();
                                                        //         id2 = targets[1].GetFiducialId();
                                                        //         id3 = targets[2].GetFiducialId();
                                                        //         // TBD - use greatest ID ??? TBD
                                                        //         if (id1 > id2 and id1 > id3         // is id1 largest
                                                        //                 and id1 < 16 and id1 >= 0)  // is ID valid
                                                        //         {
                                                        //             return (double)photon::PhotonUtils::CalculateDistanceToTarget (m_kCamHeight, GetTargetHeight(targets[0].GetFiducialId()), m_kCamPitch, (units::degree_t)targets[0].GetPitch());
                                                        //         }
                                                        //         else if (id2 > id1 and id2 > id3    // is id2 largest
                                                        //                 and id2 < 16 and id2 >= 0)  // is ID valid
                                                        //         {
                                                        //             return (double)photon::PhotonUtils::CalculateDistanceToTarget (m_kCamHeight, GetTargetHeight(targets[1].GetFiducialId()), m_kCamPitch, (units::degree_t)targets[1].GetPitch());
                                                        //         }
                                                        //         else if (id3 > id1 and id3 > id2    // is id3 largest
                                                        //                 and id3 < 16 and id3 >= 0)  // is ID valid
                                                        //         {
                                                        //             return (double)photon::PhotonUtils::CalculateDistanceToTarget (m_kCamHeight, GetTargetHeight(targets[2].GetFiducialId()), m_kCamPitch, (units::degree_t)targets[2].GetPitch());
                                                        //         }
                                                        //         break;
                                                        // }
    return 0.0;
}
units::length::meter_t VisionSub::GetTargetHeight(int id)
{
    switch(id)
    {
        case 1:
            return 0.0_m;
        case 2:
            return 0.0_m;
        case 3:
            return 0.0_m;
        case 4:
            return 0.0_m;
        case 5:
            return 0.0_m;
        case 6:
            return 0.0_m;
        case 7:
            return 0.0_m;
        case 8:
            return 0.0_m;
        case 9:
            return 0.0_m;
        case 10:
            return 0.0_m;
        case 11:
            return 0.0_m;
        case 12:
            return 0.0_m;
        case 13:
            return 0.0_m;
        case 14:
            return 0.0_m;
        case 15:
            return 0.0_m;
        case 16:
            return 0.0_m;
    }
    return 0.0_m;
}

void VisionSub::InitNetworkTableData()
{
    std::string tableName = "photonlib";
    std::string topic = "X";
    std::string topicName = "/" + tableName + "/" + topic;

    // https://docs.wpilib.org/en/stable/docs/software/networktables/tables-and-topics.html
    nt::NetworkTableInstance inst = nt::NetworkTableInstance::GetDefault();

    // get a topic from a NetworkTableInstance
    // the topic name in this case is the full name
    nt::DoubleTopic dblTopic = inst.GetDoubleTopic(topicName);

    // get a topic from a NetworkTable
    // the topic name in this case is the name within the table;
    std::shared_ptr<nt::NetworkTable> table = inst.GetTable(tableName);
    nt::DoubleTopic dblTopic2 = table->GetDoubleTopic(topic);

    // get a type-specific topic from a generic Topic
    nt::Topic genericTopic = inst.GetTopic(topicName);
    nt::DoubleTopic dblTopic3{genericTopic};

    // NOTE: dblTopic, dblTopic2, dblTopic3 should all have SAME value

    // start subscribing; the return value must be retained.
    // the parameter is the default value if no value is available when get() is called
    m_dblSub = dblTopic.Subscribe(0.0);
    m_dblSub2 = dblTopic2.Subscribe(0.0);
    m_dblSub3 = dblTopic3.Subscribe(0.0);
}
double VisionSub::GetNetworkTableData()
{
    double dbl = m_dblSub.Get(-666.0);
    return dbl;
}
