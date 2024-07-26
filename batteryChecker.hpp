#ifndef BATTERY_CHECKER_HPP
#define BATTERY_CHECKER_HPP

#include <assert.h>
#include <iostream>
#include <string>

#include "batteryCheckerParams.hpp"

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
            bool inputInRange(float minValue, float maxValue, float inputValue, const std::string& valueType);
            bool inputInLowToleranceRange(float minValue, float maxValue, float inputValue, const std::string& valueType);
            bool inputInHighToleranceRange(float minValue, float maxValue, float inputValue, const std::string& valueType);
    };
}
#endif //BATTERY_CHECKER_HPP