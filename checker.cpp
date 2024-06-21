#include <assert.h>
#include <iostream>
#include "checker.hpp"
using namespace std;

// Check each Parameter Individually
bool BatteryManagementSystem::checkTemperatureOk(float temperature)
{
  float minTemperature = 0;
  float maxTemperature = 45;
  float currentTemperature = temperature;
  return inputInRange(minTemperature, maxTemperature, currentTemperature);
}

bool BatteryManagementSystem::checkSocOk(float soc)
{
  float minSoc = 20;
  float maxSoc = 80;
  float currentSoc = soc;
  return inputInRange(minSoc, maxSoc, currentSoc);
}

bool BatteryManagementSystem::checkChargeRateOk(float chargeRate)
{
  float minCharge = 0.1;
  float MaxCharge = 0.8;
  float currentCharge = chargeRate;
  return inputInRange(minCharge, MaxCharge, currentCharge);
}

bool BatteryManagementSystem::inputInRange(float minValue, float maxValue, float inputValue)
{
  if (inputValue > minValue && inputValue < maxValue)
  {
    return true;
  }
  else
  {
    print("%f Value out of range!", inputValue);
    return false;
  }
}

bool BatteryManagementSystem::batteryIsOk(float temperature, float soc, float chargeRate) {

  temperatureOk = BatteryManagementSystem::checkTemperatureOk(temperature);
  stateOfChargeOk = BatteryManagementSystem::checkSocOk(state_of_charge);
  chargeInRange = BatteryManagementSystem::checkChargeRateOk(charge_rate);

  return temperatureOk && stateOfChargeOk && chargeInRange;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
