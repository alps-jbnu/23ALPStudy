#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec[2005];
bool ans = 0;
bool vis[2005] = { false };
void dfs(int d,int num) {
	if (d == 4) {
		ans = 1;
		return;
	}
	for (auto a : vec[num]) {
		if (vis[a])	continue;
		vis[a] = 1;
		dfs(d + 1, a);
		vis[a] = 0;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		vis[i] = 1;
		dfs(0, i);
		vis[i] = 0;
		if (ans)	break;
	}
	cout << ans;
}