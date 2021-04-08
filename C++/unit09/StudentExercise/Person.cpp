//Author: Simon Powers
//Implementation of a Person

#include "Person.h"
#include <string>

using namespace std;

//Returns the name
string Person::get_name() const
{
    return name;
}

//Returns the address
string Person::get_address() const
{
    return address;
}

//Returns a string containing the details of the person:
//name and address
string Person::print_details() const
{
    return "Name: " + name + "\n" + "Address: " + address + "\n";
}

 //Sets the name
//Params: The name
void Person::set_name(const string &name) 
{
    this->name = name;
}

//Sets the address
//Params: The address
void Person::set_address(const string &address) 
{
    this->address = address;
}