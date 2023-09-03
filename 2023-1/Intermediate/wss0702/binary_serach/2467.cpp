#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
//용액
//abs 절댓값
using namespace std;

int N;
int arr[100006];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N ;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int ans1 = 1000000001;
	int ans2 = 1000000001;
	
	for (int i = 0; i < N; i++) {
		int idx = lower_bound(arr, arr + N, -arr[i]) - arr; // lower_bound를 해도 idx값 +- 의 값까지 다 비교해 봐야함.
		if (idx + 1 < N && i != idx + 1 && abs(ans1 + ans2) > abs(arr[i] + arr[idx + 1])) {
			ans1 = arr[i];
			ans2 = arr[idx + 1];
			
		}
		if (idx < N && i != idx && abs(ans1 + ans2) > abs(arr[i] + arr[idx])) {
			ans1 = arr[i];
			ans2 = arr[idx];
			
		}
		if (idx != 0 && i != idx - 1 && abs(ans1 + ans2) > abs(arr[i] + arr[idx - 1])) {
			ans1 = arr[i];
			ans2 = arr[idx - 1];
			
		}
		
	}
	if (ans1 > ans2) swap(ans1, ans2);
	cout << ans1 << " " << ans2;
}
