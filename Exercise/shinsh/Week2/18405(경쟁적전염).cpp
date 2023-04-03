#include<bits/stdc++.h>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[205][205];
int second[205][205];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];

            if (board[i][j] != 0) {
                q.push({ i,j });
                second[i][j] = 0;
            }
            else
                second[i][j] = 20000;
        }
    }

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = a + dx[dir];
            int ny = b + dy[dir];

            if (nx < n && ny < n && nx >= 0 && ny >= 0) {
                if (second[nx][ny] >= second[a][b] + 1 && (board[nx][ny] > board[a][b] || board[nx][ny] == 0)) {
                    q.push({ nx,ny });
                    second[nx][ny] = second[a][b] + 1;
                    board[nx][ny] = board[a][b];
                }
            }
        }
    }

    int s, x, y;
    cin >> s >> x >> y;

    if (second[x - 1][y - 1] <= s)
        cout << board[x - 1][y - 1];
    else
        cout << 0;
}