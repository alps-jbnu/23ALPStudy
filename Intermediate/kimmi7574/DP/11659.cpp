#include <bits/stdc++.h>
using namespace std;

int n;	//수의 개수
int m;	//합을 구해야 하는 횟수
int a[100005];
int d[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	//0-indexed를 쓰면 d[i-1]이 d[-1]이 될 수 있음 (예외처리 해야함)
	//=> 1-indexed를 쓰는 것이 편함
	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = d[i - 1] + a[i];	//d배열에 1 ~ i-1까지의 합 저장
	}

	//i ~ j까지의 합 출력
	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << d[j] - d[i - 1] << '\n';
	}

	//  a[i] + a[i+1] + ... + a[j]
	//= (a[1] + a[2] + ... + a[j]) - (a[1] + a[2] + ... + a[i-1])
	//= d[j] - d[i-1]
}