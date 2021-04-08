//Author: Simon Powers
//Class to represent a Student

#pragma once
#include <vector>
#include "Module.h"

class Student : public Person
{
    public:
        //Constructor
        //Params: The name, address and matriculation number
        Student(const std::string &name, const std::string &address, 
                    unsigned int matric);

        //Returns the matriculation number of the student
        unsigned int get_matric() const;

        //Enrols the student on to a module
        //Params the module to be enrolled on to
        void add_module(const Module *module);

        //Returns a string containing the details of the student:
        //name, address, matric, and module enrollments
        std::string print_details() const;

    private:
        unsigned int matric;
        std::vector<const Module*> modules;

};