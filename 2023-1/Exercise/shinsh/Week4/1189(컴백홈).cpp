#include<bits/stdc++.h>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

char board[10][10];
bool visited[10][10];
int r, c, k, result;

void dfs(int xx, int yy, int dist) {
    for (int dir = 0; dir < 4; dir++) {
        if ((dist == k) && (xx == 0) && (yy == c - 1)) {
            result++;
            return;
        }

        int nx = xx + dx[dir];
        int ny = yy + dy[dir];

        if (nx >= r || nx < 0 || ny >= c || ny < 0)
            continue;
        if (visited[nx][ny])
            continue;
        if (board[nx][ny] == 'T')
            continue;

        visited[nx][ny] = true;
        
        dfs(nx, ny, dist+1);

        visited[nx][ny] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> k;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }

    visited[r - 1][0] = true;
    dfs(r - 1, 0, 1);

    cout << result;
}