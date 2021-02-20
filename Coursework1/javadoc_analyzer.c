# include <stdio.h>
# include <string.h>

int main(int argc, char** argv)
{
	int lineCounter = 0;
	int nonblankCounter = 0;
	int commentsCounter = 0;
	FILE* input = fopen("test_files/Student.java", "r");
	char line[1000];
	while (fgets(line, 1000, input) != NULL)
	{
		lineCounter++;
		printf("%s", line);
		if (strcmp(line, "\n")) {
			nonblankCounter++;
		}
		if (strcmp(line, "\n") {

		}
	}
	printf("Total number of lines: %d\n", lineCounter);
	printf("Number of non-blank lines: %d\n", nonblankCounter);
	fclose(input);
	return 0;
}