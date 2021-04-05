#include <stdio.h>
#include <string.h>
#include "writeOutputFile.h"
#include "promptInfos.h"
#include "countLinesComments.h"

/*
 * Giacomo Lorenzi
 * 
 * The program reads in a file of Java source code contained in a .java file, and
 * analyses the Javadoc comments within it
 */

int main(int argc, char** argv)
{
	char* inputFile;
	char* outputFile;

	// Check if the correct number of parametres are given
	if (argc == 5)
	{
		// Find the "-i" and "-o" parameters to get input and output file names
		for (int i = 0; i < argc; i++)
		{
			if (!strcmp(argv[i], "-i"))
			{
				// Check the input is a java file
				if (strstr(argv[i + 1], ".java") == NULL)
				{
					printf("Error: input file is not a java file\n");
					break;
				}
				else
				{
					inputFile = argv[i + 1];
				}
			}
			else if (!strcmp(argv[i], "-o"))
			{
				outputFile = argv[i + 1];
			}
		}
		// Call functions from other files
		writeOutputFile(inputFile, outputFile);
		promptInfos(inputFile);
		countLinesComments(inputFile);
	}
	else
	{
		printf("Error: incorrect number of given parameters\n");
	}
	return 0;
}