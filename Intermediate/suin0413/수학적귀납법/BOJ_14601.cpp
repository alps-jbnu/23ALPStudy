#include <iostream>
using namespace std;

int arr[257][257];
int k, x, y, num = 0;

bool check(int sz, int x, int y) {
	for (int i = x; i < x + sz; i++) {
		for (int j = y; j < y + sz; j++) {
			if (arr[i][j] != 0) return false;
		}
	}
	return true;
}
void sol(int sz, int x, int y) { // 빈 구역 3개의 가운데를 칠한다
	num++;
	int s = sz / 2;
	if (check(s, x, y)) arr[x + s - 1][y + s - 1] = num;
	if (check(s, x, y + s)) arr[x + s - 1][y + s] = num;
	if (check(s, x + s, y)) arr[x + s][y + s - 1] = num;
	if (check(s, x + s, y + s)) arr[x + s][y + s] = num;
	if (sz == 2) return;
	sol(s, x, y);
	sol(s, x + s, y);
	sol(s, x, y + s);
	sol(s, x + s, y + s);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> x >> y;
    arr[y - 1][x - 1] = -1;
    sol((1 << k), 0, 0);
    for (int i = (1 << k)-1; i >= 0; i--) {
        for (int j = 0; j < (1 << k); j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
