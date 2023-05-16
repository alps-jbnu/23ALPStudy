#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stdlib.h>
#include<tuple>
#include<array>

using namespace std;
const long long INF = 0x3f3f3f3f;
int v, e, st, en;
int d[101][101];
int b[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

priority_queue< tuple<int, int, int>,vector<tuple<int, int, int>>,greater<tuple<int, int, int>> > pq;
int di() {
	d[1][1] = 0;
	pq.push({ 0,1,1 });
	while (!pq.empty()) {
		int cost, x, y;
		tie(cost,x,y) = pq.top();  pq.pop();
		if (d[x][y] != cost) continue;
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx > e || nx < 1)continue;
			if (ny > v || ny < 1)continue;
			int nxt_cost = cost + b[nx][ny];
			if (nxt_cost < d[nx][ny]) {
				d[nx][ny] = nxt_cost;
				pq.push({ nxt_cost,nx,ny });
			}
		}

	}
	return d[e][v];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> v >> e;
	for (int i = 1; i <= e; i++) {
		fill(d[i], d[i] + v + 1, INF);
	}
	for (int i = 1; i <= e; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= v; j++) b[i][j] = str[j - 1] - '0';
	}
	cout << di();
	
}
