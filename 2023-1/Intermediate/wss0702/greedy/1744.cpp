#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
//배열 정렬하고 뒤에서 부터 큰 거부터 묶기
// 0은 음수 처리
//음수에서 큰 수끼리 곱하기

using namespace std;
int N;
vector<int> arr_plus;
vector<int> arr_mius;
long long ans;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num == 1) ans++;//1은 묶지않고 그대로 더하는게 큰 이득
		else if (num <= 0) arr_mius.push_back(num);
		else arr_plus.push_back(num);
	}
	sort(arr_plus .begin(), arr_plus.end());
	sort(arr_mius.begin(), arr_mius.end(), greater<>());//내림차순
	int i = arr_plus.size() - 1;
	while (i > 0) {
		ans += arr_plus[i] * arr_plus[i - 1];
		arr_plus.pop_back();
		arr_plus.pop_back();
		i -= 2;
	}
	if (i == 0) ans += arr_plus[0];
	int j = arr_mius.size() - 1;
	while (j > 0) {
		ans += arr_mius[j] * arr_mius[j - 1];
		arr_mius.pop_back();
		arr_mius.pop_back();
		j -= 2;
	}
	if (j == 0) ans += arr_mius[0];

	cout << ans;
	return 0;
}
