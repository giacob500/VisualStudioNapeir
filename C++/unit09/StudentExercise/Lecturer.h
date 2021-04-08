#pragma once
#include <string>
#include "Person.h"

class Lecturer : public Person
{
    public:
        //Constructor
        //Params: The name, address and office
        Lecturer(const std::string &name, const std::string &address, 
                    const std::string &office);

        //Returns the office of the lecturer
        std::string get_office() const;

        //Sets the office of the lecturer
        //Params: The office
        void set_office(const std::string &office);

    private:
        std::string office;
};