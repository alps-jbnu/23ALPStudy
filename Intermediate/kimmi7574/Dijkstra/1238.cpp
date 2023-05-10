#include <bits/stdc++.h>
using namespace std;

int n, m, x, result;
int dst[1002];	//정점까지의 최단거리 기록
vector<pair<int, int>> v[1002];

void func(int a, int d) {
	memset(dst, 98765432, sizeof(dst));	//초기값 무한대 설정
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	//우선순위 큐(최소 거리가 루트로)
	pq.push({ 0, a }); //거리, 정점
	dst[a] = 0;
	
	while (!pq.empty()) {
		int cur_x = pq.top().second;	//현재 정점
		int cur_dst = pq.top().first;	//현재 정점까지 거리
		pq.pop();
		
		if (cur_x == d) {	//현재 정점에 도착했다면
			result = dst[cur_x];	//최단 거리 기록
			break;
		}

		for (int i = 0; i < v[cur_x].size(); i++) {
			//현재 정점과 이어진 다음 정점들
			int next_x = v[cur_x][i].first;	//다음 정점
			int next_dst = v[cur_x][i].second + cur_dst;  //다음 정점까지 거리 계산
			if (dst[next_x] > next_dst) {
				//다음 정점까지 거리와 기록된 정점까지 거리와 비교해
				dst[next_x] = next_dst;	//최단거리라면 기록
				pq.push({ next_dst, next_x });	//큐에 삽입
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ansA, ansB, totalAns = 0;
	int st, en, t;

	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		cin >> st >> en >> t;
		v[st].push_back({ en, t });
	}
	for (int i = 1; i <= n; i++) {
		func(i, x);	//가는 길 최단 거리
		ansA = result;
		func(x, i);	//오는 길 최단 거리
		ansB = result;
		if (totalAns < ansA + ansB)
			totalAns = ansA + ansB;	//합
	}

	cout << totalAns << "\n";
	return 0;
}