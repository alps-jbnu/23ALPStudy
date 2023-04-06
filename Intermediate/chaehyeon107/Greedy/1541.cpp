#include <bits/stdc++.h>
using namespace std;

string s;
int tmp, ans;
int sign = 1;

int main(void) {
	cin >> s;
	for (char c : s) {
		if (c == '-' || c == '+') {
			ans += tmp * sign;
			if (c == '-') sign = -1;
			tmp = 0;
		}
		else {
			tmp *= 10;
			tmp += c - '0';
		}
	}
	ans += tmp * sign;
	cout << ans;
}
