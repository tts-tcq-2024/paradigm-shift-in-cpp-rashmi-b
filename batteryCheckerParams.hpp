#ifndef BATTERY_CHECKER_PARAMS_HPP
#define BATTERY_CHECKER_PARAMS_HPP

#include <string>
#include <iostream>

namespace BMS 
{
	static float minTemperature = 0;
	static float maxTemperature = 45;
	static float minSoc = 20;
	static float maxSoc = 80;
	static float minCharge = 0.1;
	static float MaxCharge = 0.8;
}
#endif // #define BATTERY_CHECKER_PARAMS_HPP
