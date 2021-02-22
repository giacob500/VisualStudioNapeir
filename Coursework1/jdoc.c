#include <stdio.h>
#include <string.h>

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

void promptInfos(char* inputFile) {
	int copyN = 0;
	int copyI = 0;
	char name[100];
	char info[100];
	FILE* javaFile = fopen(inputFile, "r");
	char line[1000];
	char lineCopy[1000];
	while (fgets(line, 1000, javaFile) != NULL) {
		strcpy(lineCopy, line);
		char* delimiters = " .,\n";
		char* token = strtok(line, delimiters);
		// Loop to pass through the single words
		while (token != NULL) {
			if (copyN == 2) {
				strcat(info, " ");
				strcat(info, token);
				strcat(info, "\n");
				copyN = 0;
			}
			if (copyN == 1) {
				strcat(info, token);
				copyN = 2;
			}
			if (strcmp(token, "class") == 0) {
				// Locate "author", "parameter" or "return" name based on substring location 
				copyN = 1;
			}
			if (strcmp(token, "@author") == 0) {
				// Locate "author", "parameter" or "return" name based on substring location 
				copyN = 1;
			}
			if (strcmp(token, "@param") == 0) {
				// Locate "author", "parameter" or "return" name based on substring location 
				copyN = 1;
			}
			if (strcmp(token, "@return") == 0) {
				// Locate "author", "parameter" or "return" name based on substring location 
				copyN = 1;
			}
			token = strtok(NULL, delimiters);
		}
		printf("%s\n", name);
		printf("%s\n", info);
	}
	fclose(javaFile);
}


void countStuff(char* inputFile) {
	int lineCounter = 0;
	int nonblankCounter = 0;
	int commentStatus = 0;
	int commentCounter = 0;
	FILE* javaFile = fopen(inputFile, "r");
	char line[1000];
	while (fgets(line, 1000, javaFile) != NULL)
	{
		lineCounter++;
		if (strcmp(line, "\n")) {
			nonblankCounter++;
		}
		char* delimiters = " .,\n";
		char* token = strtok(line, delimiters);
		// Loop to pass through the single words
		while (token != NULL) {
			// Check if the word equals to the start or the end of a comment
			if (strcmp(token, "/**") == 0) {
				commentStatus++;
			}
			else if (strcmp(token, "*/") == 0 && commentStatus == 1) {
				commentStatus++;
			}
			token = strtok(NULL, delimiters);
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

int main(int argc, char** argv)
{
	// If the parameters are all inserted go on
	if (argc == 5) {
		if (!strcmp(argv[1], "-i") || !strcmp(argv[3], "-o")) {
			char* inputFile = argv[2];
			char* outputFile = argv[4];
			writeOutputFile(inputFile, outputFile);
			promptInfos(inputFile);
			countStuff(inputFile);
		}
		else {
			printf("Error: incorrect parameter syntax");
		}
	}
	else {
		printf("Error: number of parameters inserted not sufficent\n");
	}
	
	return 0;
}