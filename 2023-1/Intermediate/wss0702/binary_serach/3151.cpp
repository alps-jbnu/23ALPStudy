#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
//합이 0
//lower_bound와 right_bound를이용
using namespace std;

int N;
int arr[10002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	long long answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			auto right = upper_bound(arr + j + 1, arr + N, -arr[i] - arr[j]);
			auto left = lower_bound(arr + j + 1, arr + N, -arr[i] - arr[j]);
			answer += right - left;
		}
	}
	cout << answer;
	
}
