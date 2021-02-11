#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum CHOICE
{
	TRIANGLE = 0,
	XMAS_TREE = 1,
	NAME_SATRS = 2
};

void print_triangle()
{
	char triangle_size[10];
	printf("Enter size: ");
	fgets(triangle_size, 10, stdin);
	int number3 = atoi(triangle_size);
	int size1 = number3;
	while(number3 > 0)
	{
		for (int i = 0; i < number3; ++i)
		{
			printf("*");
		}
		number3--;
		printf("\n");
	}
	printf("\nSize:%d\n", size1);
}

void print_xmastree()
{
	char tree_size[10];
	printf("Enter size: ");
	fgets(tree_size, 10, stdin);
	int number1 = atoi(tree_size);
	int spaces = number1 - 1;
	int asterisks = 1;
	for (int line = 0; line < number1; ++line)
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
	for (int e = 0; e < (asterisks / 2) - 1; ++e) {
		printf(" ");
	}
	printf("*");
	printf("\nSize:%d\n", number1);
}

void print_namesurrounded()
{
	char name[10];
	printf("Enter name: ");
	fgets(name, 10, stdin);
	int number2 = strlen(name);
	for (int i = 0; i < number2 + 1; ++i) {
		printf("*");
	}
	if (number2 > 0 && name[number2 - 1] == '\n')
		name[number2 - 1] = '\0';
	printf("\n*%s* \n", name);
	for (int i = 0; i < number2 + 1; ++i) {
		printf("*");
	}
	printf("\nSize:%d\n", number2);
}

int main(int argc, char** argv)
{
	printf("0 - Triangle \n");
	printf("1 - Christmas tree \n");
	printf("2 - Name surrounded by stars \n");
	printf("Enter choiche: ");
	char buffer[10];
	fgets(buffer, 10, stdin);
	enum CHOICE ch = atoi(buffer);
	
	switch (ch)
	{
	case TRIANGLE:
		print_triangle();
		break;
	case XMAS_TREE:
		print_xmastree();
		break;
	case NAME_SATRS:
		print_namesurrounded();
		break;
	default:
		printf("*** INVALID INPUT ***\n");
		break;
	}

	return 0;
}