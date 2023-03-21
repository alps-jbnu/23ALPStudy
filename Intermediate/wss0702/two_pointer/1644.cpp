#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
//겹치는 원소의 개수는 cnt배열로 관리
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	vector <bool> check;
	vector<int>prime;
	check.resize(N + 1, true);
	for (int i = 2; i * i <= N; i++) {
		if (check[i] == true) {
			for (int j = i + i; j <= N; j += i)
				check[j] = false;
		}
	}//소수구하기
	for (int i = 2; i < N + 1; i++) {
		if (check[i] == true)
			prime.push_back(i);
	}

	int st = 0;
	int en = 0;
	int cnt = 0;
	int sum = 0;
	while (1) {
		if (sum > N) sum -= prime[st++];
		else if (en == prime.size()) break;
		else sum += prime[en++];
		if (sum == N) cnt++;
	}
	cout << cnt;
}
