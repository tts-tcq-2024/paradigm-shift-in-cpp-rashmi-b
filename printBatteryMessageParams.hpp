#ifndef PRINT_BATTERY_MESSAGE_PARAMS_HPP
#define PRINT_BATTERY_MESSAGE_PARAMS_HPP

#include <vector>
#include <string>

namespace BMS 
{
	enum LANGUAGE_OPTION : int 
    {
        ENGLISH = 0,
        GERMAN = 1
    };

	static std::vector<std::vector<std::string>> console_messages = { { "OK.", "OK."},
														{ "WARNING: Parameter is in border range.", "WARNUNG: Parameter liegt im Grenzbereich."},
														{ "ERROR: Not in Range! Please check.", "FEHLER: Nicht in Reichweite! Überprüfen Sie bitte."}
													  };
}
#endif // #define PRINT_BATTERY_MESSAGE_PARAMS_HPP
