#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int map[301][301];
int done[301][301];
bool vis[301][301];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
int s = 1;

int melt(int y,int x) {
    int cnt = 0;
    for (int i = 0;i < 4;i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (done[ny][nx] == 0) {
            cnt++;
        }
    }
    return cnt;
}

void bfs(int y,int x) {
    queue <pair<int, int>> q;
    vis[y][x] = true;
    q.push(make_pair(y, x));
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        vis[y][x] = true;
        q.pop();
        int d = melt(y, x);
        map[y][x] = map[y][x] - d;
        if (map[y][x] < 0) {
            map[y][x] = 0;
        }
        for (int i = 0;i < 4;i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
                continue;
            }

            if (done[ny][nx] == 0 || vis[ny][nx] == true) {
                continue;
            }
            vis[ny][nx] = true;
            q.push(make_pair(ny, nx));
        }
    }
}

int main() {
    int a = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    while (1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                done[i][j] = map[i][j];
            }
        }
        int b = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] != 0 && vis[i][j]==false) {
                    bfs(i, j);
                    b++;
                    //cout << b << " ";
                }
            }
        }
        if (b >= 2) {
            cout << a;
            break;
        }
        if (b == 0) {
            cout << 0;
            break;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i][j] = 0;
                //cout << map[i][j] << " ";
            }
            //cout << "\n";
        }

        a++;
    }

}
