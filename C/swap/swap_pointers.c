#include <stdio.h>
void swap(int*,int*);

int main(int argc, char **argv)
{
	int a = 1;
	int b = 2;
	swap(&a, &b);
	printf("Back in main a is %d ", a); 
	printf("and b is %d\n", b);
	return 0;
}


void swap(int *a, int *b)
{
	printf("a before swap is %d, ", *a);
	printf("b before swap is %d\n", *b); 
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("a after swap is %d, ", *a);
	printf("b after swap is %d\n", *b); 
}