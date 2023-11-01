#include <iostream>
#include <queue>
#include <string>
using namespace std;
int dist[100002];			// 출발점에서 거리
int n, k;

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	fill(dist, dist + 100001, -1);	// 방문 안하면 dist가 -1
	dist[n] = 0;
	queue<int> Q;
	Q.push(n);

	while (dist[k] == -1) {
		int cur = Q.front(); Q.pop();
		for (int nxt : {cur - 1, cur + 1, cur * 2}) {
			if (nxt < 0 || nxt>100000)	continue;	// 범위 밖 금지
			if (dist[nxt] != -1)	continue;		// 방문 했으면 패스
			dist[nxt] = dist[cur] + 1;
			Q.push(nxt);
		}
	}

	cout << dist[k];
}
