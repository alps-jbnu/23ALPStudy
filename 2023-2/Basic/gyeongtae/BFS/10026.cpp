#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
char map[500][500] = { 0, };
bool vis[500][500] = { false };
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
queue <pair<int, int>> q;
int s = 0;
int f = 0;

void BFS(int y, int x) {
    vis[y][x] = true;
    q.push(make_pair(y, x));
    char cur = map[y][x];
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        //cout << x << " " << y << "\n";
        q.pop();
        for (int i = 0;i < 4;i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
                continue;
            }

            if (map[ny][nx] == cur && !vis[ny][nx]) {
                vis[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }
}


int main() {
    cin >> n ;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            map[i][j] = row[j] ;
        }
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (!vis[i][j]){
                BFS(i,j);
                s++;
            }
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (map[i][j] == 'G') {
                map[i][j] = 'R';
            }
        }
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            vis[i][j] = 0;
        }
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (!vis[i][j]) {
                BFS(i, j);
                f++;
            }
        }
    }
    cout << s << " " << f;
    return 0;
}
