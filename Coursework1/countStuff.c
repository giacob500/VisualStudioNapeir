#include <stdio.h>
#include <string.h>
#include "countStuff.h"

void countStuff(char* inputFile) {
	int tokenCounter = 0;
	int lineCounter = 0;
	int nonblankCounter = 0;
	int commentStatus = 0;
	int commentCounter = 0;
	FILE* javaFile = fopen(inputFile, "r");
	char line[1000];
	int emptyLine = 0;
	while (fgets(line, 1000, javaFile) != NULL)
	{
		tokenCounter = 0;
		emptyLine = 0;
		lineCounter++;
		char* delimiters = " .,\t\n";
		char* token = strtok(line, delimiters);
		// Loop to pass through the single words
		while (token != NULL) {
			tokenCounter++;
			// Check if the word equals to the start or the end of a comment
			if (strcmp(token, "/**") == 0) {
				commentStatus = 1;
			}
			else if (strcmp(token, "*/") == 0 && commentStatus == 1) {
				commentStatus = 2;
			}
			token = strtok(NULL, delimiters);
		}
		if (tokenCounter > 0) {
			nonblankCounter++;
		}

		if (commentStatus == 2) {
			commentCounter++;
			commentStatus = 0;
		}
	}
	printf("Total number of lines: %d\n", lineCounter);
	printf("Number of non-blank lines: %d\n", nonblankCounter);
	printf("Number of Javadoc comments: %d\n", commentCounter);
	fclose(javaFile);
}