#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int a = -500;
	unsigned int b = -500;
	unsigned int c = (unsigned int)a;
	float f = -500;

	printf("a signed : %d, a unsigned : %u\n", a, a);
	printf("a signed : %d, a unsigned : %u\n", b, b);
	printf("a signed : %d, a unsigned : %u\n", c, c);
	printf("a signed : %d, a unsigned : %u\n", f, f);
	printf("a == b: %d\n", a == b);
	printf("a == b: %d\n", a == c);
	printf("a == b: %d\n", a == f);

	return 0;
}