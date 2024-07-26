#include <assert.h>
#include <iostream>
#include "printBatteryMessage.hpp"

using namespace std;

void BMS::PrintConsoleMessage::printOkMessage(const std::string& valueType, LANGUAGE_OPTION language_option)
{
  std::string valueTypename = valueType;
  std::cout << valueType << BMS::console_messages[0][language_option];
}

void BMS::PrintConsoleMessage::printWarnMessage(const std::string& valueType, LANGUAGE_OPTION language_option)
{
  std::string valueTypename = valueType;
  std::cout << valueType << BMS::console_messages[1][language_option];
}

void BMS::PrintConsoleMessage::printErrorMessage(const std::string& valueType, LANGUAGE_OPTION language_option)
{
  std::string valueTypename = valueType;
  std::cout << valueType << BMS::console_messages[2][language_option];
}