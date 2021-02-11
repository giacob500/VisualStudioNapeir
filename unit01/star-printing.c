# include <stdio.h>
# include < stdlib.h >
# include < string.h >

int main(int argc, char** argv)
{
	while (1) {
		char buffer[10];
		printf("How many stars ? (0 to quit )");
		fgets(buffer, 10, stdin);
		int number = atoi(buffer);
		if (!number) {
			break;
		}
		for (int i = 0; i < number; ++i) {
			for (int j = 0; j <= i; ++j)
				printf("*");
			printf("\n");
		}
	}
	printf(" Goodbye!\n");
	return 0;
}