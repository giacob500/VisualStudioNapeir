#include <stdio.h>
int main(int argc, char** argv)
{
	int x = 500;
	int y = 200;
	int z = 0;

	printf("Before assembly z = %d\n", z);

	__asm
	{
		mov ecx, x
		add ecx, y
		mov z, ecx
	}
	printf("After assembly z = %d\n", z);
	return 0;
}