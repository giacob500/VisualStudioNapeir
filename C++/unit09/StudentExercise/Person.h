//Author: Simon Powers
//Class to represent a Person

#pragma once
#include <string>

class Person 
{
    public:
        //Returns the name
        std::string get_name() const;

        //Returns the address
        std::string get_address() const;

        //Returns a string containing the details of the person:
        //name and address
        std::string print_details() const;

        //Sets the name
        //Params: The name
        void set_name(const std::string &name);

        //Sets the address
        //Params: The address
        void set_address(const std::string &address);

    private:
        std::string name;
        std::string address;
};