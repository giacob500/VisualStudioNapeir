#include <stdio.h>
#include <string.h>
#include "promptInfos.h"

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
				strcpy(objects[10], token);
				arraySize++;
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