#include <iostream>
using namespace std;

int map[2200][2200];
int n;
int ans1, ans2, ans3;

// key == -1 혹은 0 혹은 1, m은 3^k, x, y는 시작점
void func(int m, int x, int y) {
	int key = map[x][y];
	for (int i = x; i < x+m; i++) {
		for (int j = y; j < y+m; j++) {
			if (map[i][j] != key) {
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 3; l++) {
						int mm = m / 3;
						func(m / 3, x + k * mm, y + l * mm);
					}
				}
				return;
			}
		}
	}
	if (key == -1) ans1++;
	if (key == 0) ans2++;
	if (key == 1) ans3++;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	func(n, 1, 1);

	cout << ans1 << '\n';
	cout << ans2 << '\n';
	cout << ans3 << '\n';

	return 0;
}
