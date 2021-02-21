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
		char* delimiters = " .,\n";
		char* token = strtok(line, delimiters);
		// Loop to pass through the single words
		while (token != NULL) {
			printf("%s\n", token);
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
	fclose(input);
	return 0;
}