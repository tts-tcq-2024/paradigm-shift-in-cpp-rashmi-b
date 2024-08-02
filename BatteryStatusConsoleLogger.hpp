#ifndef BATTERY_STATUS_CONSOLE_LOGGER
#define BATTERY_STATUS_CONSOLE_LOGGER

#include <assert.h>
#include <iostream>
#include <string>

#include "printBatteryMessageParams.hpp"
#include "IBatteryStatusLogger.hpp"

namespace BMS
{
    class BatteryStatusConsoleLogger:public IBatteryStatusLogger
    {
        public:
            void printOkMessage(const std::string& valueType, LANGUAGE_OPTION language_option) override;
            void printErrorMessage(const std::string& valueType, LANGUAGE_OPTION language_option) override;
            void printWarnMessage(const std::string& valueType, LANGUAGE_OPTION language_option) override;
    };
}
#endif //BATTERY_STATUS_CONSOLE_LOGGER
