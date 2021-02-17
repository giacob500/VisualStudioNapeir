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
		add esp, 4			; pop ebx
		push input
		push 50
		lea ebx, name
		push ebx
		call fgets
		call printf
		add esp, 12
	}

	return 0;
}