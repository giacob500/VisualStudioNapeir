// Author: Giacomo Lorenzi
// Function to return vector of types

#include <string>
#include <vector>
#include "typesvector.h"
using namespace std;

vector<string> typesVector() {
	vector<string> types{ "void", "char", "short", "int", "long", "long long", "float", "double",
								"char*", "short*", "int*", "long*", "long long*", "float*", "double*" };
	return types;
}