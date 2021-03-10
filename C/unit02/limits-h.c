#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char** argv)
{
	printf(" unsigned int is %d bytes , min value %u, max value %u\n", sizeof(unsigned int), 0, UINT_MAX);
	printf("int is %d bytes , min value %d, max value %d\n", sizeof(int), INT_MIN, INT_MAX);

	return 0;
}