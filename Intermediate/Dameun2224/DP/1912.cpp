#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int arr[100005];
int d[100005];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, mx = INT_MIN;
	cin >> n;

	// i까지의 합을 저장하다가, mx 연산 후 d[i] < 0 이면 0으로 바꿈
  // 모두 음수인 경우 22, 23번째 코드의 순서가 바뀌면 mx가 0이 됨
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		d[i] = d[i - 1] + arr[i];
		mx = max(mx, d[i]);
		if (d[i] < 0) d[i] = 0;
	}

	cout << mx << '\n';
	

	return 0;
}
