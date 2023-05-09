#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int n, ans = 0;
int in[4];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int stm, std, enm, end;
		cin >> stm >> std >> enm >> end;
		v.push_back({ stm * 100 + std, enm * 100 + end });
	}
	int cur = 301;
	int nxt;
	while (cur <= 1130) {
		nxt = cur;
		for (int i = 0; i < n; i++) {
			if (cur >= v[i].first && nxt < v[i].second)
				nxt = v[i].second;
		}
		if (nxt == cur) {
			cout << 0;
			return 0;
		}
		ans++;
		cur = nxt;
	}
	cout << ans;
}
