#include "checker.hpp"

int main()
{
  BMS::BatteryManagementSystem BMS;
  assert(BMS.batteryIsOk(25, 70, 0.7) == true);
  assert(BMS.batteryIsOk(50, 85, 0) == false);
  assert(BMS.batteryIsOk(30, 70, 0.1) == true);
  assert(BMS.batteryIsOk(30, 70, 0.9) == false);
  assert(BMS.batteryIsOk(1, 70, 0.7) == true);
  assert(BMS.batteryIsOk(25, 78, 0.7) == true);
  assert(BMS.batteryIsOk(25, 70, 0.7) == true);
  assert(BMS.batteryIsOk(25, 70, 0.79) == true);
  return 0;
}