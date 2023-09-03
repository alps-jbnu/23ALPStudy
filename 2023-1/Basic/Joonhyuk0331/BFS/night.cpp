#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[301][301];
int dist[301][301];
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 0;
    cin >> t;
    
    for (int i = 0; i < t; i++) 
    {
        queue<pair<int, int> > Q;
        int n = 0;
        cin >> n;
        int start_x, start_y, goal_x, goal_y;
        cin >> start_x >> start_y >> goal_x >> goal_y;

        board[goal_x][goal_y] = 2;
        Q.push({ start_x,start_y });
        dist[start_x][start_y] = 0;

        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            for (int dir = 0; dir < 8; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (board[nx][ny] == 2) {
                    cout << dist[cur.X][cur.Y] + 1<<'\n';
                    while (!Q.empty()) {
                        Q.pop();
                    }
                    break;
                }
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                    cout << "1111" << '\n';
                    continue;
                }
                if (dist[nx][ny] >= 0 || board[nx][ny] != 0) {
                    cout << "2222" << '\n';
                    continue;
                }
                cout << "3333" << '\n';
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({ nx,ny });
            }
        }
        memset(board, 0, sizeof(board));
        memset(dist, -1, sizeof(dist));
    }

}
