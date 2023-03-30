#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N;
	int count[10] = { 0, };

	scanf("%d", &N);

	while (N > 0) {
		count[N % 10]++;
		N /= 10;
	}

	count[6] = (count[6] + count[9] + 1) / 2;

	int max = 0;
	for (int i = 0; i < 9; i++) {
		if (max < count[i])
			max = count[i];
	}

	printf("%d", max);

	return 0;
}