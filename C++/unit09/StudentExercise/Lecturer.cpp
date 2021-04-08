//Author: Simon Powers
//Implementation of Lecturer
#include "Lecturer.h"

using namespace std;

 //Constructor
//Params: The name, address and office
Lecturer::Lecturer(const string &name, const string &address, const string &office)
{
    set_name(name);
    set_address(address);
    this->office = office;
}

//Returns the office of the lecturer
string Lecturer::get_office() const
{
    return office;
}

//Sets the office of the lecturer
//Params: The office
void Lecturer::set_office(const string &office)
{
    this->office = office;
}



