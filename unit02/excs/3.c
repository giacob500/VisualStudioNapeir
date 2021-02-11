#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum CHOICE
{
	EXIT = 0,
	ENTER_DETAILS = 1,
	PRINT_DETAILS = 2
};

int main(int argc, char** argv)
{
	unsigned int matric;
	char name[15];
	char address[30];

	int flag = 1;
	while (flag)
	{
		printf("\n1 - enter student details \n");
		printf("2 - print student details \n");
		printf("0 - exit \n");
		printf("Enter choiche: ");
		char buffer[10];
		fgets(buffer, 10, stdin);
		enum CHOICE ch = atoi(buffer);

		switch (ch)
		{
		case ENTER_DETAILS:
			printf("Enter name: ");
			fgets(name, 15, stdin);
			printf("Enter address: ");
			fgets(address, 30, stdin);
			printf("Enter matric: ");
			char buffer1[8];
			fgets(buffer1, 8, stdin);
			matric = atoi(buffer1);
			break;
		case PRINT_DETAILS:
			printf("\nName: %sAddress: %sMatric: %u\n", name, address, matric);
			break;
		case EXIT:
			printf("Exiting ...\n");
			flag = 0;
			break;
		default:
			printf("*** INVALID INPUT ***\n");
			break;
		}
	}

	return 0;
}