#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char** str_split(char* a_str, const char a_delim)
{
	char** result = 0;
	size_t count = 0;
	char* tmp = a_str;
	char* last_comma = 0;
	char delim[2];
	delim[0] = a_delim;
	delim[1] = 0;

	/* Count how many elements will be extracted. */
	while (*tmp)
	{
		if (a_delim == *tmp)
		{
			count++;
			last_comma = tmp;
		}
		tmp++;
	}

	/* Add space for trailing token. */
	count += last_comma < (a_str + strlen(a_str) - 1);

	/* Add space for terminating null string so caller
	   knows where the list of returned strings ends. */
	count++;

	result = malloc(sizeof(char*) * count);

	if (result)
	{
		size_t idx = 0;
		char* token = strtok(a_str, delim);

		while (token)
		{
			assert(idx < count);
			*(result + idx++) = strdup(token);
			token = strtok(0, delim);
		}
		assert(idx == count - 1);
		*(result + idx) = 0;
	}

	return result;
}

int main(int argc, char** argv)
{
	FILE* input = fopen("dictionary.txt", "r");
	char search_word[100];
	char full_sentennce[100];
	printf("Please enter a word to check the spelling of: ");
	fgets(search_word, 100, stdin);
	int len = strlen(search_word);
	if (len > 0 && search_word[len - 1] == '\n')
	{
		search_word[len - 1] = '\0';
	}

	// Modified part
	full_sentennce = search_word;
	char** tokens;
	tokens = str_split(search_word, ' ');
	// end

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
		if (strcmp(search_word, dictionary_line) == 0)
		{
			printf("Sentence %s is spelt correctly\n", full_sentennce);
			found = 1;
			break;
		}

	}
	if (found == 0)
	{
		printf("Word %s is not in the dictionary\n", search_word);
	}
	fclose(input);
	return 0;
}