#include <bits/stdc++.h>
using namespace std;

int N;	//집의 개수
int C;	//공유기의 개수
int router, st, cnt;
vector<int> X;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		X.push_back(num);
	}

	sort(X.begin(), X.end());

	int start = 1;	//최소 거리
	int end = X[N - 1] - X[0];	//최대 거리

	while (start <= end) {
		router = 1;
		int mid = (start + end) / 2;
		st = X[0];

		for (int i = 1; i < N; i++) {
			if (X[i] - st >= mid) {
				router++;
				st = X[i];
			}
		}

		if (router >= C) {
			cnt = max(cnt, mid);
			start = mid + 1;
		}
		else
			end = mid - 1;
	}

	cout << cnt;
	return 0;
}