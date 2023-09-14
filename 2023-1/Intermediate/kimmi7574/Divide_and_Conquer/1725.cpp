#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
stack<int> s;
int n, result = 0, w, h;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	s.push(0);
	for (int i = 1; i <= n + 1; i++) {
		while (arr[i] < arr[s.top()] && !s.empty()) {
			h = arr[s.top()];
			s.pop();
			w = i - s.top() - 1; //i-1이 지금 제일 높은 히스토그램
			result = max(result, h*w);
		}
		s.push(i);
	}

	cout << result << "\n";
}