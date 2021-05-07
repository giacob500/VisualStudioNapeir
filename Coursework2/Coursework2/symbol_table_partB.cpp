// Author: Giacomo Lorenzi
// Main file to form the program which using binary search tree analyze c files

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "identifier.h"
#include "BinaryTree.h"
#include "infotoconsole.h"
#include "typesvector.h"
#include "symbol_table_partB.h"
using namespace std;

// Function to output identifiers on console using binary search tree
void writeOutputFileUsingBST(vector<vector<string>> lines)
{
	int line = 0;
	int arrayFound = 0;
	bool mainStarted = false;
	bool insideMainFunction = false;
	string currentFunction = "";
	vector<string> scope;
	BinaryTree mytree;
	vector<string> types = typesVector();

	// For each line in the c file
	for (int i = 0; i < lines.size(); i++)
	{
		identifier row;
		row.timesReferenced = 0;
		row.lineNumber = i + 1; // Track line number where identifier is declared

		// For each word in the line
		for (int j = 0; j < lines[i].size(); j++)
		{
			mytree.update(lines[i][j], currentFunction);	// Check for identifiers references to update
			// Recognise struct
			if (j < lines[i].size() - 1 && lines[i][j] == "struct") {
				types.push_back(lines[i][j + 1]);
			}
			// Recognise functions or variables
			for (string type : types) {
				if (lines[i].size() >= 3 && lines[i][0] == type) {
					if (lines[i][2] == "(") {
						row.whatIs = "function";
						currentFunction = row.identifierName = lines[i][1];
						if (row.identifierName == "main") {
							insideMainFunction = true;
						}
					}
					else
						row.whatIs = "variable";
					row.identifierType = type;
				}
			}
			// Recognizing if a variable is an array or not
			if (row.whatIs == "variable") {
				if (lines[i][2][0] == '[' && lines[i][2][lines[i][2].size() - 1] == ']') {
					arrayFound = 2;
				}
				else {
					for (int g = 0; g < lines[i][j].size(); g++) {
						if (lines[i][j][g] == '[') {
							arrayFound = 1;
						}
						else if (arrayFound == 1 && lines[i][j][g] == ']') {
							arrayFound = 2;
						}
					}
				}
				if (arrayFound == 2) {
					row.whatIs = "array";
					row.identifierType += " []";
					arrayFound = 0;
					size_t pos = lines[i][j].find("[");      // Position of "[" in token
					if (pos == string::npos) {
						row.identifierName = lines[i][1];
					}
					else {
						string varName = lines[i][j].substr(0, pos);     // Get from 0 to "[" the end
						row.identifierName = varName;
					}
				}
				else if (lines[i].size() >= 3) {
					row.identifierName = lines[i][1];
				}
				if (insideMainFunction == false)
					row.identifierName += " (" + currentFunction + ")";
			}
			// Check if is inside main function
			if (insideMainFunction == true) {
				mainStarted = true;
				if (lines[i][j] == "{") {
					scope.push_back("{");
				}
				if (scope.size() > 0 && lines[i][j] == "}")
					scope.pop_back();
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

		// If identifier is empty, don't add it to identifiers vector
		if (row.identifierName != "") {
			mytree.insert(row);
		}

		// Check if function contains parameters
		if (row.whatIs == "function") {
			if (lines[i][lines[i].size() - 2] != "(" && lines[i][lines[i].size() - 1] == ")") {
				identifier row1;
				row1.whatIs = "variable";
				row1.lineNumber = i + 1;
				for (int j = 3; j < lines[i].size() - 1; j++) {
					// Check for multiple parameters
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
							row1.timesReferenced = 0;
							mytree.insert(row1);
						}
					}
				}
			}
		}
	}

	// Print BST (Binary Search Tree) to console
	cout<<"\nBinary tree in alphabetical order:"<<endl;
	mytree.print_tree();
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
			ifstream file("test_files/" + (string)argv[1]);
			string line;
			string token;

			// Tokenize input file
			while (getline(file, line))
			{
				stringstream stream(line);
				tokens.clear();
				while (stream >> token)
				{
					// Fix long long problem (recognise the long long type and consider it as a single word)
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
			}
			file.close();

			// Call the functions needed by the program
			infoToConsole(lines);
			writeOutputFileUsingBST(lines);
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