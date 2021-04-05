#include <iostream>
#include <string>

using namespace std;

void myFunction() {
	cout << "I just got executed!" << endl;
}

int main(int argc, char** argv)
{
	// Check if the correct number of parametres are given
	if (argc == 2)
	{
		string str1 = argv[1];
		string str2 = ".c";
		cout << argv[1] << " " << str2 << " " << str1.find(str2) << endl;

		if (str1.find(str2) != std::string::npos)
		{
			myFunction();
		}
		else {
			cout << "Error: input file is not a C file" << endl;
			
		}
	}
	else
	{
		cout << "Error: incorrect number of given parameters" << endl;
	}

	return 0;
}