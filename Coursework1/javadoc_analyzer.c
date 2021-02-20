# include <stdio.h>
# include <string.h>

int main(int argc, char** argv)
{
	int lineCounter = 0;
	int nonblankCounter = 0;
	int commentStatus = 0;
	int commentCounter = 0;
	FILE* input = fopen("test_files/Student.java", "r");
	char line[1000];
	while (fgets(line, 1000, input) != NULL)
	{
		lineCounter++;
		//printf("%s", line);
		if (strcmp(line, "\n")) {
			nonblankCounter++;
		}

		int sentence_length = strlen(line);
		char token[100];
		int token_index;
		int sentence_index = 0;
		while (sentence_index < sentence_length && line[sentence_index] != '\n')
		{
			token[0] = '\0';
			token_index = 0;
			while (line[sentence_index] != ' ') {
				token[token_index] = line[sentence_index];
				sentence_index++;
				token_index++;
			}
			token[token_index] = '\0';
			printf("%s			%d\n", token, commentStatus);
			sentence_index++;
			if (strcmp(token, "/**") == 0) {
				commentStatus++;
			}
			else if (strcmp(token, "*/") == 0 && commentStatus == 1) {
				commentStatus++;
			}
		}
		if (commentStatus == 2) {
			commentCounter++;
			commentStatus = 0;
		}
	}
	printf("Total number of lines: %d\n", lineCounter);
	printf("Number of non-blank lines: %d\n", nonblankCounter);
	printf("Number of Javadoc comments: %d\n", commentCounter);
	fclose(input);
	return 0;
}