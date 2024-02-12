/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc/Timer.h>
#include <wpi/SmallString.h>

#include "hal/DriverStation.h"

namespace Util
{
double Limit(double value, double lowerLimit = -1.0, double higherLimit = 1.0);
double AbsMin(double input, double minValue);
double AbsMax(double input, double maxValue);
double Abs(double input);

void DelayInSeconds(units::second_t seconds);

//Returns string of current time from year-month-day_hour-min-std::string
std::string TimeStampStr();

bool CompareDouble(double value, double requiredValue, double tolerance = 0.001);

//Log Functions
void Log(std::string title, double value, std::string subsystemName = "");
void Log(std::string title, int value, std::string subsystemName = "");
void Log(std::string title, unsigned int value, std::string subsystemName = "");
void Log(std::string title, bool value, std::string subsystemName = "");
void Log(std::string title, std::string value, std::string subsystemName = "");
void Log(std::string title, const char *value, std::string subsystemName = "");

//Experimental Functions
void SendErrorAndCode(const char* error, int32_t code);
// void SendErrorAndCode(const wpi::Twine &error, int32_t code, const char *location);

// Encoder Utils
double CalculateDistPerPulse(const double wheelDiameter, const int revPerPulse, const double gearRatio = 1.0);

//Other Constants
constexpr double ToInches = 0.393701;
constexpr double ToCM = 2.53;
constexpr double PI = 3.141592653589793238462643383279502884197169399375105820974944;
}