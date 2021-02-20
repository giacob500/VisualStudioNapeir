#include <stdlib.h>
#include <stdio.h>
#include "generate.h"
#include "sort.h"
#include "search.h"

#define NUM_INTEGERS 65535

int main(int arc, char **argv) {
	int data[NUM_INTEGERS];

	generate(NUM_INTEGERS, data);

	printf("\nUnsorted\n");
	for (int i = 0; i < 20; ++i)
		printf("%d\n", data[i]);

	sort(NUM_INTEGERS, data);

	printf("\nSorted\n");
	for (int i = 0; i < 20; i++) {
		printf("%d\n", data[i]);
	}

	return 0;
}