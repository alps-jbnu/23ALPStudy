#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MAX 52
int board[MAX][MAX];
bool vis[MAX][MAX];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int start_x,int start_y)//받는 좌표값으로 부터 bfs를 돌린다
{
    queue<pair<int, int> > q;
    q.push({ start_x,start_y });
    while (!q.empty()) {
        pair<int, int> cur = q.front();//현재값
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
                continue;
            if (vis[nx][ny] == 1 || board[nx][ny] == 0) //방문했거나 갈 수 없는 구역이면
                continue;
            vis[nx][ny] = 1;
            q.push({ nx,ny });
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 0, k = 0;
    cin >> t;//테스트 케이스 입력

    while (t--)//테스트케이스의 수 만큼 반복
    {
        cin >> n >> m >> k;
        int result = 0;

        for (int i = 0; i < k; i++) {//배추심기
            int x = 0, y = 0;
            cin >> x >> y;
            board[x][y] = 1;
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] == 1 && vis[i][j] == 0) {//배추가 심어져 있고 방문하지 않았다면
                    bfs(i, j);
                    result++;
                }
            }
        }
        cout << result << '\n';
        memset(board, 0, sizeof(board));//중요 배열 하나를 재활용하는거니까 초기화 해줘
        memset(vis, 0, sizeof(vis));
    }
}
