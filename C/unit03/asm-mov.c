#include <stdio.h>
int main(int argc, char** argv)
{
	int x = 500;
	int y = 0;

	printf("Before assembly , x = %d, y = %d\n", x, y);

	__asm
	{
		mov eax, x
		mov y, eax
	}
	printf("After assembly , x = %d, y = %d\n", x, y);
	return 0;
}