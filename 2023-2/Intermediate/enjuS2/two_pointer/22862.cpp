#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int mx = 0;
	int en = 0;
	int cnt = 0;
	cnt += v[0] % 2;
	for (int st = 0; st < n; st++) {
		while (en < n - 1 && cnt + (v[en + 1] % 2) <= k) {
			en++;
			cnt += v[en] % 2;
		}
		mx = max(mx, en - st + 1 - cnt);
		cnt -= v[st] % 2;
	}
	cout << mx;
}
