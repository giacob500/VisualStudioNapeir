#include <stdio.h>
#include <string.h>
#include "writeOutputFile.h"

// Function to write informations readed from a given input java file ("inputFile") into a specified output file ("outputFile")
void writeOutputFile(char* inputFile, char* outputFile)
{
	int write = 0;
	char line[1000];
	char lineCopy[1000];
	FILE* javaFile = fopen(inputFile, "r");
	FILE* textFile = fopen(outputFile, "w");

	// Loop input file line by line
	while (fgets(line, 1000, javaFile) != NULL)
	{
		strcpy(lineCopy, line);
		char* delimiters = " .,\n";
		char* token = strtok(line, delimiters);
		// Loop line word by word
		while (token != NULL)
		{
			// Check if the word equals to the start or the end of a javadoc comment
			if (strcmp(token, "/**") == 0)
			{
				write = 1;
			}
			else if (strcmp(token, "{") == 0 && write == 1)
			{
				// Write he entire line on output file and stop until next javadoc comment
				fprintf(textFile, "%s\n", lineCopy);
				write = 0;
			}
			token = strtok(NULL, delimiters);
		}
		// If javadoc comment is opened write the entire line on output file
		if (write == 1)
		{
			fprintf(textFile, "%s", lineCopy);
		}
	}

	// Close files
	fclose(javaFile);
	fclose(textFile);
}