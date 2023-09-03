#include<bits/stdc++.h>
using namespace std;

int n;
priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
pair<int, pair<int,int>> p[100005];
pair<int, pair<int,int>> pr[100005];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second.first;
		p[i].second.second = i + 1;
		pr[i] = p[i];
	}
	sort(pr, pr + n);
	int mx =pr[0].first+pr[0].second.first;
	int ans = 0;
	for (int i = 1; i < n;) {
		while (pr[i].first <= mx && i < n) {
			pq.push({ pr[i].second.second,{pr[i].first,pr[i].second.first} });
			++i;
		}
		if (pq.empty()) {
			pq.push({ pr[i].second.second,{pr[i].first,pr[i].second.first} });
			mx = pr[i].first;
			++i;
		}
		ans = max(ans, mx - pq.top().second.first);
		mx += pq.top().second.second;
		pq.pop();
	}
	cout << ans;
 }