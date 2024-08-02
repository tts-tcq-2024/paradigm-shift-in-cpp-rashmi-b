//interface in c++
#include <assert.h>
#include <iostream>
#include <string>

#include "printBatteryMessageParams.hpp"

class IBatteryStatusLogger{
public:
            virtual void printOkMessage(const std::string& valueType, LANGUAGE_OPTION language_option)=0;
            virtual void printErrorMessage(const std::string& valueType, LANGUAGE_OPTION language_option)=0;
            virtual void printWarnMessage(const std::string& valueType, LANGUAGE_OPTION language_option)=0;
};
