//Author: Simon Powers
//Class to represent a Module

#pragma once
#include <string>
#include "Lecturer.h"

class Module
{
    public:
        //Constructor
        //Params: The name, address and office
        Module(const std::string &name, const Lecturer *lecturer);

        //Returns the name of the module
        std::string get_name() const;

        //Returns a const pointer to the lecturer
        const Lecturer* get_lecturer() const;

        //Sets the name of the module
        //Params: the name
        void set_name(const std::string &name);

        //Sets the lecturer
        //Params: a const pointer to the lecturer
        void set_lecturer(const Lecturer *lecturer);

    private:
        std::string name;
        const Lecturer *lecturer; 
};