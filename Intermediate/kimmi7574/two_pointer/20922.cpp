#include <bits/stdc++.h>
using namespace std;

int n, k;
int len = 0;
int a[200005];
int cnt[100005];	// i번째 수의 등장 횟수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int st = 0, en = 0;
	++cnt[a[en]];	//처음 위치 a[0]의 등장 횟수 추가
	//bool connect = false;

	for (int st = 0; st < n; st++) {
		while (en + 1 != n && cnt[a[en + 1]] < k) {
			++en;
			cnt[a[en]]++;
		}

		len = max(len, en - st + 1);
		cnt[a[st]]--;
	}

	/*while (st <= en && en < n) {
		if (a[en] == a[en + 1]) {
			en_cnt++;
		}
		else {
			if (en_cnt == k) {
				st = en;
				connect = true;
			}
			if (connect && en_cnt <= k)
				cnt++;
			if (en_cnt > 0)
				en_cnt = 0;
		}
		en++;
	}*/

	cout << len;
	return 0;
}