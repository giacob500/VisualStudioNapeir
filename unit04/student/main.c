#include "student.h"

int main(int argc, char** argv)
{
	struct student s;
	s.matric = 123456;
	s.name = "Kevin Chalmers";
	s.address = "Edinburgh Napier University";
	print_student(s);
	return 0;
}
