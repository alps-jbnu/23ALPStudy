#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<string, int> id;
string name[1002];
vector<int> adj[1002]; 
vector<int> ch[1002];
int deg[1002];

int n, m, num;
string x, y;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> name[i];
	}
	sort(name + 1, name + n + 1);
	for (int i = 1; i <= n; i++) {
		id[name[i]] = i;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adj[id[y]].push_back(id[x]);
		deg[id[x]]++;
	}

	vector<int> ac;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) ac.push_back(i);
	}
	cout << ac.size() << '\n';
	for (int a : ac)
		cout << name[a] << ' ';
	cout << '\n';
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
		for (int chd : adj[i])
			if (deg[chd] - deg[i] == 1) ch[i].push_back(chd);
	}
	for (int i = 1; i <= n; i++) {
		int size = ch[i].size();
		cout << name[i] << ' ' << size << ' ';
		for (int c : ch[i])
			cout << name[c] << ' ';
		cout << '\n';
	}
}
