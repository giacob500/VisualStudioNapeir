//Author: Simon Powers
//A university records system

#include "Person.h"
#include "Module.h"
#include "Student.h"
#include "Lecturer.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    //Create Lecturers
    Lecturer *l1 = new Lecturer("Alex", "Merchiston", "C18");
    Lecturer *l2 = new Lecturer("Jane", "Craiglockhart", "C42");
    Lecturer *l3 = new Lecturer("John", "Sighthill", "D2");
    //Create Students
    Student *s1 = new Student("Kevin", "Edinburgh", 1234);
    Student *s2 = new Student("Neil", "Aberdeen", 1359);
    //Create Modules
    Module set07109("Programming Fundamentals", l1);
    Module set07106("Mathematics for Software Engineering", l2);
    Module imd07109("Human Computer interaction", l3);

    //Enrol students on to modules
    s1->add_module(&set07109);
    s1->add_module(&set07106);
    s2->add_module(&set07109);
    s2->add_module(&imd07109);

    //Create a vector to store the students and lecturers
    vector<Person*> people{l1,l2,l3,s1,s2};

    //Print the details of everyone in the system
    //Use the auto keyword
    for(auto p : people)
    {
        cout << p->print_details() << endl;
    }

    //Free the memory of the students and lecturers on the heap
    //Explictly specify the type of p: Person*
    for(Person *p : people)
    {
        delete p;
    }
    
    return 0;
}
