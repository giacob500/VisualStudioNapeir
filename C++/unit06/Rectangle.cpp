#include <iostream>
using namespace std;

class Rectangle
{
private:
	double length;
	double width;

public:
	Rectangle();
	Rectangle(double, double);
	double get_area();
	double get_length();
	void set_length(double);
	double get_width();
	void set_width(double);
};

//Default constructor
Rectangle::Rectangle()
{
	length = 1;
	width = 1;
}

Rectangle::Rectangle(double l, double w)
{
	length = l;
	width = w;
}

double Rectangle::get_area()
{
	return length * width;
}

double Rectangle::get_length()
{
	return length;
}

void Rectangle::set_length(double l)
{
	if (l < 0)
	{
		cout << "Error: negative length" << endl;
	}
	else
	{
		length = l;
	}
}

double Rectangle::get_width()
{
	return width;
}

void Rectangle::set_width(double w)
{
	if (w < 0)
	{
		cout << "Error: negative width" << endl;
	}
	else
	{
		width = w;
	}
}

int main()
{
	return 0;
}
