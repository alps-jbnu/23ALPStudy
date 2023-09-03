#include<bits/stdc++.h>
using namespace std;


int n;
int arr[50005];
int dp[4][50001];
int g;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		cin >> tmp;
		arr[i] = arr[i - 1] + tmp;
	}
	cin >> g;
	for (int i = 1; i <= 3; i++) {
		for (int j = i * g; j <= n; j++) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - g] + arr[j] - arr[j - g]);
		}
	}
	cout << dp[3][n];

 }