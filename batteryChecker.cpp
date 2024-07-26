#include <assert.h>
#include <iostream>
#include "batteryChecker.hpp"
#include "printBatteryMessage.hpp"

using namespace std;

BMS::PrintConsoleMessage consoleMessage;

/* Check each Parameter Individually */
bool BMS::BatteryManagementSystem::checkTemperatureOk(float temperature, bool checkTolerance)
{
  float currentTemperature = temperature;
  
  if (checkTolerance)
  {
    inputInLowToleranceRange(minTemperature, maxTemperature, currentTemperature, "temperature");
    inputInHighToleranceRange(minTemperature, maxTemperature, currentTemperature, "temperature");
  }
  
  return inputInRange(minTemperature, maxTemperature, currentTemperature, "temperature");
}

bool BMS::BatteryManagementSystem::checkSocOk(float state_of_charge, bool checkTolerance)
{
  float currentSoc = state_of_charge;
  
  if (checkTolerance)
  {
    inputInLowToleranceRange(minSoc, maxSoc, currentSoc, "state_of_charge");
    inputInHighToleranceRange(minSoc, maxSoc, currentSoc, "state_of_charge");
  }

  return inputInRange(minSoc, maxSoc, currentSoc, "state_of_charge");
}

bool BMS::BatteryManagementSystem::checkChargeRateOk(float charge_rate, bool checkTolerance)
{
  float currentCharge = charge_rate;

  if (checkTolerance)
  {
    inputInLowToleranceRange(minCharge, MaxCharge, currentCharge, "charge_rate");
    inputInHighToleranceRange(minCharge, MaxCharge, currentCharge, "charge_rate");
  }

  return inputInRange(minCharge, MaxCharge, currentCharge, "charge_rate");
}

bool BMS::BatteryManagementSystem::inputInRange(float minValue, float maxValue, float inputValue, const std::string& valueType)
{
  if (inputValue > minValue && inputValue < maxValue)
  {
    consoleMessage.printOkMessage(valueType, BMS::ENGLISH);
    return true;
  }
  else
  {
    consoleMessage.printErrorMessage(valueType, BMS::ENGLISH);
    return false;
  }
}

bool BMS::BatteryManagementSystem::inputInLowToleranceRange(float minValue, float maxValue, float inputValue, const std::string& valueType)
{
  float minTolerance = (minValue * 5) / 100;
  if (inputValue > minValue && inputValue < (minValue + minTolerance))
    {
      consoleMessage.printWarnMessage(valueType, BMS::ENGLISH);
      return true;
    }
    else 
    {
      consoleMessage.printErrorMessage(valueType, BMS::ENGLISH);
      return false;
    }
}

bool BMS::BatteryManagementSystem::inputInHighToleranceRange(float minValue, float maxValue, float inputValue, const std::string& valueType)
{
  float maxTolerance = (maxValue * 5) / 100;
  if (inputValue >= (maxValue - maxTolerance) && inputValue <= maxValue)
    {
      consoleMessage.printWarnMessage(valueType, BMS::ENGLISH);
      return true;
    }
    else 
    {
      consoleMessage.printErrorMessage(valueType, BMS::ENGLISH);
      return false;
    }
}

/* Is battery OK Takes temperature, state of charge and charge rate as inputs */ 
bool BMS::BatteryManagementSystem::batteryIsOk(float temperature, float state_of_charge, float charge_rate)
{
  // Pass parameter values with flag to check with tolerance or not
  temperatureOk = BMS::BatteryManagementSystem::checkTemperatureOk(temperature, true);
  stateOfChargeOk = BMS::BatteryManagementSystem::checkSocOk(state_of_charge, true);
  chargeRateOk = BMS::BatteryManagementSystem::checkChargeRateOk(charge_rate, false);

  return temperatureOk && stateOfChargeOk && chargeRateOk;
}
