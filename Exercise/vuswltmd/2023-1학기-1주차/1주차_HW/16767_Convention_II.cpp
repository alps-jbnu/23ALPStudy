#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int N;
int a[100005];
int s[100005];         
priority_queue< pair<int, int> , vector<pair<int, int>>, greater<>> cow_data;
priority_queue<int, vector<int>, greater<>> pq;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> a[i] >> s[i];
		cow_data.push({ a[i], i });
	}

	long long _time = 0;
	long long eat_time = 0;
	long long eat_start_time = 0;
	long long max_time = 0;

	while (!cow_data.empty() || !pq.empty()) {
		_time += 1;

		while (!cow_data.empty()) {
			auto cur = cow_data.top();
			if (cur.first > _time) break;
			pq.push(cur.second);
			cow_data.pop();
		}

		if (!pq.empty() && eat_time + eat_start_time <= _time) {
			
			int cur = pq.top(); pq.pop();
			eat_start_time = _time;
			eat_time = s[cur];
			max_time = max(max_time, _time - a[cur]);
		}
	}

	cout << max_time;
	return 0;
}

//https://github.com/vuswltmd/23ALPStudy/blob/main/Exercise/elecbot0/1week/16767.cpp 참고했습니다..ㅠㅠ
