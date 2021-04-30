#include <string>
#include <vector>
#include "typesvector.h"
using namespace std;

vector<string> infoToConsole() {
	vector<string> types{ "void", "char", "short", "int", "long", "long long", "float", "double",
								"char*", "short*", "int*", "long*", "long long*", "float*", "double*" };
	return types;
}