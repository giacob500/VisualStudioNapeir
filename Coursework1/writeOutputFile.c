#include <stdio.h>
#include <string.h>
#include "writeOutputFile.h"

void writeOutputFile(char* inputFile, char* outputFile) {
	int write = 0;
	FILE* javaFile = fopen(inputFile, "r");
	FILE* textFile = fopen(outputFile, "w");
	char line[1000];
	char lineCopy[1000];
	while (fgets(line, 1000, javaFile) != NULL) {
		strcpy(lineCopy, line);
		char* delimiters = " .,\n";
		char* token = strtok(line, delimiters);
		// Loop to pass through the single words
		while (token != NULL) {
			// Check if the word equals to the start or the end of a comment
			if (strcmp(token, "/**") == 0) {
				write = 1;
			}
			else if (strcmp(token, "{") == 0 && write == 1) {
				fprintf(textFile, "%s\n", lineCopy);
				write = 0;
			}
			token = strtok(NULL, delimiters);
		}
		if (write == 1) {
			fprintf(textFile, "%s", lineCopy);
		}
	}
	fclose(javaFile);
	fclose(textFile);
}