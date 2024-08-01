#include "batteryChecker.hpp"
class BatteryStatusLoggerMock:public IBatteryStatusLogger{

  public:
      //void printOkMe....
      //void ...
};

void test_cases(){
BatteryStatusLoggerMock fakeLogger;
  BMS::BatteryManagementSystem codeUnderTest { &fakeLogger};
}

int main()
{
  BatteryStatusConsoleLogger consoleLogger;
  BMS::BatteryManagementSystem BMS { &consoleLogger};
  assert(BMS.batteryIsOk(25, 70, 0.7) == true);
  assert(BMS.batteryIsOk(50, 85, 0) == false);
  assert(BMS.batteryIsOk(30, 70, 0.1) == false);
  assert(BMS.batteryIsOk(30, 70, 0.9) == false);
  assert(BMS.batteryIsOk(1, 70, 0.7) == true);
  assert(BMS.batteryIsOk(25, 78, 0.7) == true);
  assert(BMS.batteryIsOk(15, 50, 0.79) == true);
  return 0;
}
