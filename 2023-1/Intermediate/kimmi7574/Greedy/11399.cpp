#include <bits/stdc++.h>
using namespace std;

int n;	// 줄 서있는 사람 수
int P[1005];	//i번 사람이 돈을 인출하는데 걸리는 시간
long long sum[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> P[i];
	}

	sort(P, P + n);

	sum[0] = P[0];
	int min_val = sum[0];
	for (int i = 1; i < n; i++) {
		sum[i] = sum[i - 1] + P[i];
		min_val += sum[i];
	}

	cout << min_val;
}