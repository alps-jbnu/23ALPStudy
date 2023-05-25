#include <bits/stdc++.h>
using namespace std;

int dp[10003];
int n;
int period, cnt, prior, res;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> period >> cnt;
		if (cnt == 0){
			dp[i] = period;
			continue;
		}
        int num = 0;
		for (int j = 0; j < cnt; j++){
			cin >> prior;
			num = max(num, dp[prior]);
		}
		dp[i] = period + num;
	}

	for (int i = 1; i <= n; i++) res = max(res, dp[i]);
	cout << res << '\n';
}