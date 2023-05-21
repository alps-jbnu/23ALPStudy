//최소 신장 트리를 구하고, 최소 신장 트리 내에 가장 유지비가 큰 간선을 제거
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int parent[100005];
int result;

int getParent(int num) {
	if (num == parent[num]) return num;
	return parent[num] = getParent(parent[num]);
}
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a != b) {
		parent[a] = b;
	}
}
bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	vector<pair<int, pair<int, int>>> v;

	for (int i = 0; i < m; i++) {
		int cost, a, b;
		cin >> a >> b >> cost;
		v.push_back(make_pair(cost, make_pair(a, b)));
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;	//자기 자신으로 저장
	}
	sort(v.begin(), v.end());

	int maxCost=0;
	for (int i = 0; i < m; i++) {
		if (!findParent(v[i].second.first, v[i].second.second)) {
			maxCost = max(maxCost, v[i].first);
			result += v[i].first;
			unionParent(v[i].second.first, v[i].second.second);
		}
	}
	std::cout << result - maxCost;

	return 0;
}
