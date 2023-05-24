#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stdlib.h>
#include<tuple>
#include<vector>
#include<string.h>
#include<math.h>

#define X first
#define Y second
#define MAX 1002

using namespace std;
int V, E;
int p[MAX];
pair<int, int> board[MAX];
vector <tuple <long long, int, int>>e;
int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}//부모 그룹 찾기
bool is_diff_group(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)return 0;
	if (p[u] == p[v])p[v]--;
	if (p[u] < p[v])p[v] = u;
	else p[u] = v;
	return 1;
}//다른 그룹인지 확인 및 병합
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> V >> E;
	fill(p, p +V + 1,-1);
	int x, y;
	for (int i = 1; i <= V; i++) {
		cin >> x >> y;
		board[i] = { x,y };
	}
	int cnt = 0;
	for (int i = 0; i < E; i++) {
		cin >> x >> y;
		if (is_diff_group(x, y)) cnt++;
	}
	long long cost;
	for (int i = 1; i <= V; i++) {
		for (int j = i + 1; j <= V; j++) {
			int dx = (board[i].X - board[j].X);
			int dy = (board[i].Y - board[j].Y);
			cost = ((long long)dx) * dx + ((long long)dy) * dy;
			e.push_back({ cost, i, j });
		}
	}
	sort(e.begin(), e.end());
	double ans = 0;
	for (auto cur : e) {
		tie(cost, x, y) = cur;
		if (!is_diff_group(x, y))continue;
		ans += sqrt(cost);
		cnt++;
		if (cnt == V - 1) break;
	}
	cout << fixed;
	cout.precision(2);
	cout << ans;
}
