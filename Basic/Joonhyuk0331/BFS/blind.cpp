#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MAX 101
char board[MAX][MAX];
bool vis[MAX][MAX];
int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int start_x, int start_y,char c)//c에 R,G,B를
{
    queue<pair<int, int> > q;
    q.push({ start_x,start_y });
    while (!q.empty()) {
        pair<int, int> cur = q.front();//현재값
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (vis[nx][ny] == 1 || board[nx][ny] != c) //방문했거나 C가 아닐경우
                continue;
            vis[nx][ny] = 1;
            q.push({ nx,ny });
        }
    }
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // scanf, gets, getchar, printf, puts, putchar 사용불가
    cin >> n;
    int R_result = 0;
    int G_result = 0;
    int B_result = 0;

    int Blind_G_result = 0;
    int Blind_B_result = 0;

    for (int i = 0; i < n; i++) {//RGB심기
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            board[i][j] = str[j];
        }
    }
    //정상인
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'R' && vis[i][j] == 0) {//R이고 방문하지 않았다면
                bfs(i, j, 'R');
                R_result++;
            }
            if (board[i][j] == 'G' && vis[i][j] == 0) {//G이고 방문하지 않았다면
                bfs(i, j, 'G');
                G_result++;
            }
            if (board[i][j] == 'B' && vis[i][j] == 0) {//B이고 방문하지 않았다면
                bfs(i, j, 'B');
                B_result++;
            }
        }
    }
    
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {//RGB심기
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'R')//적=녹 이므로   R=>G로 바꾼다
                board[i][j] = 'G';
        }
    }
    
    //색맹
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            /*if (board[i][j] == 'R' && vis[i][j] == 0) {//R이고 방문하지 않았다면
                bfs(i, j, 'R');
                Blind_R_result++;
            }*///R=G처리 했으니까 안할거임
            if (board[i][j] == 'G' && vis[i][j] == 0) {//G이고 방문하지 않았다면
                bfs(i, j, 'G');
                Blind_G_result++;
            }
            if (board[i][j] == 'B' && vis[i][j] == 0) {//B이고 방문하지 않았다면
                bfs(i, j, 'B');
                Blind_B_result++;
            }
        }
    }

    cout << R_result + G_result + B_result<<" " << Blind_G_result + Blind_B_result;
}
