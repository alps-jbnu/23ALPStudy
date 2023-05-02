#include<bits/stdc++.h>
using namespace std;

int dx[6] = { 2,1,-1,-2,-1,1 };
int dy[6] = { 0,2,2,0,-2,-2 };
int board[205][205];
bool visited[205][205];
int n;
queue<pair<int, int>> q;

void bfs(int xx,int yy) {
    board[xx][yy] = 0;
    visited[xx][yy] = true;

    q.push(make_pair(xx,yy));

    while (!q.empty()) {
        xx = q.front().first;
        yy = q.front().second;
        q.pop();

        for (int dir = 0; dir < 6; dir++) {
            int nx = xx + dy[dir];
            int ny = yy + dx[dir];

            if (ny < 0 || nx < 0 || ny > n || nx > n)
                continue;

            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                board[nx][ny] = board[xx][yy] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    bfs(r1,c1);

    if (board[r2][c2] == 0)
        cout << -1;
    else
        cout << board[r2][c2];
}