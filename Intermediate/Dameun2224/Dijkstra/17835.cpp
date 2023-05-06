#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

/*
* 예를 들어
* 면접장 1 -> 4,8
* 면접장 2 -> 2,9
* 면접장 3 -> 4,10
* 인 경우 최종 최댓값은 2,9이므로 각각의 최솟값도 저장해야함
* 그리고 모든 점에서 면접장까지의 최솟값들 중 최댓값이 최종 정답
*/

/*
* 시간초과가 나서, 바킹독 코드 참고함
* d[i]를 그냥 바로 답을 내는 보드로 사용
* pq에 면접장을 그대로 넣어도 d[i]가 덮어씌워지며 바로 최솟값을 구해줌
*/

#define X first
#define Y second

// 총 v*n번
int v, e, n;
// {비용, 정점 번호}
vector<pair<long long int, int>> adj[100005];
const long long int INF = 0x7f7f7f7f7f7f;
long long int d[100005];	// 최단경로 저장

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e >> n;
	fill(d + 1, d + v + 2, INF);
	priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
	
	while (e--) {
		int u, v;
		long long int w;
		cin >> u >> v >> w;
		adj[v].push_back({ w,u });
	}
	while (n--) {
		int a;
		cin >> a;
		d[a] = 0;
		pq.push({ d[a], a });
	}

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.Y] != cur.X) continue;
		// 현재 보는 점과 연결된 점들의 값 모두 확인 (간선들)
		for (auto nxt : adj[cur.Y]) {
			if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({ d[nxt.Y], nxt.Y });
		}
	}

	int idx = 0;
	long long int ans = 0;
	for (int i = v; i >= 1; i--) {
		if (d[i] >= ans) {
			ans = d[i];
			idx = i;
		}
	}

	cout << idx << '\n' << ans << '\n';

	return 0;
}
