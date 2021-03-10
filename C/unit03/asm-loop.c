#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	char* format = "Argument %d: %s\n";
	char* message = "All arguments printed.\n";
	int i;
	__asm
	{
		mov i, 0
		jmp $CHECK_i

	$INCREMENT_i:
		inc i

	$CHECK_i:
		mov ecx, i
		cmp ecx, argc
		jge $END_LOOP
		mov edx, i
		mov eax, argv
		mov ecx, [eax + (edx * 4)]
		push ecx
		push i
		push format
		call printf
		add esp, 12
		jmp $INCREMENT_i
	
	$END_LOOP:
		push message
		call printf
		pop ebx
	}

	return 0;
}