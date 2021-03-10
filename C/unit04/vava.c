#include <stdio.h>
#include <string.h>


int main(int argc, char** argv)
{
    // Read in a word to check the spelling of
    char sentence[1000];
    printf("Please enter the sentence to check the spelling of: ");
    fgets(sentence, 1000, stdin);

    char* delimiters = " .,\n"; // Symbols that mark the end of a token(word)
    char* token = strtok(sentence, delimiters); // Get the first token
    FILE* input = fopen("dictionary.txt", "r");

    while (token != NULL) // Loop until there are no more tokens (words) left
    {
        char dictionary_line[100];
        int dict_line_len = 0;
        int found = 0; // not found the word in the dictionary yet
        for (int i = 0; token[i]; i++)
        {
            token[i] = tolower(token[i]);
        }
        while (fgets(dictionary_line, 100, input) != NULL)
        {
            // Need to remove the new line at the end of the word
            dict_line_len = strlen(dictionary_line);
            if (dict_line_len > 0 && dictionary_line[dict_line_len - 1] == '\n')
            {
                dictionary_line[dict_line_len - 1] = '\0 ';
            }

            // Case sensitivity
            for (int i = 0; dictionary_line[i]; i++)
            {
                dictionary_line[i] = tolower(dictionary_line[i]);
            }
            printf(":%s:%s:\n", token, dictionary_line);
            if (strcmp(token, dictionary_line) == 0)
            {
                // Strings match
                printf("The word -%s- is spelt correctly \n", token);
                found = 1;
                rewind(input);
                break;
            }
        }
        if (found == 0)
        {
            printf("The word -%s- is not in the dictionary \n", token);
        }

        token = strtok(NULL, delimiters); // Get the next token (note the NULL as the first arg )

    }

    fclose(input);
    return 0;
}