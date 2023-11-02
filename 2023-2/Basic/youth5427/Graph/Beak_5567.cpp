/*
	Day: 2023.10.10
	참고 : 그래프_실패
*/
#include <iostream>
#include <vector>

using namespace std;
int vis[505] = { 0 };
vector<int> adj_matrix[505] = {};
int result = 0;
void dfs(int cur) {
	vis[cur]++;
	for (auto nxt : adj_matrix[cur]) {
		if (vis[nxt] == 1 || vis[nxt] == 2) {
			result++; continue;
		}
		//if (vis[nxt] > 2) continue; // Avoid visiting a node more than twice
		dfs(nxt);
	}
}

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj_matrix[a - 1].push_back(b - 1);
		adj_matrix[b - 1].push_back(a - 1);
	}
	dfs(0);
	cout << result;
	

}
