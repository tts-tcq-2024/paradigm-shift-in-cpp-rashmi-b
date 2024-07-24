#ifndef CHECKER_PARAMS_HPP
#define CHECKER_PARAMS_HPP

#include <vector>
#include <string>
#include <iostream>
#include <map>

namespace BMS 
{
	static float minTemperature = 0;
	static float maxTemperature = 45;
	static float minSoc = 20;
	static float maxSoc = 80;
	static float minCharge = 0.1;
	static float MaxCharge = 0.8;

	enum LANGUAGE_OPTION : int 
    {
        ENGLISH = 0,
        GERMAN = 1
    };

	static std::vector<std::vector<std::string>> message = { { "OK.", "OK."},
														{ "WARNING: Parameter is in border range.", "WARNUNG: Parameter liegt im Grenzbereich."},
														{ "ERROR: Not in Range! Please check.", "FEHLER: Nicht in Reichweite! Überprüfen Sie bitte."}
													  };
}
#endif // CHECKER_PARAMS_HPP