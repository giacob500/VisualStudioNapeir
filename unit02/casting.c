#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char** argv)
{
	unsigned char c = UCHAR_MAX;
	printf("Value is %d\n", c);
	printf("As signed char %d\n", (char)c);
	return 0;
}