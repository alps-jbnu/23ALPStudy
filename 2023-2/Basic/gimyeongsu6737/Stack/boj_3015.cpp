#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	stack<pair<int, int>> s;
	long long int ans = 0;
	while (n > 0) {
		n--;
		int h;
		cin >> h;
		int cnt = 1;

		while (!s.empty() && s.top().first <= h) {
			ans = ans + s.top().second;

			if (h == s.top().first) cnt = cnt + s.top().second;

		    s.pop();	
		}
		
		if (!s.empty()) ans++;

		s.push({ h, cnt });

	}
	cout << ans;

}