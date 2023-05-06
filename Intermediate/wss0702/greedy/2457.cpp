vector<pair<int, int>>flower;
int ans;

#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//날짜를 파싱하는 법을 몰랐음.
// *이전 꽃이 피는 시기< 피는 시기 < 이전 꽃이 지는 시기 < 지는 시기


int N;

vector<pair<int, int>>flower;
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		int start_month, start_day, end_month, end_day;
		cin >> start_month >> start_day >> end_month >> end_day;
		flower.push_back({ start_month * 100 + start_day,end_month * 100 + end_day });
	}
	int time = 301;
	while (time < 1201) {
		int next_time = time;
		for (int i = 0; i < N; i++) {
			if (flower[i].first <= time && flower[i].second > next_time) {
				next_time = flower[i].second;
			}
		}
		if (next_time == time) {
			cout << 0;
			return 0;
		}
		ans++;
		time = next_time;
	}
	cout << ans;
	
}
