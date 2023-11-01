#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
int board[500][500];
int dp[500][500];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

int dfs(int x, int y) {
    if (x == n - 1 && y == m - 1) return 1;
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
            if (board[nx][ny] < board[x][y]) {
                dp[x][y] = dp[x][y] + dfs(nx, ny);
            }
        }
    }

    return dp[x][y];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            dp[i][j] = -1;
        }
    }
    
    int ans = dfs(0, 0);
    cout << ans;

    return 0;
}
