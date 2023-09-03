/*
최솟값을 구해야 한다.→그리디로 접근

각 단계에서 최선의 방법으로 하기

최선의 방법을 걸리는 시간이 가장 작은 사람부터 인출해서 그 다음 작은 사람. 이런식으로 접근하였다.

#include <iostream>
#include <algorithm>

int p[1005];

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> p[i];

	}
	std::sort(p, p + n);
	int sum = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		sum += p[i];
		ans += sum;
	}
	std::cout << ans;
}
*/
