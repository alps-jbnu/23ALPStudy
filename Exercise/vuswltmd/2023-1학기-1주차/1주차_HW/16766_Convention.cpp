#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int cow[100005];
int N, M, C;

bool solve(long long x) {
	int cnt = 1;
	int start = 0;
	for (int i = 1; i < N; i++) {

		if (i - start >= C || cow[i] - cow[start] >= x) {
			cnt++;
			start = i;
		}

	}
	return cnt > M;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> C;

	for (int i = 0; i < N; i++) {
		cin >> cow[i];
	}

	sort(cow, cow + N);

	long long st = 0;
	long long en = 0x7fffffff;

	while (st < en) {
		long long mid = (st + en + 1) / 2;
		if (solve(mid)) st = mid;
		else en = mid - 1;
	}

	cout << st;
}
