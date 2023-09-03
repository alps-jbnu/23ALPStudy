#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
//과자 나눠주기
// 과자의 길이를 더해서 M개 만큼 겹치는 숫자 찾기
//parametric search
// (최적화 문제) M개를 만들 수 있는 과자의 최대 길이
// (결정 문제) 과자의 길이가 len 일 과자의 개수는 M개인가?
using namespace std;

int M, N;
long long arr[1000005];

bool solve(int len/*과자의 최대 길이*/) {
	
	long long cur = 0;// 과자의 개수
	for (int i = 0; i < N; i++) cur += arr[i] / len;
	return cur >= M;
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	int start = 0;
	int mid;
	int en = arr[N - 1];
	while (start < en) {
		mid = (start + en + 1) / 2;
		if (solve(mid))
			start = mid;
		else en = mid - 1;
	}

	cout << start;

}
