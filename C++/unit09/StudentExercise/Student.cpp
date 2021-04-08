//Author: Simon Powers
//Implementation of a Student

#include "Module.h"
#include "Student.h"

using namespace std;

//Constructor
//Params: The name, address and matriculation number
Student::Student(const string &name, const string &address, 
                    unsigned int matric)
{
    set_name(name);
    set_address(address);
    this->matric = matric;
}

//Returns the matriculation number of the student
unsigned int Student::get_matric() const
{
    return matric;
}

 //Enrols the student on to a module
//Params the module to be enrolled on to
void Student::add_module(const Module *module)
{
    modules.push_back(module);
}

//Returns a string containing the details of the student:
//name, address, matric, and module enrollments
string Student::print_details() const
{
    string ret = "Student\n";
    ret += Person::print_details();
    ret += "Matric: " + to_string(matric) + "\n";
    ret += "Modules:\n";
    for(auto m : modules)
    {
        ret += m->get_name() + "\n";
    }
    return ret;
}
