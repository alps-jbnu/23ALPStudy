#include <bits/stdc++.h>
using namespace std;

int parent[100001];

int find(int x) {
	if (x == parent[x]) return x;
	else
		return parent[x] = find(parent[x]);
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

	int n, m, a, b, c, sum = 0;
	vector<tuple<int, int, int>> vec;
	vector<int> result;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		vec.push_back({ c, a, b });	//비용, 출발지, 목적지
	}

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		int a = get<1>(vec[i]);
		int b = get<2>(vec[i]);
		int c = get<0>(vec[i]);

		if (find(a) != find(b)) {
			merge(a, b);
			result.push_back(c);
			//왜 sum += c로 하면 안되는가??
		}
	}

	for (int i = 0; i < result.size() - 1; i++)
		sum += result[i];

	cout << sum;
	return 0;
}