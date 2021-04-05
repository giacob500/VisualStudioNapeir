#include <iostream>

using namespace std;

class animal
{
	public:
};

class mammal : public animal
{
	public:
};

class horse : public mammal
{
	public:
};

class bird : public mammal
{
	public:
};

class pegasus : public horse, public bird
{
public:
	pegasus()
	{
		cout << " Called pegasus constructor " << endl;
	}
	~pegasus() {
		cout << " Called pegasus destructor " << endl;
	}
};