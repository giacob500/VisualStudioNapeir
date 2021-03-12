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
	char objects[11][100] = {
						 {'i', 'n', 't', '\0'},
						 {'c', 'h', 'a', 'r', '\0'},
						 {'f', 'l', 'o', 'a', 't', '\0'},
						 {'d', 'o', 'u', 'b', 'l', 'e','\0'},
						 {'b', 'y', 't', 'e', '\0'},
						 {'s', 'h', 'o', 'r', 't', '\0'},
						 {'l', 'o', 'n', 'g', '\0'},
						 {'v', 'o', 'i', 'd', '\0'},
						 {'b', 'o', 'o', 'l', 'e', 'a', 'n','\0'},
						 {'S', 't', 'r', 'i', 'n', 'g','\0'}
	};
	int arraySize = 10;
	int lastElementSize = 6;
	int possibleMethod = 0;
	int method = 0;
	int wordsCounter = 0;

	char info[100] = "";
	char saveForLater[100] = "";
	char saveOtherStuffForLater[100] = "";
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
				printf("Author: %s", saveForLater);
				// ADD HERE
				/*
				char str[100];
				char new_char = 'a';*/
				//...
					// adds new_char to existing string:
				/*
				int i = 0;
				//int lenght = 0;
				while (objects[10][10] != '\0')
				{
					++i;
				}*/
				strcpy(objects[10], token);
				arraySize++;/*
				strcpy(objects[i], "\0");
				lastElementSize = strlen(token);
				printf("\nNew object type: %s\n", (char*)objects[9]);
				// --------*/
				strcpy(saveForLater, "");
			}

			else if (method == 1) {
				printf("Method: %s\n", saveOtherStuffForLater);
				if (param = 1) {
					printf("Parameter: %s", saveForLater);
					param = 0;
				}
				else if (retrn = 1) {
					printf("Returns: %s", saveForLater);
					retrn = 0;
				}
				strcpy(saveForLater, "");
				method = 0;
			}
			else if (possibleMethod == 1) {
				strcpy(saveOtherStuffForLater, "");
				strcpy(saveOtherStuffForLater, token);
				possibleMethod = 0;
			}

			else if (saveNextToken == 1) {
				if (strcmp(token, "@param")) {
					strcat(saveForLater, token);
					strcat(saveForLater, " ");
				}
				else {
					//printf("saveForLaterWord: %s-\n", saveForLater);
					//printf("saveForLaterChar: %c\n", saveForLater[strlen(saveForLater) - 2]);
					saveForLater[strlen(saveForLater) - 2] = '\0';
					strcat(saveForLater, "\nParameter: ");
				}
			}
			else if (!strcmp(token, "@return")) {
				saveNextToken = 1;
			}
			else if (!strcmp(token, "@param")) {
				saveNextToken = 1;
			}
			else if (!strcmp(token, "@author")) {
				author = 1;
			}
			else if (!strcmp(token, "class")) {
				clas = 1;
			}
			else if (!strcmp(token, "(")) {
				method = 1;
			}

			//check if it is a method
			//qui ci va un for che scorre tutti gli elementi della lista con dentro l'if sotto
			for (int i = 0; i < arraySize; ++i) {
				if (!strcmp(token, (char*)objects[i]) && possibleMethod == 0) {
					possibleMethod = 1;
				}
			}
			token = strtok(NULL, delimiters);
		}
	}
	printf("%s\n", info);
	fclose(javaFile);
}

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
			/*
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
			}*/
			
		
		/* SHOULD USE THIS SOMEWHERE IDK WHERE
		*/
	}
	else {
		printf("Error: insufficient number of given parameters\n");
	}  
	return 0;
}