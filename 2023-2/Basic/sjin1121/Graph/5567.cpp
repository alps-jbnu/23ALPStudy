#include <iostream>
#include <vector>

using namespace std;
vector<int>v[501];
bool visited[501];
int main() {
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	visited[1] = true;

	for (int i = 0; i < v[1].size(); i++) {
		visited[v[1][i]] = true;
		for (int j = 0; j < v[v[1][i]].size(); j++) {
			if (visited[v[v[1][i]][j]] == false) {
				visited[v[v[1][i]][j]] = true;
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (visited[i])
			cnt++;
	}
	cout << cnt;
}
