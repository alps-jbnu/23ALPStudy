#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int dp[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str1;
	string str2;
	cin >> str1 >> str2;

	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j - 1]);
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	cout << dp[str1.size()][str2.size()];
}
