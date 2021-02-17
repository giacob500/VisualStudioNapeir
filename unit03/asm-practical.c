#include <stdio.h>
int main(int argc, char** argv)
{
	char name[50];
	char* msg = "Please enter your name: ";
	FILE* input = stdin;

	__asm
	{
		push msg
		call printf
		pop ebx
		push input
		push 50
		lea ebx, name
		push ebx
		call fgets
		call printf
		pop ebx
	}

	return 0;
}