#include<stdio.h>
#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int A[1001] = { 0 }; // 수열을 담을 배열 
	int dp[1001] = { 0 };
	for (int i = 0; i < N; i++)
		cin >> A[i];
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		int location = 0;
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i]) {
				if (location < dp[j]) location = dp[j]; //A[i]가 A[j]보다 크다면 A[j]의 수열의 길이를 받음.
			}
			dp[i] = location + 1; //location은 그전까지 받았던 수열의 길이. +1은 나를 포함한 dp[i]의 수열의 길이. 
		}
	}
	int max = 0;
	for (int i = 0; i < N; i++) if (max < dp[i]) max = dp[i];
	cout << max;
}

