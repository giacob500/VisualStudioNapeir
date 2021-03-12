#include <stdio.h>
#include <string.h>
#include "writeOutputFile.h"
#include "promptInfos.h"
#include "countStuff.h"

int main(int argc, char** argv)
{
	char* inputFile;
	char* outputFile;
	// If the parameters are all inserted go on
	if (argc == 5) {
		// get number of arguments typed in input
		for (int i = 0; i < argc; i++) {
			if (!strcmp(argv[i], "-i")) {
				if (strstr(argv[i + 1], ".java") == NULL) {
					printf("Error: input file is not a java file\n");
					break;
				}
				else {
					inputFile = argv[i + 1];
				}				
			}
			else if (!strcmp(argv[i], "-o")) {
				outputFile = argv[i + 1];
			}		
		}
		writeOutputFile(inputFile, outputFile);
		promptInfos(inputFile);
		countStuff(inputFile);			
	}
	else {
		printf("Error: insufficient number of given parameters\n");
	}  
	return 0;
}