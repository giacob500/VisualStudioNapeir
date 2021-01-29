# include <stdio.h>
// contains helper functions for strings
# include <string.h>

int main(int argc, char **argv)
{
	// Declare a character array for message
	char msg_1[5] = { 'H','e','l','l','o' };
	// Declare a second character array for message
	char msg_2[8] = " World !";
	// Declare a third message
	char msg_3[9] = " Goodbye !\0 ";
	// Declare a forth message - no size
	char msg_4[] = " Compiler worked out my size !";
	// Declare a fifth message - use a pointer
	char* msg_5 = " Compiler worked out my size too !";

	// Print messages . 1st message is not null - terminated
	printf("%s\n", msg_1);
	printf("%s\n", msg_2);
	printf("%s\n", msg_3);
	printf("%s\n", msg_4);
	printf("%s\n", msg_5);

	return 0;
}