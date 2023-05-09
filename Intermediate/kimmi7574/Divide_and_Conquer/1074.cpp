#include <bits/stdc++.h>
using namespace std;

int n, r, c, cnt = 0;

void solve(int x, int y, int n) {
	if (r == x && c == y) {
		cout << cnt;
		return;
	}
	
	int div = n / 2;

	if (r >= x && r < x + n && c >= y && c < y + n) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				solve(x + div * i, y + div * j, div);
			}
		}
	}
	else {	//r, c가 현재 사분면에 존재 x-> 현재 사분면의 크기를 더해줌
		cnt += n * n;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> r >> c;	//r행 c열 i, j
	int size = int(pow(2, n));

	solve(0, 0, size);

	return 0;
}