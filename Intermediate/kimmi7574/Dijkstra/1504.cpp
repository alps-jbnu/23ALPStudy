#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<pair<int, int>> v[802];
int dst[802];

void func(int a) {
	memset(dst, 98765432, sizeof(dst));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, a));	//거리, 정점
	dst[a] = 0;

	while (!pq.empty()) {
		int dst_sum = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (dst[x] < dst_sum)
			continue;
		for (int i = 0; i < v[x].size(); i++) {
			int next_x = v[x][i].first;
			int next_dst = dst_sum + v[x][i].second;

			if (dst[next_x] > next_dst) {
				pq.push({ next_dst, next_x });
				dst[next_x] = next_dst;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;  //a <--c--> b
	int result = 0;
	int v1, v2; //반드시 거쳐야하는 정점

	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	cin >> v1 >> v2;

	//1~v1 + v1~n최단거리 vs. 1~v2 + v2~n최단거리 -> 더 짧은거로 선택
	func(1);
	int one_to_v1 = dst[v1];
	int one_to_v2 = dst[v2];

	func(v1);
	int v1_to_v2 = dst[v2];	//양방향이므로
	int v1_to_n = dst[n];

	func(v2);
	int v2_to_n = dst[n];

	result = min(98765432, one_to_v1 + v1_to_v2 + v2_to_n);
	result = min(result, one_to_v2 + v1_to_v2 + v1_to_n);

	if (result >= 98765432)
		cout << -1;
	else
		cout << result;
	return 0;
}