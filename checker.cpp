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

bool BatteryManagementSystem::checkSocOk(float state_of_charge)
{
  float minSoc = 20;
  float maxSoc = 80;
  float currentSoc = state_of_charge;
  return inputInRange(minSoc, maxSoc, currentSoc);
}

bool BatteryManagementSystem::checkChargeRateOk(float charge_rate)
{
  float minCharge = 0.1;
  float MaxCharge = 0.8;
  float currentCharge = charge_rate;
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
    printf("%f Value out of range!", inputValue);
    return false;
  }
}

bool BatteryManagementSystem::batteryIsOk(float temperature, float state_of_charge, float charge_rate) {

  temperatureOk = BatteryManagementSystem::checkTemperatureOk(temperature);
  stateOfChargeOk = BatteryManagementSystem::checkSocOk(state_of_charge);
  chargeRateOk = BatteryManagementSystem::checkChargeRateOk(charge_rate);

  return temperatureOk && stateOfChargeOk && chargeRateOk;
}

int main() {
  assert(BatteryManagementSystem::batteryIsOk(25, 70, 0.7) == true);
  assert(BatteryManagementSystem::batteryIsOk(50, 85, 0) == false);
}
