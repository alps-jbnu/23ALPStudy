#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> t[200005];
bool vis[200005];
int n, m;
int g, ans1, ans2;

void Find_pole(int now, int cost) {
	bool ex = t[now].size() > 2 || (now == m && t[now].size() == 2);
	bool no = (now != m && t[now].size() == 1) || (now == m && t[now].size() == 0);
	if (ex || no) {
		g = now;
		ans1 = cost;
		return;
	}
	for (auto k : t[now]) {
		if (!vis[k.first]) {
			vis[k.first] = 1;
			Find_pole(k.first, cost + k.second);
		}
	
	}
}

void Find_branch(int now, int cost) {
	bool chk = t[now].size() == 1;
	if (chk) {
		ans2 = max(ans2, cost);
		return;
	}
	for (auto k : t[now]) {
		if (!vis[k.first]) {
			vis[k.first] = 1;
			Find_branch(k.first, cost + k.second);
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		t[a].push_back({ b,c });
		t[b].push_back({ a,c });
	}
	vis[m] = 1;
	Find_pole(m, 0);
	Find_branch(g, 0);
	cout << ans1 << ' ' << ans2;
 }