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
	// Vector to store the console message. Retrieve them using the above enum as index values.
	// E.g console_messages[1][BMS::ENGLISH] will get "WARNING: Parameter is in border range."
	static std::vector<std::vector<std::string>> console_messages = { { "OK.", "OK."},
														{ "WARNING: Parameter is in border range.", "WARNUNG: Parameter liegt im Grenzbereich."},
														{ "ERROR: Not in Range! Please check.", "FEHLER: Nicht in Reichweite! Überprüfen Sie bitte."}
													  };
}
#endif // #define PRINT_BATTERY_MESSAGE_PARAMS_HPP
