#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
long long M;
int arr[10002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int st = 0;
	int en = 0;
	int cnt = 0;
	int total = arr[0];
	for (st = 0; st < N; st++) {
		while (en < N && total < M) {
			en++;
			if(en != N) total += arr[en];
		}
		if (en == N) break;
		if (total == M) {
			cnt++;
		}
		total -= arr[st];
	}
	cout << cnt;
}
