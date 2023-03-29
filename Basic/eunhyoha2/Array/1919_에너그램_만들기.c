#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char A[1000], B[1000];
int main() {
	scanf("%s %s", &A, &B); // 문자열 %s

	int sum = strlen(A) + strlen(B); // 단어 길이
	for (int i = 0; i < strlen(A); i++) {
		for (int j = 0; j < strlen(B); j++) {
			if (A[i] == B[j]) {
				A[i] = -1; 
				B[j] = -2; 
				sum -= 2;
			}
		}
	}
	printf("%d", sum);

	return 0;
}