#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[100];
int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	int v;
	scanf("%d", &v);

	int count = 0;
	for (int j = 0; j < N; j++) {
		if (arr[j] == v)
			count++;
	}
	printf("%d", count);

	return 0;
}