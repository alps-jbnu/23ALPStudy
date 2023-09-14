#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int dice(int a, int b, int c)
{
	int result = 0;
	if (a == b && b == c) {
		result = 10000 + 1000 * a;
	}
	else if (a == b) {
		result = 1000 + 100 * a;
	}
	else if (a == c) {
		result = 1000 + 100 * c;
	}
	else if (b == c) {
		result = 1000 + 100 * b;
	}
	else if (a > b && a > c) {
		result = 100 * a;
	}
	else if (b > a && b > c) {
		result = 100 * b;
	}
	else if (c > b && c > a) {
		result = 100 * c;
	}
	return result;
}

int main()
{
	int a = 0, b = 0, c = 0;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", dice(a, b, c));
}

