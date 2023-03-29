#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
//나무 자르기
// 잘린 나무의 길이를 더해서 M개 만큼 겹치는 숫자 찾기
//parametric search

using namespace std;

int M, N;
int arr[1000005];

bool solve(int len/*나무의 최대 길이*/) {
	
	long long cur = 0;// 가져가는 나무의 길이
	for (int i = 0; i < N; i++) { 
		if(arr[i] > len)
		cur += arr[i] - len; 
	}
	return cur >= M;
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
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
