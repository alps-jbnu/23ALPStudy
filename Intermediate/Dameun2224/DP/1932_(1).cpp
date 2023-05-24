#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[505][505];
int mx[505][505];


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)cin >> arr[i][j];
	}

	mx[1][1] = arr[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			// mx[1][1]을 시작으로 잡아서, mx[0][j], mx[i][0]은 모두 0
			// 그래서 조건문 없이 
			// mx[i][j] = max(mx[i - 1][j - 1], mx[i - 1][j]) + arr[i][j];
			// 만 써도 문제 없음
			if (j == 1) mx[i][1] = mx[i - 1][1] + arr[i][1];
			else if (j == i) mx[i][j] = mx[i - 1][j - 1] + arr[i][j];
			else mx[i][j] = max(mx[i - 1][j - 1], mx[i - 1][j]) + arr[i][j];
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, mx[n][i]);
	cout << ans << '\n';

	return 0;
}
