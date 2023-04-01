#include <bits/stdc++.h>
using namespace std;
int arr[500001];

int main(void)
{
	int n = 0;
	cin >> n;
	int cnt = 1;
	stack<pair<int, int>> s;
	int loop = 0;
	int t = 0;
	int idx = 1;

	while (cnt<=n) {
		if (idx == 1) {
			cin >> t;
			idx = 0;
		}
		if (s.empty() == true) {
			s.push({ cnt,t });
			arr[cnt] = 0;
			cnt++;
			idx = 1;
		}
		else if (t > s.top().second) {
			s.pop();
			idx = 0;
		}
		else if (t < s.top().second) {
			arr[cnt] = s.top().first;
			s.push({ cnt,t });
			cnt++;
			idx = 1;
		}
		loop++;
		//cout << "loop: " << loop << " ," << "n: " << n << " ," << "cnt: " << cnt << " ," << "t: " << t << '\n';
	}
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << ' ';
	}
}
