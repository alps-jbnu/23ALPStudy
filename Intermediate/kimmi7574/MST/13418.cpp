#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> road;
int parent[1001];

int find(int x) {
	if (parent[x] == x) return x;
	else
		return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
}

bool compare(tuple<int, int, int>& a, tuple<int, int, int>& b) {
	return get<0>(a) > get<0>(b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, a, b, c;
	int up = 0, down = 0;

	cin >> n >> m;
	cin >> a >> b >> c;
	road.push_back({ c,a,b });	//비용, 출발지, 도착지

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		road.push_back({ c,a,b });	//c = 1(내리막길)/0(오르막길)
	}

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	//피로도 최소(오르막길 최소로 이용): 내리막길 우선 -> 오름차순 정렬
	sort(road.begin(), road.end());
	
	for (int i = 0; i < road.size(); i++) {
		if (find(get<1>(road[i])) != find(get<2>(road[i]))) {
			merge(get<1>(road[i]), get<2>(road[i]));

			if(!get<0>(road[i]))	//오르막길 사용횟수 count
				down++;
		}
	}

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	//피로도 최악(오르막길 최대로 이용): 오르막길 우선 -> 내림차순 정렬
	sort(road.begin(), road.end(), compare);

	for (int i = 0; i < road.size(); i++) {
		if (find(get<1>(road[i])) != find(get<2>(road[i]))) {
			merge(get<1>(road[i]), get<2>(road[i]));

			if (!get<0>(road[i]))	//오르막길 사용횟수 count
				up++;
		}
	}

	cout << (int)(pow(down, 2) - pow(up, 2)) << "\n";
	return 0;
}