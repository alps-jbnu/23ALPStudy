#include <bits/stdc++.h>
using namespace std;

int cost[1002][1002];
int parent[1002];
vector<tuple<int, int, int>> vec;	//비용,출발지,도착지

//해당 노드의 루트(최종 부모)찾기
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

//union: 두 노드를 합침(부모를 같게함)
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> cost[i][j];
		}
	}

	for (int i = 0; i <= n; i++) {
		parent[i] = i;	//초기 부모는 자기 자신
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			vec.push_back({ cost[i][j], i, j });
		}
	}

	sort(vec.begin(), vec.end());	//cost순으로 오름차순 정렬
	long long result = 0;

	for (int i = 0; i < vec.size(); i++) {
		if (find(get<1>(vec[i])) == find(get<2>(vec[i])))
			continue;	//사이클 발생 -> 패스
		result += get<0>(vec[i]);	//비용 더함
		merge(get<1>(vec[i]), get<2>(vec[i]));	//두 노드 합침
	}
	cout << result;
	return 0;
}