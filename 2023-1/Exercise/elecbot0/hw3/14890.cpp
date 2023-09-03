#include <bits/stdc++.h>

using namespace std;

int N, L, cnt;
int board[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> L;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    for (int i = 0; i < N; i++) {
        int len = 0;
        int prev = board[i][0];
        bool check = false;
        for (int j = 0; j < N; j++) {
            if (abs(prev - board[i][j]) > 1) break;
            if (prev > board[i][j]) {
                if (check && len < L) break;
                check = true;
                len = 1;
                prev = board[i][j];
            } else if (prev < board[i][j]) {
                if (check && len < 2 * L) break;
                if (len < L) break;
                check = false;
                len = 1;
                prev = board[i][j];
            } else {
                len += 1;
            }
            if (j == N - 1) {
                if (check && len < L) break;
                cnt += 1;
            }
        }
        len = 0;
        prev = board[0][i];
        check = false;
        for (int j = 0; j < N; j++) {
            if (abs(prev - board[j][i]) > 1) break;
            if (prev > board[j][i]) {
                if (check && len < L) break;
                check = true;
                len = 1;
                prev = board[j][i];
            } else if (prev < board[j][i]) {
                if (check && len < 2 * L) break;
                if (len < L) break;
                check = false;
                len = 1;
                prev = board[j][i];
            } else {
                len += 1;
            }
            if (j == N - 1) {
                if (check && len < L) break;
                cnt += 1;
            }
        }
    }
    cout << cnt;
    return 0;
}
