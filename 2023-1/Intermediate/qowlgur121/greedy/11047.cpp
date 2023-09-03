#include <iostream>
int n, k;
int a[15];


int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cin >> n >> k;

	int ans = 0;
	for (int i = 0; i < n; i++)std::cin >> a[i];
	for (int i = n - 1; i >= 0; i--) {
		ans += k / a[i]; //ans는 거슬러줘야하는 동전의 개수
		k %= a[i];  //거스름돈
	}
	std::cout << ans;

}
