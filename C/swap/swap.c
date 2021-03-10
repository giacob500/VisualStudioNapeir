#include <stdio.h>
void swap(int*, int*);

int main(int argc, char** argv)
{
	int a = 1;
	int b = 2;
	swap(&a, &b);
	return 0;
}

//Doesn't work as intended!
void swap(int *a, int *b)
{
	printf("%d\n", *a);
	printf("%d\n", *a);
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("%d\n", *a);
	printf("%d\n", *b);
}