#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
//겹치는 원소의 개수는 cnt배열로 관리
using namespace std;

int K, N;

int arr[200005];
int cnt[100005]; // 겹치는 원소의 개수
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int st = 0;
	int en = 0;
	
	int ans = 0;
	for (st = 0; st < N; st++) {
		while (en != N && cnt[arr[en]] < K) {
			cnt[arr[en]]++;
			en++;
		}
		ans = max(ans, en - st);
		cnt[arr[st]]--;
	}
	cout << ans;
}
