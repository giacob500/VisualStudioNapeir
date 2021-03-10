#include <stdio.h>
#include <stdlib.h>

void func() {
	static int x = 0;
	printf("x = %d\n", x);
	x = x + 1;
}

int main(int argc, char** argv)
{
	for (int i = 0; i < 100; ++i)
	func();

	return 0;
}