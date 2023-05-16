#include<iostream>
#include<vector>
using namespace std;
int board[2188][2188];
int N;
int ans[3];
bool check(int n, int x, int y) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++)
			if (board[i][j] != board[x][y])return false;
	}
	return true;
}
void func(int n, int x, int y) {
	if(check(n,x,y)) {
		ans[board[x][y] + 1]++;
		return;
	}
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++)
			func(n / 3, x + i * n / 3, y + j * n / 3);
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	func(N, 0, 0);
	for (int i = 0; i < 3; i++) cout << ans[i] << "\n";
}
