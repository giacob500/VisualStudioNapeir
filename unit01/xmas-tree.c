#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	char buffer[10];
	printf("How big do you want your xmas tree? (number in lines): ");
	fgets(buffer, 10, stdin);
	int number = atoi(buffer);
	int spaces = number - 1;
	int asterisks = 1;

	for (int line = 0; line < number; ++line)
	{
		for (int g = 0; g < spaces; ++g) {
			printf(" ");
		}
		for (int j = 0; j < asterisks; ++j)
		{
			printf("*");			
		}
		spaces--;
		asterisks += 2;
		printf("\n");
	}
	for (int e = 0; e < (asterisks/2)-1; ++e) {
		printf(" ");
	}
	printf("*");

	return 0;
}