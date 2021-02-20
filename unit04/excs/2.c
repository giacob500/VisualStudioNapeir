# include <stdio.h>
# include <string.h>

int main(int argc, char** argv)
{
	FILE* input = fopen("file.txt", "r");
	char line[10];
	while (fgets(line, 10, input) != NULL)
		{
			printf("%s\n", line);
		}
	fclose(input);
	return 0;
}