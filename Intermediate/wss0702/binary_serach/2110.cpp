#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
//공유기 설치
//parametric search
// 개수가 C개이면서 인접한 공유기 사이의 거리가 최대인 것
// (최적화 문제) C개를 만들 수 있는 인접한 공유기 사이의 최대 거리
// (결정 문제) 공유기의 길이가 len 일 공유기의 개수는 C개인가?
using namespace std;

int N, C;
int arr[200002];

bool solve(int len/*인접한 공유기 사이의 최대 거리*/) {
	int count = 0;// 공유기의 개수 
	int cur = 0;// 
	while (cur != N) {
		cur = lower_bound(arr + cur, arr + N, arr[cur] + len) - arr;
		// lower_bound는 iterator값을 반환함 따라서, 배열의 첫번째 주소를 빼면 인덱스 값이 나옴
		//arr[cur]+len(거리)에 맞는 좌표가 없다면 lower_bound는 arr[cur]+len이 들어갔을 때 오름차순이 되는 곳의 주소를 반환한다. 마지막에 들어간다면 배열의 첫번째 주소값을 빼면 N이된다.  										
		count++;
	}

	return count >= C;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int start = 1;
	int mid;
	int en = 1000000000;
	while (start < en) {
		mid = (start + en + 1) / 2;
		if (solve(mid))
			start = mid;
		else en = mid - 1;
	}
	cout << start;

}
