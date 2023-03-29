#include <bits/stdc++.h>
using namespace std;

int m; //우주의 개수
int n;	//행성의 개수 1~n
int universe[102][10002];

void compress(int a[]) {
	vector<int> v(a, a + n);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
	}
}

bool compare(int a[], int b[]) {
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> universe[i][j];
		}
		compress(universe[i]);
	}

	int cnt = 0;
	for (int i = 0; i < m - 1; i++) {
		for (int j = i + 1; j < m; j++) {
			cnt += compare(universe[i], universe[j]);
		}
	}

	cout << cnt;

	return 0;
}