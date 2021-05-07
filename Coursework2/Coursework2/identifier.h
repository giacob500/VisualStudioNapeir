// Author: Giacomo Lorenzi
// A struct to store identifier attributes

#pragma once

#include <string>

struct identifier
{
    std::string identifierName;
    int lineNumber;
    std::string whatIs;
    std::string identifierType;
    int timesReferenced;
};