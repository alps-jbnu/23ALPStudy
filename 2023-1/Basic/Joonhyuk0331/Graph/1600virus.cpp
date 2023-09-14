#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool vis[101];
vector<int> adj[101];//인접리스트 백터가 10개 있는것임

int bfs();

int main() {
	int v;//정점
	int e;//간선의 개수
	cin >> v;
	cin >> e;
	
	for (int i = 0; i < e; i++) {//인접 리스트 생성기
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout << bfs();
}

int bfs() {
	int count = 0;//결과값출력할것임
	queue<int> q;//큐 선언
	q.push(1);
	vis[1] = true;//초기값 집어넣기

	while (!q.empty()) {//bfs
		int cur = q.front();
		q.pop();
		//cout << cur << ' '; 디버깅용
		for (auto nxt : adj[cur]) {
			if (vis[nxt]==true) 
				continue;
			q.push(nxt);//1이 아니라면 nxt 푸쉬하고
			vis[nxt] = true;//방문표시남김
			count++;
		}
	}

	return count;
}
