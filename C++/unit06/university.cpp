#include <iostream>
#include <string>

using namespace std;

struct programme
{
	string code;
	string name;

	programme() {
		cout << "Called programme default constructor" << endl;
	}
	programme(const string& code, const string& name)
	{
		cout << "Called programme parametrised constructor" << endl;
		this -> code = code;
		this -> name = name;
	}
};

struct module {
	string code;
	string name;
	unsigned char mark;
	module() {
		cout << "Called module default constructor" << endl;
	}
	module(const string& code, const string& name, unsigned int mark) {
		cout << "Called module parametrised constructor" << endl;
		this -> code = code;
		this -> name = name;
		this -> name = mark;	
	}
};

struct student {
	unsigned int matric;
	string name;
	string address;
	programme prog;
	module mods[6];

	student()
	{
		cout << "Called student default constructor" << endl;
	}
};

int main(int argc, char** argv)
{
	cout << "Creating a student object " << endl;
	student s;
	cout << "Setting student details " << endl;
	s.matric = 42001290;
	s.name = "Kevin Chalmers ";
	s.address = "School of Computing";

	cout << "Setting programme " << endl;
	s.prog = programme("56119 BH", "BEng (Hons) Software Engineering");

	cout << "Setting module 0" << endl;
	s.mods[0] = module("SET07109", "Programming Fundamentals", 85);

	cout << "Setting module 1" << endl;
	s.mods[1] = module("SET07108", "Human Computer Interaction", 70);

	cout << "Setting module 2" << endl;
	s.mods[1] = module("SET07105", "Filosofia", 90);

	// Average is not resulting the correct number beacuse not every module have been added to the list (total:6, added: 3)

	int averageMark = 0;

	for (int i = 0; i < 6; i++) {
		averageMark += s.mods[i].mark;
	}
	
	averageMark /= 6;

	cout << "Average mark: " << averageMark << endl;

	return 0;
}