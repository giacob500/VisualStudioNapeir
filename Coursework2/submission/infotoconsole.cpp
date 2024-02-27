// Author: Giacomo Lorenzi
// Function to prompt informations about a c file to console

#include <iostream>
#include <string>
#include <vector>
#include "infotoconsole.h"
#include "typesvector.h"
using namespace std;

void infoToConsole(vector<vector<string>> lines)
{
	int variables = 0;
	int functions = 0;
	int ifstatements = 0;
	int whileloops = 0;
	int forloops = 0;
	vector<string> types = typesVector();

	for (int i = 0; i < lines.size(); i++) {
		for (int j = 0; j < lines[i].size(); j++)
		{
			// Recognise struct
			if (j < lines[i].size() - 1 && lines[i][j] == "struct") {
				types.push_back(lines[i][j + 1]);
			}
			// Recognise variables & functions
			for (string type : types) {
				if (j < lines[i].size() - 2 && lines[i][j] == type) {
					if (lines[i][j + 2] == "(") {
						functions++;
					}
					else {
						variables++;
					}
				}
			}
			// Recognise if statements, for and while loops
			if (j < lines[i].size() - 1 && lines[i][j + 1] == "(")
			{
				if (lines[i][j] == "if")
					ifstatements++;
				else if (lines[i][j] == "for")
					forloops++;
				else if (lines[i][j] == "while")
					whileloops++;
			}
		}
	}

	cout << "Variables: " << variables << endl;
	cout << "Functions: " << functions << endl;
	cout << "If statements: " << ifstatements << endl;
	cout << "For loops: " << forloops << endl;
	cout << "While loops: " << whileloops << endl;
}