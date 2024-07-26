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
    if(inputInLowToleranceRange(minTemperature, maxTemperature, currentTemperature))
    {
      consoleMessage.printWarnMessage("temperature", BMS::ENGLISH);
      return true;
    }
    else if(inputInHighToleranceRange(minTemperature, maxTemperature, currentTemperature))
    {
      consoleMessage.printWarnMessage("temperature", BMS::ENGLISH);
      return true;
    }
    else
    {
      consoleMessage.printErrorMessage("temperature", BMS::ENGLISH);
      return false;
    }
  }
  
  if(inputInRange(minTemperature, maxTemperature, currentTemperature))
  {
    consoleMessage.printOkMessage("temperature", BMS::ENGLISH);
    return true;
  }
  else
  {
    consoleMessage.printErrorMessage("temperature", BMS::ENGLISH);
    return false;
  }
}

bool BMS::BatteryManagementSystem::checkSocOk(float state_of_charge, bool checkTolerance)
{
  float currentSoc = state_of_charge;
  
  if (checkTolerance)
  {
    if(inputInLowToleranceRange(minSoc, maxSoc, currentSoc))
    {
      consoleMessage.printWarnMessage("state_of_charge", BMS::ENGLISH);
      return true;
    }
    else if(inputInHighToleranceRange(minSoc, maxSoc, currentSoc))
    {
      consoleMessage.printWarnMessage("state_of_charge", BMS::ENGLISH);
      return true;
    }
    else
    {
      consoleMessage.printErrorMessage("state_of_charge", BMS::ENGLISH);
      return false;
    }
  }

  if(inputInRange(minSoc, maxSoc, currentSoc))
  {
    consoleMessage.printOkMessage("state_of_charge", BMS::ENGLISH);
    return true;
  }
  else
  {
    consoleMessage.printErrorMessage("state_of_charge", BMS::ENGLISH);
    return false;
  }

}

bool BMS::BatteryManagementSystem::checkChargeRateOk(float charge_rate, bool checkTolerance)
{
  float currentCharge = charge_rate;

  if (checkTolerance)
  {
    if(inputInLowToleranceRange(minCharge, MaxCharge, currentCharge) ||
    inputInHighToleranceRange(minCharge, MaxCharge, currentCharge))
    {
      consoleMessage.printWarnMessage("charge_rate", BMS::ENGLISH);
      return true;
    }
    else
    {
      consoleMessage.printErrorMessage("charge_rate", BMS::ENGLISH);
      return false;
    }
  }

  if(inputInRange(minCharge, MaxCharge, currentCharge))
  {
    consoleMessage.printOkMessage("charge_rate", BMS::ENGLISH);
    return true;
  }
  else
  {
    consoleMessage.printErrorMessage("charge_rate", BMS::ENGLISH);
    return false;
  }
}

bool BMS::BatteryManagementSystem::inputInRange(float minValue, float maxValue, float inputValue)
{
  if (inputValue > minValue && inputValue < maxValue)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool BMS::BatteryManagementSystem::inputInLowToleranceRange(float minValue, float maxValue, float inputValue)
{
  float minTolerance = (minValue * 5) / 100;
  if (inputValue > minValue && inputValue < (minValue + minTolerance))
    {
      return true;
    }
    else 
    {
      return false;
    }
}

bool BMS::BatteryManagementSystem::inputInHighToleranceRange(float minValue, float maxValue, float inputValue)
{
  float maxTolerance = (maxValue * 5) / 100;
  if (inputValue >= (maxValue - maxTolerance) && inputValue <= maxValue)
    {
      return true;
    }
    else 
    {
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
