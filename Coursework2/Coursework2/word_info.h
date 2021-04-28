//Author: Simon Powers
//A struct to store a word together with its count

#pragma once

#include <string>

struct word_info
{
    std::string word; //The word;
    int count; //The number times the word occurs in the file
};