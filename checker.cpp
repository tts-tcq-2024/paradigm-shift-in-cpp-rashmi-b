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
  return inputInRange(minTemperature, maxTemperature, currentTemperature, "temperature");
}

bool BatteryManagementSystem::checkSocOk(float state_of_charge)
{
  float minSoc = 20;
  float maxSoc = 80;
  float currentSoc = state_of_charge;
  return inputInRange(minSoc, maxSoc, currentSoc, "state_of_charge");
}

bool BatteryManagementSystem::checkChargeRateOk(float charge_rate)
{
  float minCharge = 0.1;
  float MaxCharge = 0.8;
  float currentCharge = charge_rate;
  return inputInRange(minCharge, MaxCharge, currentCharge, "charge_rate");
}

bool BatteryManagementSystem::printOutput(bool result, const std::string& valueType)
{
  bool inRange = result;
  string valueType = valueType;
  if (inRange)
  {
    printf("%f Value of %s is in range", inputValue, valueType.c_str());
  }
  else
  {
    printf("%f Value of %s is not in range! Please check", inputValue, valueType.c_str());
  }
}

bool BatteryManagementSystem::inputInRange(float minValue, float maxValue, float inputValue, const std::string&  valueType)
{
  string valueType = valuetype;
  if (inputValue > minValue && inputValue < maxValue)
  {
    printOutput(true, valueType);
    return true;
  }
  else
  {
    printOutput(false, valueType);
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

int main()
{
  BatteryManagementSystem BMS;
  assert(BMS.batteryIsOk(25, 70, 0.7) == true);
  assert(BMS.batteryIsOk(50, 85, 0) == false);
}
