# include <stdio.h>
# include <string.h>

int main(int argc, char** argv)
{
	FILE* file = fopen("names.txt", "w");
	while (1) {
		printf("Insert name (END to exit): \n");
		char buffer[10];
		fgets(buffer, 10, stdin);
		int number = atoi(buffer);

		int len = strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';

		if (!strcmp(buffer, "END")) {
			printf("Exiting program...\n");
			break;
		}
		printf("Writing name on file...\n");
		fprintf(file, "%s\n", buffer);
		printf("Name written correctly.\n");
	}
	fclose(file);
	return 0;
}