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
	// flags
	int saveNextToken = 0;
	int author = 0;
	int param = 0;
	int retrn = 0;
	int clas = 0;


	char info[100] = "";
	char saveForLater[100] = "";
	//memset(info, 0, 100);
	printf("%s\n", info);
	FILE* javaFile = fopen(inputFile, "r");
	char line[1000];
	while (fgets(line, 1000, javaFile) != NULL) {
		char* delimiters = " .,;\n";
		char* token = strtok(line, delimiters);
		// Loop to pass through the single words
		while (token != NULL) {
			if (!strcmp(token, "*/") || !strcmp(token, "{")) {
				printf("\n");
				saveNextToken = 0;
				author = 0;
				clas = 0;
			}

			if (author == 1) {
				strcat(saveForLater, token);
				strcat(saveForLater, " ");
			}
			else if (clas == 1) {
				printf("Class: %s\n", token);
				printf("Author: %s\n", saveForLater);

			}

			else if (saveNextToken == 1) {
				printf("%s ", token);
			}
			else if (!strcmp(token, "@return")) {
				printf("Rtuerns: ");
				saveNextToken = 1;
			}
			else if (!strcmp(token, "@param")) {
				printf("Parameter: ");
				saveNextToken = 1;
			}

			else if (!strcmp(token, "@author")) {
				author = 1;
			}
			else if (!strcmp(token, "class")) {
				clas = 1;
			}
			
			//check if it is a method


			token = strtok(NULL, delimiters);
		}
	}
	printf("%s\n", info);
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
		if (!strcmp(argv[1], "-i") && !strcmp(argv[3], "-o")) {
			if (strstr(argv[2], ".java") != NULL) {
				char* inputFile = argv[2];
				char* outputFile = argv[4];
				writeOutputFile(inputFile, outputFile);
				promptInfos(inputFile);
				countStuff(inputFile);
			}
			else {
				printf("Error: input file is not a java file\n");
			}
		}
		else {
			printf("Error: incorrect parameter syntax or order\n");
		}
	}
	else {
		printf("Error: number of parameters inserted not sufficent\n");
	}

	return 0;
}