#include <stdio.h>
#include <string.h>

// rewriting strcat function
void strcat(char a[], cahr b[])
{
	int i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	int j = 0;
	while (b[j] != '\n')
	{
		a[i] = b[j];
		i++;
		j++;
	}
	a[i] = '\0';
}

int main(int argc, char** argv)
{
	char a[10];
	char b[10];
	
	strcat(a, b);
	return 0;
}