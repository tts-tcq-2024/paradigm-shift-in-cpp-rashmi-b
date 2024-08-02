#include <assert.h>
#include <iostream>
#include "BatteryStatusConsoleLogger.hpp"

using namespace std;

void BMS::BatteryStatusConsoleLogger::printOkMessage(const std::string& valueType, LANGUAGE_OPTION language_option)
{
  std::string valueTypename = valueType;
  std::cout << valueType << BMS::console_messages[0][language_option];
}

void BMS::BatteryStatusConsoleLogger::printWarnMessage(const std::string& valueType, LANGUAGE_OPTION language_option)
{
  std::string valueTypename = valueType;
  std::cout << valueType << BMS::console_messages[1][language_option];
}

void BMS::BatteryStatusConsoleLogger::printErrorMessage(const std::string& valueType, LANGUAGE_OPTION language_option)
{
  std::string valueTypename = valueType;
  std::cout << valueType << BMS::console_messages[2][language_option];
}
