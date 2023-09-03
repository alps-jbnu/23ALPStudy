#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> edge;
vector<int> installed_city;
int parent[1002];

int find(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k, cost = 0;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		installed_city.push_back(num);
	}

	for (int i = 1; i < installed_city.size(); i++)
		merge(installed_city[0], installed_city[i]);

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back({ w, u, v });
	}

	sort(edge.begin(), edge.end());

	for (int i = 0; i < edge.size(); i++) {
		int u = get<1>(edge[i]);
		int v = get<2>(edge[i]);
		int w = get<0>(edge[i]);

		if (find(u) != find(v)) {
			merge(u, v);
			cost += w;
		}
	}

	cout << cost;
	return 0;
}