#include <bits/stdc++.h>
using namespace std;

int n;	//집의 개수
int R[1005];	//빨강으로 칠하는 비용 배열
int G[1005];	//초록으로 칠하는 비용 배열
int B[1005];	//파랑으로 칠하는 비용 배열
int d[1005][3];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> R[i] >> G[i] >> B[i];
	}

	//초기값
	d[1][0] = R[1];
	d[1][1] = G[1];
	d[1][2] = B[1];

	for (int k = 2; k <= n; k++) {
		d[k][0] = min(d[k - 1][1], d[k - 1][2]) + R[k];
		d[k][1] = min(d[k - 1][0], d[k - 1][2]) + G[k];
		d[k][2] = min(d[k - 1][0], d[k - 1][1]) + B[k];
	}

	cout << min({ d[n][0], d[n][1], d[n][2] }) << '\n';
}