#include <assert.h>
#include <iostream>
#include "checker.hpp"
#include "checker_params.hpp"
using namespace std;

/* Check each Parameter Individually */
bool BMS::BatteryManagementSystem::checkTemperatureOk(float temperature)
{
  float currentTemperature = temperature;
  
  inputInLowToleranceRange(minTemperature, maxTemperature, currentTemperature, "temperature");
  inputInHighToleranceRange(minTemperature, maxTemperature, currentTemperature, "temperature");

  return inputInRange(minTemperature, maxTemperature, currentTemperature, "temperature");
}

bool BMS::BatteryManagementSystem::checkSocOk(float state_of_charge)
{
  float currentSoc = state_of_charge;

  inputInLowToleranceRange(minSoc, maxSoc, currentSoc, "state_of_charge");
  inputInHighToleranceRange(minSoc, maxSoc, currentSoc, "state_of_charge");

  return inputInRange(minSoc, maxSoc, currentSoc, "state_of_charge");

}

bool BMS::BatteryManagementSystem::checkChargeRateOk(float charge_rate)
{
  float currentCharge = charge_rate;

  inputInLowToleranceRange(minCharge, MaxCharge, currentCharge, "charge_rate");
  inputInHighToleranceRange(minCharge, MaxCharge, currentCharge, "charge_rate");

  return inputInRange(minCharge, MaxCharge, currentCharge, "charge_rate");
}

void BMS::BatteryManagementSystem::printOkMessage(const std::string& valueType)
{
  std::string valueTypename = valueType;
  std::cout << "OK: Parameter" << valueType << "in Range.";
}

void BMS::BatteryManagementSystem::printErrorMessage(const std::string& valueType)
{
  std::string valueTypename = valueType;
  std::cout << "Error: Parameter" << valueType << "Not in Range! Please check.";
}

void BMS::BatteryManagementSystem::printWarnMessage(const std::string& valueType)
{
  std::string valueTypename = valueType;
  std::cout << "WARNING: Parameter" << valueType << "is in border range.";
}

bool BMS::BatteryManagementSystem::inputInRange(float minValue, float maxValue, float inputValue, const std::string&  valueType)
{
  if (inputValue > minValue && inputValue < maxValue)
  {
    printOkMessage(valueType);
    return true;
  }
  else
  {
    printErrorMessage(valueType);
    return false;
  }
}

bool BMS::BatteryManagementSystem::inputInLowToleranceRange(float minValue, float maxValue, float inputValue, const std::string&  valueType)
{
  float minTolerance = (minValue * 5) / 100;
  if (inputValue > minValue && inputValue < (minValue + minTolerance))
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

bool BMS::BatteryManagementSystem::inputInHighToleranceRange(float minValue, float maxValue, float inputValue, const std::string&  valueType)
{
  float maxTolerance = (maxValue * 5) / 100;
  if (inputValue >= (maxValue - maxTolerance) && inputValue <= maxValue)
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

/* Is battery OK Takes temperature, state of charge and charge rate as inputs */ 
bool BMS::BatteryManagementSystem::batteryIsOk(float temperature, float state_of_charge, float charge_rate)
{

  temperatureOk = BMS::BatteryManagementSystem::checkTemperatureOk(temperature);
  stateOfChargeOk = BMS::BatteryManagementSystem::checkSocOk(state_of_charge);
  chargeRateOk = BMS::BatteryManagementSystem::checkChargeRateOk(charge_rate);

  return temperatureOk && stateOfChargeOk && chargeRateOk;
}
