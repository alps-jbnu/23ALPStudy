#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <list>
#include <tuple>
#include <stdlib.h>
using namespace std;

#define X first
#define Y second

// https://cocoon1787.tistory.com/315

int N, ans, h[100002];
stack<int> s;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) cin >> h[i];

	s.push(0); // 오류 방지
	for (int i = 1; i <= N + 1; i++) {
		while (!s.empty() && h[s.top()] > h[i]) {
			int check = s.top(); s.pop();
			ans = max(ans, h[check] * (i - s.top() - 1));
		}
		s.push(i);
	}

	cout << ans << '\n';

    return 0;
}
