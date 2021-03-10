#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
	FILE* input = fopen("dictionary.txt", "r");
	char search_word[100];
	printf("Please enter a word to check the spelling of: ");
	fgets(search_word, 100, stdin);
	int len = strlen(search_word);
	if (len > 0 && search_word[len - 1] == '\n')
	{
		search_word[len - 1] = '\0';
	}

	// Modified part
	printf("Here starts the modified part:\n");
	char* delimiters = " . ,\n";
	char* token = strtok(search_word, delimiters);
	while (token != NULL)
	{		
		char dictionary_line[100];
		int dict_line_len = 0;
		int found = 0;
		while (fgets(dictionary_line, 100, input) != NULL)
		{
			dict_line_len = strlen(dictionary_line);
			if (dict_line_len > 0 && dictionary_line[dict_line_len - 1] == '\n')
			{
				dictionary_line[dict_line_len - 1] = '\0';
			}
			if (strcmp(token, dictionary_line) == 0)
			{
				printf("Word %s is spelt correctly\n", token);
				found = 1;
				break;
			}

		}
		if (found == 0)
		{
			printf("Word %s is not in the dictionary\n", token);
		}
		printf("%s\n", token);
		token = strtok(NULL, delimiters);
		rewind(input);
	}
	// end
		
	fclose(input);
	return 0;
}