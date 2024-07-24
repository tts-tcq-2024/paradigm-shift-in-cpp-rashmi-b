#ifndef CHECKER_HPP
#define CHECKER_HPP

#include <assert.h>
#include <iostream>
#include <string>

#include "checker_params.hpp"

namespace BMS
{
    class BatteryManagementSystem
    {
        public:
            bool batteryIsOk(float temperature, float state_of_charge, float charge_rate);

        private:
            bool temperatureOk;
            bool stateOfChargeOk;
            bool chargeRateOk;

            bool checkTemperatureOk(float temperature);
            bool checkSocOk(float state_of_charge);
            bool checkChargeRateOk(float charge_rate);
            void printOkMessage(const std::string& valueType, LANGUAGE_OPTION language_option);
            void printErrorMessage(const std::string& valueType, LANGUAGE_OPTION language_option);
            void printWarnMessage(const std::string& valueType, LANGUAGE_OPTION language_option);
            bool inputInRange(float minValue, float maxValue, float inputValue, const std::string& valueType);
            bool inputInLowToleranceRange(float minValue, float maxValue, float inputValue, const std::string& valueType);
            bool inputInHighToleranceRange(float minValue, float maxValue, float inputValue, const std::string& valueType);
    };
}
#endif //CHECKER_HPP