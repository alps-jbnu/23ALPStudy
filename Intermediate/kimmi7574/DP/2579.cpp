#include <bits/stdc++.h>
using namespace std;

int n;	//계단의 개수
int score;	//계단에 쓰여 있는 점수
int s[300];	//계단에 쓰인 점수 배열
int d[300][300];	//계단 점수 합의 최댓값 배열

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}

	//초기값
	d[1][1] = s[1];
	d[1][2] = 0;
	d[2][1] = s[2];
	d[2][2] = s[1] + s[2];

	//d[i][j] : 현재가지 j개의 계단을 연속해서 밟고, 
	//			i번째 계단까지 올라섰을 때 접수 합의 최댓값
	for (int k = 3; k <= n; k++) {
		d[k][1] = max(d[k - 2][1], d[k - 2][2]) + s[k];
		d[k][2] = d[k - 1][1] + s[k];
	}

	cout << max(d[n][1], d[n][2]) << '\n';
}