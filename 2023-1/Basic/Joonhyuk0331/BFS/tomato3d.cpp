#include <bits/stdc++.h>
using namespace std;
#define MAX 102
int board[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];
int n, m, h;

int dx[6] = { 0,0 ,1,-1,0,0 };
int dy[6] = { -1,1,0,0,0,0 };
int dz[6] = { 0,0,0 ,0,-1,1 };

typedef struct{//tuple? pair중첩? 헷갈려서 그냥 구조체 선언함
    int z;
    int x;
    int y;
}p;

queue<p> q;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;

    for (int i = 0; i < h; i++) {//토마토배치 0토마토 1익은토마토 -1빈칸
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) { //board[h][n][m] board[z][x][y]
                    q.push({ i,j,k });//시작점이 여러개일 때 해법:시작점을 큐에 미리 집어넣고 bfs돌린다
                }
                if (board[i][j][k] == 0) {
                    dist[i][j][k] = -1;//왜 -1,0,1중 0만 초기화? >> 1은 이미 큐에 넣었고 -1은 못가는곳이니까
                }
            }
        }
    }
    //bfs3d
    while (!q.empty()) {
        p cur;
        cur.x = q.front().x;
        cur.y = q.front().y;
        cur.z = q.front().z;
        q.pop();
        //cout << "pop!  " << "cur.z:" << cur.z << " cur.x:" << cur.x << " cur.y:" << cur.y << '\n';

        for (int dir = 0; dir < 6; dir++) {
            int nz = cur.z + dz[dir];
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
                continue;
            if (dist[nz][nx][ny]>=0) //dist가 -1아니면 컨티뉴
                continue;
            dist[nz][nx][ny] = dist[cur.z][cur.x][cur.y] + 1;
            q.push({ nz,nx,ny });
            //cout << "push!  " << "nz:" << nz << " nx:" << nx << " ny:" << ny << '\n';
        }
    }
    //bfs후 결과처리
    int result =0;
    for (int i = 0; i < h; i++) {//토마토배치 0토마토 1익은토마토 -1빈칸
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (dist[i][j][k] == -1) {//토마토가 모두 익었다면 dist-1있을 수 없음
                    cout << -1;
                    return 0;
                }
                result = max(result,dist[i][j][k]);
            }
        }
    }
    cout << result;
}
