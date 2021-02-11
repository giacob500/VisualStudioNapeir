# include <stdio.h>
# include < stdlib.h >
# include < string.h >

int main(int argc, char** argv)
{
	int flag = 1;
	while (flag) {
		printf("1 - say hello\n");
		printf("2 - say goodbye\n");
		char buffer[10];
		fgets(buffer, 10, stdin);
		int number = atoi(buffer);

		switch (number) {
		case 1:
			printf("Hello world!\n");
			break;
		case 2:
			printf("Goodbye world!\n");
			//break;
		default:
			printf("***INVAALID INPUT***\n");
			break;
		}
	}
	return 0;
}