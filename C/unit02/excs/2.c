#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char** argv)
{
	// Integer types
	unsigned int a = UINT_MAX;
	signed int a1 = INT_MAX;
	signed int a2 = INT_MIN;
	printf("Integer -  unsigned max+1:%u signed max+1:%d signed min-1:%d\n", a + 1, a1 + 1, a2 - 1);
	unsigned short b = USHRT_MAX;
	signed short b1 = SHRT_MAX;
	signed short b2 = SHRT_MIN;
	printf("Short -  unsigned max+1:%h signed max+1:%h signed min-1:%h\n", b + 1, b1 + 1, b2 - 1);
	unsigned long c = ULONG_MAX;
	signed long c1 = LONG_MAX;
	signed long c2 = LONG_MIN;
	printf("Long -  unsigned max+1:%lu signed max+1:%ld signed min-1:%ld\n", c + 1, c1 + 1, c2 - 1);
	unsigned long long d = ULLONG_MAX;
	signed  long long d1 = LLONG_MAX;
	signed long long d2 = LLONG_MIN;
	printf("Long long -  unsigned max+1:%llu signed max+1:%lld signed min-1:%lld\n", d + 1, d1 + 1, d2 - 1);

	/*
	// Floating point types
	signed float d = 
	signed double e = dou
	*/

	// Character types
	unsigned char z = UCHAR_MAX;
	signed char z1 = CHAR_MAX;
	signed char z2 = CHAR_MIN;
	char z3 = CHAR_MAX;
	char z4 = CHAR_MIN;
	printf("Char -  unsigned max+1:%c signed max+1:%c signed min-1:%c max-1:%d min-1:%c\n", z + 1, z1 + 1, z2 - 1, z3 + 1, z4 - 1);

	return 0;
}