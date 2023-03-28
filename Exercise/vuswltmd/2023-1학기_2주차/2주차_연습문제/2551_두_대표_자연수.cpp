#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int number[10005];
int N;
int ans1;
int ans2;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		number[num]++;
	}
	long long sum1 = 100'000'000'000'000;
	long long sum2 = 100'000'000'000'000;
	

	for (int i = 1; i < 10005; i++) {
		// 대표자연수의 범위가 1 ~ 10000 사이에 있을 것이므로 하나씩 다 검사를 해본다
		long long sum = 0;

		for (int j = 1; j < 10005; j++) {
			sum += (long long)number[j] * abs(i - j);
		}
		if (sum < sum1) {
			sum1 = sum;
			ans1 = i;
		}
	}
	

	for (int i = 1; i < 10005; i++) {
		long long sum = 0;

		for (int j = 1; j < 10005; j++) {
			sum += (long long)number[j] * (abs(i - j) * abs(i - j));
		}
		if (sum < sum2) {
			sum2 = sum;
			ans2 = i;
		}
	}

	cout << ans1 << ' ' << ans2;
}

