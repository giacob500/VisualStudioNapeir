//Author: Simon Powers
//Implementation of a Module
#include "Module.h"

using namespace std;

Module::Module(const string &name, const Lecturer *lecturer)
{
    this->name = name;
    this->lecturer = lecturer;
}

string Module::get_name() const
{
    return name;
}

const Lecturer* Module::get_lecturer() const
{
    return lecturer;    
}

void Module::set_name(const string &name)
{
    this->name = name;
}

void Module::set_lecturer(const Lecturer *lecturer)
{
    this->lecturer = lecturer;
}