#ifndef PRINT_BATTERY_MESSAGE_HPP
#define PRINT_BATTERY_MESSAGE_HPP

#include <assert.h>
#include <iostream>
#include <string>

#include "printBatteryMessageParams.hpp"

namespace BMS
{
    class PrintConsoleMessage
    {
        public:
            void printOkMessage(const std::string& valueType, LANGUAGE_OPTION language_option);
            void printErrorMessage(const std::string& valueType, LANGUAGE_OPTION language_option);
            void printWarnMessage(const std::string& valueType, LANGUAGE_OPTION language_option);
    };
}
#endif //PRINT_BATTERY_MESSAGE_HPP