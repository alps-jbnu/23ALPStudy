#include<bits/stdc++.h>
using namespace std;
int n, m, q;
int par[100005];
pair<int, int> arr[100005];
stack<int> L;
bool vis[100005];
long long ans = 0;

int Find(int a) {
 	if (par[a] < 0)	return a;
	return par[a] = Find(par[a]);
}


long long Union(int u, int v) {
	u = Find(u);
	v = Find(v);

	if (u == v)	return 0;

	long long res = par[u] * par[v];

	if (par[u] < par[v]) {
		par[u] += par[v];
		par[v] = u;
	}
	else {
		par[v] += par[u];
		par[u] = v;
	}
	return  res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	for (int i = 0; i < q; i++) {
		int a;
		cin >> a;
		vis[a] = 1;
		L.push(a);
	}
	memset(par, -1, sizeof(par));
	for (int i = 0; i < m; i++) {
		if (vis[i+1])	continue;
		Union(arr[i].first, arr[i].second);
	}

	for (int i = 0; i < q; i++) {
		ans+=Union(arr[L.top() - 1].first, arr[L.top() - 1].second);
		L.pop();
	}

	cout << ans;
 }