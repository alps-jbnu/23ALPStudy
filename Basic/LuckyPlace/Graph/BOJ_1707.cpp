#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> vertex[20001];
int color[20001] = { 0, };
int n, m;			// 정점의 개수와 간선의 개수

bool is_bipartite_graph()			// 이분 그래프 인지 판별하는 함수 true면 이분 그래프
{
	for (int cur = 1; cur <= n; cur++)		// 모든 node를 다 확인
	{
		for (auto next : vertex[cur])
		{
			if (color[next] % 2 == color[cur] % 2)		// 연결되어 있는 node들의 색이 같으면
				return false;										// false 리턴
			else 
				continue;
		}
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;		// 테스트 케이스의 개수
	cin >> k;
	queue<int> q;
	while (k--)
	{
		cin >> n >> m;
		int u, v;
		while (m--)			// 간선 정보 입력
		{
			cin >> u >> v;
			vertex[u].push_back(v);
			vertex[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)			// 모든 경우의 수에 대해 bfs 탐색
		{
			if (color[i] > 0)
				continue;
			q.push(i);				
			color[i] = 1;			// 홀과 짝으로 색 구별
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				for (auto next : vertex[cur])
				{
					if (color[next] > 0)
						continue;
					color[next] = color[cur] + 1;
					q.push(next);
				}
			}
		}
		if (is_bipartite_graph())
			cout << "YES";
		else
			cout << "NO";
		cout << endl;

		for (int i = 0; i <= n; i++)		// 마지막으로 vertex vector와 color 초기화
		{
			vertex[i].clear();
			color[i] = 0;
		}
	}
	return 0;
}