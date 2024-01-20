// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/VisionSub.h"

VisionSub::VisionSub() = default;

// This method will be called once per scheduler run
void VisionSub::Periodic() 
{
    //Initialize:
    m_targetSkew = 0.0;
    m_targetPitch = 0.0;
    m_targetYaw = 0.0;
    m_targetID = 0;
    m_targetArea = 0.0;

    static int heartBeat = 0;
    frc::SmartDashboard::PutNumber("VisionSubPeriodic HB", heartBeat++);

units::meter_t testTargDist = 0_in;
units::meter_t testTargDist2 = 0_in;

    photon::PhotonPipelineResult currentResult = m_testCam.GetLatestResult();
    bool seeTargets = currentResult.HasTargets();

    frc::SmartDashboard::PutBoolean("VisionSubPeriodic See Targets", seeTargets);

    //Check if Targets are Present:
    if(seeTargets == true)
    {
        //Get Total Targets Camera Sees:
        std::span<const photon::PhotonTrackedTarget, 4294967295U> targetArray = currentResult.GetTargets();

        unsigned int targetAmount = targetArray.size();

        frc::SmartDashboard::PutNumber("VisionSubPeriodic numTargets", targetAmount);

        //Find Requested Target:
        for(unsigned int i = 0; i < targetAmount; i++)
        {
            photon::PhotonTrackedTarget potentialTarget = targetArray[i];
            m_targetID = potentialTarget.GetFiducialId();

            if(m_targetID == 3)
            {
                potentialTarget.GetDetectedCorners();
                // wpi::SmallVector<std::pair<double, double>, 4> targetCorners = potentialTarget.GetDetectedCorners();
                // wpi::SmallVector<std::pair<double, double>, 4> targetMinAreaCorners = potentialtarget.GetMinAreaRectCorners();
                m_targetPitch = potentialTarget.GetPitch();
                m_targetSkew = potentialTarget.GetSkew(); 
                m_targetYaw = potentialTarget.GetYaw();
                m_targetArea = potentialTarget.GetArea();   
                m_targetDist = photon::PhotonUtils::CalculateDistanceToTarget
                (m_kCamHeight, m_kTargetHeight, m_kCamPitch, (units::degree_t)m_targetPitch);

//testTargDist = photon::PhotonUtils::CalculateDistanceToTarget (m_kCamHeight, 6.5_in, m_kCamPitch, (units::degree_t)m_targetPitch);

//testTargDist2 = photon::PhotonUtils::CalculateDistanceToTarget (m_kCamHeight, 6.75_in, m_kCamPitch, (units::degree_t)m_targetPitch);

            }
            else if (m_targetID == 4)
            {
                potentialTarget.GetDetectedCorners();
                // wpi::SmallVector<std::pair<double, double>, 4> targetCorners = potentialTarget.GetDetectedCorners();
                // wpi::SmallVector<std::pair<double, double>, 4> targetMinAreaCorners = potentialtarget.GetMinAreaRectCorners();
                m_targetPitch2 = potentialTarget.GetPitch();
                m_targetSkew2 = potentialTarget.GetSkew();
                m_targetYaw2 = potentialTarget.GetYaw();
                m_targetArea2 = potentialTarget.GetArea();   
            }

            char msg[250];
            char title[250];

            //msg = output/variable, and title = input.
            sprintf(msg, "VisionSubPeriodic target #%d ", i);

            sprintf(title, "%s target ID", msg);
            frc::SmartDashboard::PutNumber(title, m_targetID);

            sprintf(title, "%s target Requested", msg);
            frc::SmartDashboard::PutNumber(title, m_idRequested);

            sprintf(title, "%s target Skew", msg);
            frc::SmartDashboard::PutNumber(title, m_targetSkew);

            sprintf(title, "%s target Pitch", msg);
            frc::SmartDashboard::PutNumber(title, m_targetPitch);

            sprintf(title, "%s target Yaw", msg);
            frc::SmartDashboard::PutNumber(title, m_targetYaw);

            sprintf(title, "%s target Area", msg);
            frc::SmartDashboard::PutNumber(title, m_targetArea); 

            sprintf(title, "%s target Distance", msg);
            frc::SmartDashboard::PutNumber(title, (double)m_targetDist); 


            sprintf(title, "%s target 2 Skew", msg);
            frc::SmartDashboard::PutNumber(title, m_targetSkew2);
            
            sprintf(title, "%s target 2 Yaw", msg);
            frc::SmartDashboard::PutNumber(title, m_targetYaw2);

            sprintf(title, "%s target 2 Pitch", msg);
            frc::SmartDashboard::PutNumber(title, m_targetPitch2);

            sprintf(title, "%s target 2 Area", msg);
            frc::SmartDashboard::PutNumber(title, m_targetArea2); 

//sprintf(title, "%s test Distance", msg); frc::SmartDashboard::PutNumber(title, (double)testTargDist); 
//sprintf(title, "%s test Distance2", msg); frc::SmartDashboard::PutNumber(title, (double)testTargDist2); 

        }
    }

    //Display Target Data:
    frc::SmartDashboard::PutNumber("Request - Target ID", m_targetID);
    frc::SmartDashboard::PutNumber("Target Requested", m_idRequested);
    frc::SmartDashboard::PutNumber("Request - Target Skew", m_targetSkew);
    frc::SmartDashboard::PutNumber("Request - Target Pitch", m_targetPitch);
    frc::SmartDashboard::PutNumber("Request - Target Area", m_targetArea);
    frc::SmartDashboard::PutNumber("Request - Target Distance", (double)m_targetDist);  
}

void VisionSub::init() {} 

double VisionSub::getTargYaw(int id)
  {
//     photon::PhotonPipelineResult currentResult = m_testCam.GetLatestResult();
//     std::span<const photon::PhotonTrackedTarget, 4294967295U> targetArray = currentResult.GetTargets();
//     unsigned int getTargAmount = targetArray.size();

//     switch (id)
//     {
//         case 1:

//         case 2:

//         case 3:

//         case 4:

//         default:

//         return 0.0;
//     }
//   }
  
//   double VisionSub::getTargPitch(int id)
//   {

  }
  
  double VisionSub::getTargSkew(int id)
  {

  }
  
  double VisionSub::getTargArea(int id)
  {

  }

  double VisionSub::getTargDist(int id)
  {
    
  }
