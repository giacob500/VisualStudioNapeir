#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void infoToConsole(std::vector<string> tokens)
{
	// Determine all possible types a variable could be
	std::vector<string> types{ "void", "char", "short", "int", "long", "long long", "float", "double",
							"char*", "short*", "int*", "long*", "long long*", "float*", "double*" };

	// Flags

	// Counters
	int variables = 0;
	int functions = 0;
	int ifstatements = 0;
	int whileloops = 0;
	int forloops = 0;


	for (int i = 0; i < tokens.size(); i++) {

		// Recognize struct
		if (i < tokens.size() - 1 && tokens[i] == "struct") {
			types.push_back(tokens[i + 1]);
		}

		// Recognize variables & functions
		for (string type : types) {
			if (i < tokens.size() - 2 && tokens[i] == type) {
				if (tokens[i + 2] == "(")
					functions++;
				else
					variables++;
			}
		}

		// Recognize if statements, for and while loops
		if (i < tokens.size() - 1 && tokens[i + 1] == "(")
		{
			if (tokens[i] == "if")
				ifstatements++;
			else if (tokens[i] == "for")
				forloops++;
			else if (tokens[i] == "while")
				whileloops++;
		}
	}

	cout << "Variables: " << variables << endl;
	cout << "Functions: " << functions << endl;
	cout << "Functions: " << ifstatements << endl;
	cout << "Functions: " << forloops << endl;
	cout << "Functions: " << whileloops << endl;
}

int main(int argc, char** argv)
{
	bool alreadyLong = false;
	// Check if the correct number of parametres are given
	if (argc == 2)
	{
		// Check if the input file is a C file
		if (((string)argv[1]).find(".c") != std::string::npos)
		{
			std::vector<string> tokens;
			ifstream file("test_files/test4.c");
			string line;
			string token;
			while (getline(file, line))
			{
				stringstream stream(line);
				while (stream >> token)
				{
					// Fix long long problem (it is split by space)
					if (token == "long") {
						if (alreadyLong == false) {
							alreadyLong = true;
						}
						else if (alreadyLong == true) {
							tokens.push_back("long " + token);
							alreadyLong = false;
						}
					}
					else {
						if (alreadyLong == true) {
							tokens.push_back("long");
							tokens.push_back(token);
							alreadyLong = false;
						}
						else {
							tokens.push_back(token);
						}						
					}

				}
				tokens.push_back("\n");
			}

			file.close();
			// Call the functions needed by the program 
			infoToConsole(tokens);
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