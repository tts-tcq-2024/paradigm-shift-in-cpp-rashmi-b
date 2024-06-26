#ifndef CHECKER_HPP
#define CHECKER_HPP

#include <assert.h>
#include <iostream>
#include <string>

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
        bool printOutput(bool result, const std::string& valueType);
        bool inputInRange(float minValue, float maxValue, float inputValue, const std::string& valueType);
    };

#endif //CHECKER_HPP