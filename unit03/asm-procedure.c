#include <stdio.h>
int main(int argc, char** argv)
{
	char* message = "Hello World!\n";

	__asm
	{
		push message
		call printf
		call printf
		call printf
		pop ebx
	}

	return 0;
}