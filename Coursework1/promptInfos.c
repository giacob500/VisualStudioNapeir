#include <stdio.h>
#include <string.h>
#include "promptInfos.h"

// Function to prompt to console informations readed from given input java file ("inputFile")
void promptInfos(char* inputFile)
{
	// Flags
	int saveNextToken = 0;
	int author = 0;
	int param = 0;
	int retrn = 0;
	int clas = 0;
	int possibleMethod = 0;
	int method = 0;

	// Other variables
	int objectsArraySize = 10;
	char line[1000];
	char saveForLater[100] = "";
	char saveOtherStuffForLater[100] = "";
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
	FILE* javaFile = fopen(inputFile, "r");

	// Loop input file line by line
	while (fgets(line, 1000, javaFile) != NULL)
	{
		char* delimiters = " .,;\n";
		char* token = strtok(line, delimiters);
		// Loop line word by word
		while (token != NULL)
		{
			// If comment is closed or if method is opened reset flags
			if (!strcmp(token, "*/") || !strcmp(token, "{"))
			{
				printf("\n");
				saveNextToken = 0;
				author = 0;
				clas = 0;
			}
			// If author is found save it for later
			if (author == 1)
			{
				strcat(saveForLater, token);
				strcat(saveForLater, " ");
			}
			// If class is found print it and then author
			else if (clas == 1)
			{
				printf("Class: %s\n", token);
				printf("Author: %s", saveForLater);
				strcpy(objects[10], token);
				objectsArraySize++;
				strcpy(saveForLater, "");
			}
			// if method is found print it and its parameters or what returns
			else if (method == 1)
			{
				printf("Method: %s\n", saveOtherStuffForLater);
				if (param = 1) {
					printf("Parameter: %s", saveForLater);
					param = 0;
				}
				else if (retrn = 1)
				{
					printf("Returns: %s", saveForLater);
					retrn = 0;
				}
				strcpy(saveForLater, "");
				method = 0;
			}
			// If a possible method is found save string for later
			else if (possibleMethod == 1)
			{
				strcpy(saveOtherStuffForLater, "");
				strcpy(saveOtherStuffForLater, token);
				possibleMethod = 0;
			}
			// Save word into a string to display all method's parameters later on
			else if (saveNextToken == 1)
			{
				if (strcmp(token, "@param"))
				{
					strcat(saveForLater, token);
					strcat(saveForLater, " ");
				}
				else {
					// Cut jaavdoc comment's asterisk(*) and add "Parameter:"
					saveForLater[strlen(saveForLater) - 2] = '\0';
					strcat(saveForLater, "\nParameter: ");
				}
			}
			// Flag up if one of the words below is found
			else if (!strcmp(token, "@return"))
			{
				saveNextToken = 1;
			}
			else if (!strcmp(token, "@param"))
			{
				saveNextToken = 1;
			}
			else if (!strcmp(token, "@author"))
			{
				author = 1;
			}
			else if (!strcmp(token, "class"))
			{
				clas = 1;
			}
			else if (!strcmp(token, "("))
			{
				method = 1;
			}
			// Check if the object type is part of the knowns in the objects array, so flag up a possible method
			for (int i = 0; i < objectsArraySize; ++i)
			{
				if (!strcmp(token, (char*)objects[i]) && possibleMethod == 0)
				{
					possibleMethod = 1;
				}
			}
			token = strtok(NULL, delimiters);
		}
	}
	printf("\n");

	// Close file
	fclose(javaFile);
}