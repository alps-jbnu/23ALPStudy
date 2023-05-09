#include<bits/stdc++.h>
using namespace std;

int n, x;
vector<pair<int, int>> vec;
int ans = 0;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return (a.first - a.second) > (b.first - b.second);
}




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ a,b });
		ans += b;
		x -= 1000;
	}
	
	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < n; i++) {
		if (x >= 4000 && vec[i].first - vec[i].second >= 0) {
			x -= 4000;
			ans += vec[i].first - vec[i].second;
		}
	}
	cout << ans;
 }