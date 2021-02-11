# include <stdio.h>
# include < stdlib.h >
# include < string.h >

int main(int argc, char** argv)
{
	char buffer[10];
	printf("What's your name? (0 to quit )");
	fgets(buffer, 25, stdin);
	int number = strlen(buffer);
	if (!number) {
		break;
	}
	for (int i = 0; i < number + 1; ++i) {
		printf("*");
	}
	if (number > 0 && buffer[number - 1] == '\n')
		// If so set newline character to null terminator
		buffer[number - 1] = '\0';
	printf("\n*%s*\n", buffer);
	for (int i = 0; i < number + 1; ++i) {
		printf("*");
	}
	printf("\nGoodbye!\n");
	return 0;
}