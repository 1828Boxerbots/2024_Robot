// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <NetworkTables/NetworkTable.h>
#include <units/length.h>
#include <string>
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
    
    Util::Log("dist(in meters)", (double)GetDistanceInMeters(), GetName());

    Util::Log("NetworkTableData", GetNetworkTableData(), GetName());

    double total = (double)m_timer.Get() - start;
    Util::Log("periodic(msec)", total*1000.0, GetName());
}

void VisionSub::Init()
{
    // initialize Addressable LED lights

    m_timer.Reset();
    m_timer.Start();

    InitNetworkTableData(); // TBD TBD TBD TBD TBD TBD TBD TBD TBD
}

double VisionSub::GetBestYaw()
{
    photon::PhotonPipelineResult result = m_testCam.GetLatestResult();
    if (result.HasTargets() == false)
    {
        return 0.0;
    }
    return result.GetBestTarget().GetYaw();
}

double VisionSub::GetYaw()
{
    photon::PhotonPipelineResult result = m_testCam.GetLatestResult();
    if (result.HasTargets() == false)
    {
        return 0.0;
    }

    int id1;
    int id2;
    double yaw1;
    double yaw2;
    int numTargets = NumValidTargets(&id1, &id2, &yaw1, &yaw2);
    if (numTargets == 0)
    {
        // no VALID targets found
        return 0.0;
    }

    // find specific ID
    if (numTargets == 1)
    {
        return yaw1;
    }

    if (id2 > id1)
    {
        // required ID to focus on is the larger ID
        return yaw2;
    }
    return 0.0;
}

bool VisionSub::HasTargets()
{
    return m_testCam.GetLatestResult().HasTargets();
}

int VisionSub::NumValidTargets(int *pTarget1Id, int *pTarget2Id, double *pYaw1, double *pYaw2)
{
    int targValidCount = 0;

    if (m_testCam.GetLatestResult().HasTargets() == false)
    {
        return 0;
    }

    std::span<const photon::PhotonTrackedTarget, 4294967295U> targets = m_testCam.GetLatestResult().GetTargets();

    for(unsigned i = 0; i < targets.size(); i++)
    {        
        int targID = targets[i].GetFiducialId();

        // valid target ID's are from 1 thru 16.
        if(targID >= 1 and targID <= m_kMaxTargetId)
        {
            targValidCount++;

            // output ID #'s and yaw's
            if (targValidCount == 1 and pTarget1Id != nullptr)
            {
                *pTarget1Id = targets[i].GetFiducialId();
                *pYaw1 = m_testCam.GetLatestResult().GetBestTarget().GetYaw();
            }
            else if (targValidCount == 2 and pTarget2Id != nullptr)
            {
                *pTarget2Id = targets[i].GetFiducialId();
                *pYaw2 = targets[i].GetYaw();
            }
        }
    }

    return targValidCount;
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
    return 0.0;
}

double VisionSub::GetDistanceInInches()
{
    photon::PhotonPipelineResult result = m_testCam.GetLatestResult();
    if (result.HasTargets() == false)
    {
        return 0.0;
    }

    int id1;
    int id2;
    int numTargets = NumValidTargets(&id1, &id2);

    if (numTargets == 0)
    {
        // no VALID targets found
        return 0.0;
    }

        // get target info
    std::span<const photon::PhotonTrackedTarget, 4294967295U> targets = result.GetTargets();

    int requiredID = 0; // TBD TBD
    // find specific ID
    if (numTargets == 1)
    {
        requiredID = id1;
    }

    if (id2 > id1)
    {
        // required ID to focus on is the larger ID
        requiredID = id2;
    }
    
    for(unsigned i=0; i<targets.size(); ++i)
    {
        Util::Log(std::string("ID #") + std::to_string(i), targets[i].GetFiducialId(), GetName());
        units::inch_t dist = (units::inch_t)photon::PhotonUtils::CalculateDistanceToTarget (m_kCamHeight, GetTargetHeight(targets[i].GetFiducialId()), m_kCamPitch, (units::degree_t)targets[i].GetPitch());
        double distInch = (double)dist; // Convert inches to double;.

        Util::Log(std::string("distInch #") + std::to_string(i), distInch, GetName());
        if (targets[i].GetFiducialId() == requiredID)
        {
            Util::Log("Final distInch", distInch, GetName());
            return distInch;
        }
    }
    return 0.0;
}

units::length::meter_t VisionSub::GetTargetHeight(int id)
{
    // for given target-ID, return height (needed for distance calculation)
    switch(id)
    {
        case 1:
            return 0.0_m; // TBD TBD  look at field specs from Game Manual
        case 2:
            return 0.0_m; // TBD TBD  look at field specs from Game Manual
        case 3:
            return 0.0_m; // TBD TBD  look at field specs from Game Manual
        case 4:
            return 0.0_m; // TBD TBD  look at field specs from Game Manual
        case 5:
            return 0.0_m; // TBD TBD  look at field specs from Game Manual
        case 6:
            return 0.0_m; // TBD TBD  look at field specs from Game Manual
        case 7:
            return 0.0_m; // TBD TBD  look at field specs from Game Manual
        case 8:
            return 0.0_m; // TBD TBD  look at field specs from Game Manual
        case 9:
            return 0.0_m; // TBD TBD  look at field specs from Game Manual
        case 10:
            return 0.0_m; // TBD TBD  look at field specs from Game Manual
        case 11:
            return 0.0_m; // TBD TBD  look at field specs from Game Manual
        case 12:
            return 0.0_m; // TBD TBD  look at field specs from Game Manual
        case 13:
            return 0.0_m; // TBD TBD  look at field specs from Game Manual
        case 14:
            return 0.0_m; // TBD TBD  look at field specs from Game Manual
        case 15:
            return 0.0_m; // TBD TBD  look at field specs from Game Manual
        case 16:
            return 0.0_m; // TBD TBD  look at field specs from Game Manual
    }
    return 0.0_m;
}

void VisionSub::InitNetworkTableData()
{
    std::string tableName = "photonvision";
    std::string topic = m_cameraName + "/targetYaw"; // why doesn't m_testCam.GetCameraName() work?
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
    Util::Log("netTable topic1 yaw", dbl, GetName());
    dbl = m_dblSub2.Get(-777.0);
    Util::Log("netTable topic2 yaw", dbl, GetName());
    dbl = m_dblSub3.Get(-888.0);
    Util::Log("netTable topic3 yaw", dbl, GetName());
    return dbl;
}
