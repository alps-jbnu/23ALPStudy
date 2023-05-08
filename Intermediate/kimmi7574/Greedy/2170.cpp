#include <bits/stdc++.h>
using namespace std;

int n;	//선을 그은 횟수
pair<int, int> line[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> line[i].first >> line[i].second;
	}

	sort(line, line + n);

	int total = 0;
	int start = line[0].first;
	int end = line[0].second;

	for (int i = 1; i < n; i++) {
		int cur_s = line[i].first;
		int cur_e = line[i].second;

		if (end >= cur_s) { //총 끝점이 현재 시작점보다 크거나 같고,
			if (end < cur_e)//총 끝점이 현재 끝점보다 작으면
				end = cur_e;//현재 끝점을 총 끝점으로 함.
		}
		else {	//이전 총 길이 끝, 새로운 길이 시작
			total += end - start;
			start = cur_s;	//현재 시작점을 새로운 시작점(총 시작점의 새출발)
			end = cur_e;	//현재 끝점을 새로운 끝점(총 끝점의 새출발)
		}
	}

	total += end - start;	//마지막 남은 선의 길이 더함
	cout << total << "\n";
}