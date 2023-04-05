#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
//정렬 안됨
//겹치는 숫자를 최대한 빼지 않고
//겹치지 않는 숫자들을 뺴는 쪽으로해야함.
//flag에 있는 숫자 중 겹치는 수 중 적은 수를 pop시키고 새로운 숫자를 꽃는다.

using namespace std;
int N, K;
int arr[105];
int use[102];//콘센트
int ans;
vector<int> flag;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
	}
	if (N >= K) {
		cout << 0;
		return 0;
	}
	int arr_index = 0;
	int c_index = 0;
	while (c_index < N) {
		if (find(use, use + N, arr[arr_index]) == use + N/*중복 체크*/) {
			use[c_index] = arr[arr_index];
			c_index++;
		}
		arr_index++;
	}
	//멀테탭에 가능한 모든 기기를 꽂음
	for (int i = N; i < K; i++) {
		int cur = arr[i];//사용한 물품
		if (find(use, use + N, cur) == use + N) {
			pair<int, int> e = {INT_MIN, INT_MIN};

			for (int j = 0; j < N; j++) {
				pair<int, int> c;
				int pos = find(arr + i, arr + K, use[j]) - arr;

				if (pos == K) c = { INT_MAX, j };
				else c = { pos, j };

				if (c.first > e.first) e = c;
			}
			use[e.second] = cur;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
