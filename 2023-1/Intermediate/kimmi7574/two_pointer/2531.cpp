#include <bits/stdc++.h>
using namespace std;

int n, d, k, c;
int flag, coupon, max_sushi = 0;
int sushi[30002];
bool check[3001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		cin >> sushi[i];
	}

	for (int i = 0; i < n; i++) {
		flag = 0;	//중복된 스시 체크
		coupon = 1;	//쿠폰 스시가 있는지 확인
		for (int j = i; j < i + k; j++) {
			if (check[sushi[j%n]] == 1)
				flag++;	//이미 먹은 초밥일 경우 중복 수 표시
			else
				check[sushi[j%n]] = 1;	//처음 먹어보는 초밥일 경우 체크

			if (sushi[j%n] == c)	//쿠폰 스시 있을 시
				coupon = 0;
		}

		max_sushi = max(max_sushi, k - flag + coupon);
		memset(check, 0, sizeof(check));
	}

	cout << max_sushi;
	return 0;
}