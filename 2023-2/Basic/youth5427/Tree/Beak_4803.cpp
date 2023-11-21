/*
	Day: 2023.11.20
	참고 : tree
*/
#include <iostream>
#include <vector>
using namespace std;
const int MXN = 510;
vector<int> adj[MXN];
bool vis[MXN], isTree; // vis: 방문 여부 확인 isTree: 현재 그래프가 트리인지 확인
int cnt_tree; // cnt_tree: 트리의 갯수
void dfs(int cur, int pre) {	// cur: 최근 pre: 이전
	for (int nxt : adj[cur]) { // 현재 노드에서 연결된 노드들을 순회
		if (nxt == pre) // 이전 노드와 같으면 스킵
			continue;
		if (vis[nxt]) { // 이미 방문한 노드라면, 현재 그래프는 트리가 아님
			isTree = false;
			continue;
		}
		vis[nxt] = true; // 방문 표시
		dfs(nxt, cur); // 다음 노드로 이동
	}
}
int cnt = 1;	// cnt: 반복한 횟수
int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	while (true) {
		// [테스트 케이스]
		int n, m; // n: 정점의 갯수 m: 간선의 갯수
		cin >> n >> m;
		// 0 0 입력시 종료
    // 왜 or 연산은 안되냐....
		if (n == 0 && m == 0) break;

		// [변수 초기화]
		// 방문 배열 초기화
		fill(vis, vis + n + 1, 0);	
		// 인접 리스트 초기화
		for (int i = 1; i <= n; i++)
			adj[i].clear(); 
		// 트리 개수 초기화
		cnt_tree = 0;

		while (m--) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;	// 방문한 노드 패스
			vis[i] = true;	// 방문 초기화
			isTree = true;	// 트리 여부 초기화
			dfs(i, -1);		// (최근, 이전)
			if (isTree)
				cnt_tree += 1;
		}
		
		cout << "Case " << cnt << ": ";
		if (cnt_tree == 0) {
			cout << "No trees.\n";
		}
		else if (cnt_tree == 1) {
			cout << "There is one tree.\n";
		}
		else
		{
			cout << "A forest of " << cnt_tree << " trees.\n";
		}
		cnt++;
	}
}
