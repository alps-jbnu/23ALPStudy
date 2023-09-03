#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
//합이 0
//lower_bound와 right_bound를이용
using namespace std;

int N;
int A[4002];
int B[4002];
int C[4002];
int D[4002];
int A_add_B[16000005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A_add_B[cnt++] = A[i] + B[j];
		}
	}
	sort(A_add_B, A_add_B + N * N);
	long long answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			auto right = upper_bound(A_add_B, A_add_B + N * N, -C[i] - D[j]);
			auto left = lower_bound(A_add_B, A_add_B + N * N, -C[i] - D[j]);
			answer += right - left;
		}
	}
	cout << answer;
	
}
