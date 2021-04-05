#include <stdio.h>
#include <string.h>
#include "countLinesComments.h"

// Function to count lines and javadoc comments in a given input java file ("inputFile")
void countLinesComments(char* inputFile)
{
	int emptyLine = 0;
	int tokenCounter = 0;
	int lineCounter = 0;
	int nonblankCounter = 0;
	int commentStatus = 0;
	int commentCounter = 0;
	char line[1000];
	FILE* javaFile = fopen(inputFile, "r");

	// Analyze input file line by line
	while (fgets(line, 1000, javaFile) != NULL)
	{
		tokenCounter = 0;
		emptyLine = 0;
		lineCounter++;
		char* delimiters = " .,\t\n";
		char* token = strtok(line, delimiters);
		// Analyze line word by word
		while (token != NULL)
		{
			tokenCounter++;
			// Check if the word equals to the start or the end of a javadoc comment
			if (strcmp(token, "/**") == 0)
			{
				commentStatus = 1;
			}
			else if (strcmp(token, "*/") == 0 && commentStatus == 1)
			{
				commentStatus = 2;
			}
			token = strtok(NULL, delimiters);
		}
		// If at least a token has been found on the current line increase non-blank counter
		if (tokenCounter > 0)
		{
			nonblankCounter++;
		}
		// If a javadoc comment has been found increase its counter
		if (commentStatus == 2)
		{
			commentCounter++;
			commentStatus = 0;
		}
	}
	// Print results to console
	printf("Total number of lines: %d\n", lineCounter);
	printf("Number of non-blank lines: %d\n", nonblankCounter);
	printf("Number of Javadoc comments: %d\n", commentCounter);

	// Close file
	fclose(javaFile);
}