#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int P[1003];
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	
	sort(P, P + N);
	
	int sum = 0;
	int presum = 0;
	for (int i = 0; i < N; i++) {
		presum += P[i];
		sum += presum;
	}
	cout << sum;
}
