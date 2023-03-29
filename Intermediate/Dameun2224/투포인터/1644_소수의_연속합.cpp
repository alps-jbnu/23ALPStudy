#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <limits.h>
using namespace std;

int arr[4000005];
vector<int> v;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	// 소수 vector에 넣기
	arr[1] = 1;
	for (int i = 2; i <= 4000005; i++) {
		if (!arr[i]) {
			for (int j = i * 2; j <= 4000005; j += i) arr[j] = 1;
		}
	}
	
	for (int i = 2; i <= 4000005; i++) {
		if (!arr[i]) v.push_back(i);
	}
		
	// 투 포인터
	int st = 0, en = 0, tot = 0, ans = 0;
	for (st = 0; st < v.size(); st++) {
		while (tot < n && en < v.size()) {
			tot += v[en];
			en++;
		}
		if (tot == n) ans++;
		 tot -= v[st];
	}

	cout << ans << '\n';

	return 0;
}
