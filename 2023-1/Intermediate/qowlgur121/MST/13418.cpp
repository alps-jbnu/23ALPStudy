//정렬을 다르게 접근해서 풀었는데 틀렸다. 어디서 틀린지 알고 싶다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int parent[100005];

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
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	vector<pair<pair<int, int>,int >> v;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(make_pair(make_pair(a, b), c));	//(출발점, 도착점), c
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;	//자기 자신으로 저장
	}
	sort(v.begin(), v.end());	//오르막부터 내리막으로 정렬됨
	int num=1;
	for (int i = 0; i < m; i++) {
		if (!findParent(v[i].first.first, v[i].first.second)) {
			if (v[i].second == 0) {
				num++;
			}
			unionParent(v[i].first.first, v[i].first.second);
		}
	}
	int max = num * num;
	std::cout << max;
	num = 1;
	sort(v.begin(), v.end(),greater<>());	//내리막부터 오르막으로 정렬됨
	for (int i = 0; i < m; i++) {
		if (!findParent(v[i].first.first, v[i].first.second)) {
			if (v[i].second == 0) {    //오르막
				num++;
			}
			unionParent(v[i].first.first, v[i].first.second);
		}
	}
	int min = num * num;


	std::cout << max - min;

	return 0;
}
