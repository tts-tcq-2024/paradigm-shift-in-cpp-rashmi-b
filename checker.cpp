#include <assert.h>
#include <iostream>
#include "checker.hpp"
using namespace std;

/* Check each Parameter Individually */
/* Check temperature is within range */
bool BatteryManagementSystem::checkTemperatureOk(float temperature)
{
  float minTemperature = 0;
  float maxTemperature = 45;
  float currentTemperature = temperature;
  return inputInRangeWithTolerance(minTemperature, maxTemperature, currentTemperature, "temperature");
}

bool BatteryManagementSystem::checkSocOk(float state_of_charge)
{
  float minSoc = 20;
  float maxSoc = 80;
  float currentSoc = state_of_charge;
  return inputInRangeWithTolerance(minSoc, maxSoc, currentSoc, "state_of_charge");
}

bool BatteryManagementSystem::checkChargeRateOk(float charge_rate)
{
  float minCharge = 0.1;
  float MaxCharge = 0.8;
  float currentCharge = charge_rate;
  return inputInRangeWithTolerance(minCharge, MaxCharge, currentCharge, "charge_rate");
}

void BatteryManagementSystem::printErrorMessage(const std::string& valueType)
{
  std::string valueTypename = valueType;
  std::cout << "Error: Parameter" << valueType << "Not in Range! Please check.";
}

void BatteryManagementSystem::printWarnMessage(const std::string& valueType)
{
  std::string valueTypename = valueType;
  std::cout << "WARNING: Parameter" << valueType << "is in border range.";
}

bool BatteryManagementSystem::inputInRangeWithTolerance(float minValue, float maxValue, float inputValue, const std::string&  valueType)
{
  float minTolerance = (minValue * 5) / 100;
  float maxTolerance = (maxValue * 5) / 100;
  if (inputValue > minValue && inputValue < maxValue)
  {
    // Now check with tolerance
    if ((inputValue > minValue && inputValue < (minValue + minTolerance)) || (inputValue >= (maxValue - maxTolerance) && inputValue <= maxValue))
    {
      printWarnMessage(valueType);
      return true;
    }
    else 
    {
      printErrorMessage(valueType);
      return false;
    }
  }
  else
  {
    printErrorMessage(valueType);
    return false;
  }
}

/* Is battery OK Takes temperature, state of charge and charge rate as inputs */ 
bool BatteryManagementSystem::batteryIsOk(float temperature, float state_of_charge, float charge_rate)
{

  temperatureOk = BatteryManagementSystem::checkTemperatureOk(temperature);
  stateOfChargeOk = BatteryManagementSystem::checkSocOk(state_of_charge);
  chargeRateOk = BatteryManagementSystem::checkChargeRateOk(charge_rate);

  return temperatureOk && stateOfChargeOk && chargeRateOk;
}
