/*
최솟값을 구하라 하고 입력이 작으니까 그리디로 접근해보자.

그리디는 매 단계에서 최선의 선택을 하는 것이다.

이 문제에서 최선의 선택 아이디어는 각 배열의 가장 작은수를 다른 배열의 가장 큰수와 매치 시키는 것이다.

#include <iostream>
#include <algorithm>

int a[105];
int b[105];

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}

	std::sort(a, a + n);
	std::sort(b, b + n);
	int s=0;
	for (int i = 0; i < n; i++) {
		s += a[i] * b[n - 1 - i];
	}
	std::cout << s;

}

*/
