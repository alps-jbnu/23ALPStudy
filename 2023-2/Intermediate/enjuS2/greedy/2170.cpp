#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<memory>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	while (n--) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end());
	int ans = 0;
	int st = v[0].first;
	int en = v[0].second;
	for (int i = 1; i < v.size(); i++) {
		int s = v[i].first;
		int e = v[i].second;
		if (en >= s) {
			if (en < e) {
				en = e;
			}
		}
		else {
			ans += en - st;
			st = s;
			en = e;
		}
	}
	ans += en - st;
	cout << ans << '\n';
}
