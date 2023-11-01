/*
	Day: 2023.10.10
	참고 : 그래프
*/
#include <iostream>
#include <vector>

using namespace std;
int vis[101];
vector<int> adj_matrix[100] = {};
int result = 0;
void dfs(int cur) {
	vis[cur] = 1;
	for (auto nxt : adj_matrix[cur]) {
		if (vis[nxt]) continue;
		result++;
		dfs(nxt);
	}
}

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj_matrix[u-1].push_back(v-1);
		adj_matrix[v-1].push_back(u-1);
	}
	dfs(0);
	cout << result;
	/*
	for (int i =
	0; i < e; i++) {
		for (int j = 0; j < e; j++) {
			if (adj_matrix[i - 1][j - 1] == 1) {
				result++;
			}
		}
		
	}*/
	
}
