#include <bits/stdc++.h>
using namespace std;

int n, k;
int len = 0;
int S[1000002];

bool isEven(int num) {
	return num % 2 == 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> S[i];
	}

	int st = 0, en = 0; 
	int	cnt = 0;	// S[st] ~ S[en] 에서 홀수의 개수
	if (S[0] % 2 == 1)
		cnt ++;

	for (st = 0; st < n; st++) {
		while (en < n - 1 && cnt + S[en + 1] % 2 <= k) {
			en++;
			cnt += S[en] % 2; //S[en]가 짝수면 나머지 0, 홀수면 나머지 1
		}

		len = max(len, en - st + 1 - cnt);
		cnt -= S[st] % 2;
	}

	cout << len;
	return 0;
}