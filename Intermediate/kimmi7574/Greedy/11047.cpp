#include <bits/stdc++.h>
using namespace std;

int n, k;
int A[15];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt = 0;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		cnt += k / A[i];	//몫 : 동전 개수
		k %= A[i];			//나머지: 20번줄에서 나누고 난 후 의 남은 k원
	}

	cout << cnt;
}