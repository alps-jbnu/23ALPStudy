//2339 석판자르기 
#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;
int board[21][21];
int is_right_cutting_or_wrong_cutting(int row_left, int col_left, int row_right, int col_right) {
	int gem = 0;
	int impurities = 0;
	for (int i = row_left; i <= row_right; ++i) {
		for (int j = col_left; j <= col_right; ++j) {
			if (board[i][j] == 1) impurities++;
			else if (board[i][j] == 2) gem++;
		}
	}
	if (gem == 1 && impurities == 0) return true;
	if (gem < impurities) return 0;//보석보다 불순물이 더 많으면 결국엔 보석이 없는 빈곳이 생김
	if (gem > 0 && impurities == 0) return 0;
	return -1;
}
bool is_Blocked(int row_left, int col_left, int row_right, int col_right, int idx, bool grain) {
	if (grain/*가로*/) {
		for (int i = row_left; i <= row_right; ++i) {
			if (board[i][idx] == 2) return true;
		}
	}
	else {
		for (int i = col_left; i <= col_right; ++i) {
			if (board[idx][i] == 2) return true;
		}
	}
	return false;
}//경계선에 보석이 있으면 안됨
int divided(int row_left, int col_left, int row_right, int col_right, bool grain) {
	if (is_right_cutting_or_wrong_cutting(row_left, col_left, row_right, col_right) == 1) return 1;
	else if (is_right_cutting_or_wrong_cutting(row_left, col_left, row_right, col_right) == 0) return 0;
	int result = 0;
	for (int i = row_left; i <= row_right; ++i) {
		for (int j = col_left; j <= col_right; ++j) {
			if (board[i][j] == 1) {
				if (grain) {
					if (!is_Blocked(row_left, col_left, row_right, col_right, i, false))
						result += (divided(row_left, col_left, i - 1, col_right, false) * divided(i + 1, col_left, row_right, col_right, false));
				}
				else {
					if (!is_Blocked(row_left, col_left, row_right, col_left, j, true))
						result += (divided(row_left, col_left, row_right, j - 1, true) * divided(row_left, j + 1, row_right, col_right, true));
				}
			}
		}
	}
	return result;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}
	int ans = 0;
	ans = divided(0, 0, N, N, true) + divided(0, 0, N, N, false); //true 가로 먼저, false세로 먼저
	if (ans > 0) cout << ans;
	else cout << -1;
	return 0;
}
