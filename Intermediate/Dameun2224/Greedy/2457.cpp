#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n;
int a, b, c, e;
int m, d, cnt;
vector<pair<pair<int, int>, pair<int, int>>> v;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int k = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> e;
		if (a == 12 || (a > c || (a == c && b > e))) {	// 12월에 피는 꽃은 벡터에 넣지 않고 continue;
			k++;
			continue;
		}
		v.push_back({ {a, b}, {c, e} });
	}
	sort(v.begin(), v.end());
	n -= k;

	int i = 0;
	while (i < n) {	//첫번째 꽃 정하기
		// 피는 달이 3보다 크거나 3월 1일보다 큰 경우 종료
		if (v[i].first.first > 3 || (v[i].first.first == 3 && v[i].first.second > 1)) break;
		// 피는 달이 3월보다 작거나 같은 경우, 지는 날짜가 가장 늦은 꽃으로 정함
		if (v[i].first.first <= 3) {
			if (v[i].first.first == 3)
				if (v[i].first.second != 1) continue;
			m = max(v[i].second.first, m);
			if (m == v[i].second.first)
				d = v[i].second.second;
		}
		i++;
	}
	cnt++;
	// 첫번째 꽃을 정하지 못한 경우 0을 출력하고 종료
	if (m == 0) {
		cout << 0 << '\n';
		return 0;
	}

	i--;
	int index = i;
	while (i < n) {
		if (m == 12) break;	// 이번 꽃이 12월에 진다면 종료
		for (int j = i; j < n; j++) {
			// 다음 꽃의 피는 날이 현재 꽃의 지는 달 이후라면 종료
			if (v[j].first.first > v[i].second.first) break;
			// 다음 꽃의 피는 날이 현재 꽃의 지는 달과 같으면서 이후라면 종료
			if (v[j].first.first == v[i].second.first && v[j].first.second > v[i].second.second) break;
			if (v[j].first.first < v[i].second.first || (v[j].first.first == v[i].second.first && v[j].first.second <= v[i].second.second)) {
				m = max(m, v[j].second.first);
				if (m == v[j].second.first) {
					// 정렬되어 있기 때문에, 같은 달일 경우 j가 크면 날은 항상 크거나 같다
					d = v[j].second.second;
					index = j;
				}
			}
		}
		// for문에서 다음 꽃을 찾지 못하고 index가 i와 같다면 cnt = 0; break;
		if (index == i) {
			cnt = 0;
			break;
		}
		i = index;
		cnt++;
	}

	// 마지막 꽃의 지는 날이 11월 30일과 같거나 전이라면 cnt = 0;
	if (m < 11 || (m == 11 && d == 30)) cnt = 0;

	cout << cnt << '\n';


	return 0;
}
