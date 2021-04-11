#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

/*
// Needed variables - SECOND PART
	string identifierName;
	int lineNumber = 1;
	string identifierType;
	int identifierReferenced = 0;
*/
struct identifier {
	string identifierName;
	int lineNumber = 0;
	string whatIs;
	string identifierType;
	int timesReferenced = 0;
};

void infoToConsole(vector<vector<string>> lines)
{
	// Determine all possible types a variable could be
	vector<string> types{ "void", "char", "short", "int", "long", "long long", "float", "double",
							"char*", "short*", "int*", "long*", "long long*", "float*", "double*" };

	// Counters - FIRST PART
	int variables = 0;
	int functions = 0;
	int ifstatements = 0;
	int whileloops = 0;
	int forloops = 0;

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

void writeOutputFile(vector<vector<string>> lines)
{
	int line = 0;
	int arrayFound = 0;
	vector<identifier> identifiers;
	// Determine all possible types a variable could be
	vector<string> types{ "void", "char", "short", "int", "long", "long long", "float", "double",
							"char*", "short*", "int*", "long*", "long long*", "float*", "double*" };

	for (int i = 0; i < lines.size(); i++)
	{
		identifier row;
		row.lineNumber = i + 1; // Track line number of identifier declaration
		for (int j = 0; j < lines[i].size(); j++)
		{
			// Increse references if token matches identifier name
			for (int g = 0; g < identifiers.size(); g++) {
				size_t bracketPosition = identifiers[g].identifierName.find("(");
				if (lines[i][j] == identifiers[g].identifierName) {
					identifiers[g].timesReferenced++;
				}
				// If a variable is a function parameter first clean it, then compare it
				else if (bracketPosition != string::npos && lines[i][j] == identifiers[g].identifierName.substr(0, bracketPosition - 1)) {
					//int where = identifiers[g].identifierName.size() - pos;
					//string diocan = identifiers[g].identifierName.substr(0, pos-1);					
					identifiers[g].timesReferenced++;
				}
			}
			// Recognise struct
			if (j < lines[i].size() - 1 && lines[i][j] == "struct") {
				types.push_back(lines[i][j + 1]);
			}
			// Recognise functions or variables
			for (string type : types) {
				if (lines[i].size() >= 3 && lines[i][0] == type) {
					if (lines[i][2] == "(") {
						row.whatIs = "function";
						row.identifierName = lines[i][1];
					}
					else
						row.whatIs = "variable";
					row.identifierType = type;
				}
			}
			// Recognizing if a variable is an array or not
			if (row.whatIs == "variable") {
				for (int g = 0; g < lines[i][j].size(); g++) {
					if (lines[i][j][g] == '[') {
						arrayFound = 1;
					}
					else if (arrayFound == 1 && lines[i][j][g] == ']') {
						arrayFound = 2;
					}
				}
				
				// PROBLEM WITH CHAR [] -----------------
				if (lines[i][2][0] == '[' && lines[i][2][lines[i][2].size() - 1] == ']') {
					arrayFound = 2;
				}
				if (arrayFound == 2) {
					row.whatIs = "array";
					row.identifierType += " []";
					arrayFound = 0;
					size_t pos = lines[i][j].find("[");      // position of "[" in token
					if (pos == string::npos) {
						row.identifierName = lines[i][1];
					}
					else {
						string varName = lines[i][j].substr(0, pos);     // get from 0 to "[" the end
						row.identifierName = varName;
					}
				}
				else if (lines[i].size() >= 3) {
					row.identifierName = lines[i][1];
				}
				cout << row.identifierType << "\n";
			}
		}
		
		// Recognise for, where, if
		if (lines[i].size() >= 14 &&
			lines[i][0] == "for" &&
			lines[i][1] == "(" && lines[i][lines[i].size() - 1] == ")") {
			row.whatIs = "variable";
			row.identifierType = lines[i][2];
			row.identifierName = lines[i][3];
			for (int j = 4; j < lines[i].size() - 1; j++) {
				if (lines[i][j] == row.identifierName) {
					row.timesReferenced++;
				}
			}
		}

		

		// Delete empty lines (to add at the check below)
	/*
		if (identifiers[i].identifierName == "" &&
			identifiers[i].identifierType == "" &&
			identifiers[i].whatIs == "" &&
			identifiers[i].lineNumber == 0 &&
			identifiers[i].timesReferenced == 0) {
			auto ciao = identifiers.begin() + i;
			identifiers.erase(identifiers.begin() + i);
		}
	}*/
	// If identifier values are empty, don't add it to its vector
		if (row.whatIs != "")
			identifiers.push_back(row);

		if (row.whatIs == "function") {
			if (lines[i][lines[i].size() - 2] != "(" && lines[i][lines[i].size() - 1] == ")") {
				// Found! This is a function with parameters
				//cout << row.identifierName << endl;
				identifier row1;
				row1.whatIs = "variable";
				row1.lineNumber = i + 1;
				//bool openBracket = false;
				for (int j = 3; j < lines[i].size() - 1; j++) {
					if (lines[i][j] != ",") {
						for (string type : types) {
							if (lines[i][j] == type) {
								row1.identifierType = type;
							}
							else {
								row1.identifierName = lines[i][j] + " (" + lines[i][1] + ")";
							}
						}
						if (row1.identifierType != lines[i][j]) {
							identifiers.push_back(row1);
						}
					}
				}
				// identifiers.push_back(row1); was here
			}
		}
	}

	// Writing on output file
	ofstream outputFile("identifiers.txt");

	for (int i = 0; i < identifiers.size(); i++) {
		outputFile << identifiers[i].identifierName << ", " <<
			"line " << identifiers[i].lineNumber << ", " <<
			identifiers[i].whatIs << ", " <<
			identifiers[i].identifierType << ", " <<
			"referenced " << identifiers[i].timesReferenced << "\n";
	}
	outputFile.close();
}

int main(int argc, char** argv)
{
	bool alreadyLong = false;
	// Check if the correct number of parametres are given
	if (argc == 2)
	{
		// Check if the input file is a C file
		if (((string)argv[1]).find(".c") != string::npos)
		{
			vector<string> tokens;
			vector<vector<string>> lines;
			ifstream file("test_files/test4.c");
			string line;
			string token;
			while (getline(file, line))
			{
				stringstream stream(line);
				tokens.clear();
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
				lines.push_back(tokens);
				//tokens.push_back("\n");
			}
			file.close();
			// Call the functions needed by the program 
			infoToConsole(lines);
			writeOutputFile(lines);
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