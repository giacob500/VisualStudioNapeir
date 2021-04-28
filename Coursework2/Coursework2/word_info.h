//Author: Simon Powers
//A struct to store a word together with its count

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